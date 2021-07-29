#pragma once 

#include "Sock.hpp"
#include "Log.hpp"
#include "Until.hpp"

#define WEBROOT "wwwroot"
#define HOMEPAGE "index.html"
#define VERSION "HTTP/1.0"

static std::string CodeTODesc(int code)
{
  std::string desc;
  switch(code){
    case 200:
      desc = "OK";
      break;
    case 404:
      desc = "Not Found!";
      break;
    default:
      desc = "OK";
      break;
  }

  return desc;
}

static std::string SuffixToDesc(const std::string &suffix)
{
  if(suffix == ".html" || suffix == ".htm")
  {
    return "text/html";
  }
  else if(suffix == ".js")
  {
    return "application/x-javascript";
  }
  else if(suffix == ".css")
  {
    return "text/css";
  }
  else if(suffix == ".jpg")
  {
    return "image/jpeg";
  }
  else 
  {
    return "text/html";
  }
}

class HttpRequest{
  private:
    std::string request_line;
    std::vector<std::string> request_header;
    std::string blank;
    std::string request_body;
 private:
    std::string method;
    std::string uri;
    std::string version;
      
    
    std::string path; 
    std::string query_string;

    std::unordered_map<std::string, std::string> header_kv;

    ssize_t content_Length;
    bool cgi;

    ssize_t file_size;

    std::string suffix;
   public:
    HttpRequest():blank("\n"),content_Length(-1),path(WEBROOT),cgi(false),suffix("text/html")
    {}
        
    //写进请求行
    void SetRequestLine(const std::string &line)
    {
      request_line = line;
    }
    
    //插入请求报头
    void InsertHeaderLine(const std::string &line)
    {
      request_header.push_back(line);
      LOG(Notice, line);
    }

    //请求行解析
    void RequestLineParse()
    {
      Util::StringParse(request_line, method, uri, version);
      //LOG(Notice, request_line);
      //LOG(Notice, method);
      //LOG(Notice, uri);
      //LOG(Notice, version);
    }

    //请求报头解析
    void RequestHeaderParse()
    {
      for(auto& e : request_header)
      {
        std::string k,v;
        Util::MakeStringTOKV(e, k, v);
        header_kv.insert({k, v});
        if(k == "Content-Length")
        {
          content_Length = Util::StringTOInt(v);
        }
      } 
    }
    
    //是否需要读取正文
    bool IsNeedRecvBody()
    {
      //Post, poSt, POST
      if(strcasecmp(method.c_str(), "POST") == 0 && content_Length > 0)//忽略大小写比较
      {
        cgi = true;
        return true;
      }

      return false;
    }

    ssize_t GetContenLength()
    {
      return content_Length;
    }
    
    void SetRequestBody(const std::string &body)//这里是EndPoint的对象，要往请求里面放入
    {
      request_body = body;
    }
    
    bool ISMethodLegal()
    {
      if(strcasecmp(method.c_str(), "POST") == 0 || strcasecmp(method.c_str(), "GET") == 0)
      {
        return true;
      }

      return false;
    }

    bool IsGet()
    {
      return strcasecmp(method.c_str(), "GET") == 0 ? true : false;
    }
    
    bool IsPOST()
    {
      return strcasecmp(method.c_str(), "POST") == 0 ? true : false;
    }

    void UriParse()
    {
      //uri存在
      std::size_t pos = uri.find('?');
      if(pos == std::string::npos)
      {
        path += uri;
      }
      else 
      {
        path += uri.substr(0, pos);
        query_string = uri.substr(pos+1);
        cgi = true;
      }

    }

    void SetUriEqPath()
    {
      path += uri;
    }
    
    std::string GetPath()
    {
      return path;
    }

    std::string SetPath(std::string _path)
    {
      path = _path;
      return path;
    }

    void IsAddHomePage()
    {
      // path  /  or /a/b/c.html or /s 
      if(path[path.size()-1] == '/')
      {
        path += HOMEPAGE;
      }
    }
      
    void SetCgi()
    {
      cgi = true;
    }
    bool IsCgi()
    {
      return cgi;
    }
    void SetFileSize(ssize_t s)
    {
      file_size = s;
    }
    ssize_t GetFileSize()
    {
      return file_size;
    }
    std::string GetQueryString()
    {
      return query_string;
    }
    std::string GetBody()
    {
      return request_body;
    }
    std::string GetMethod()
    {
      return method;
    }
    std::string MakeSuffix()
    {
      std::size_t pos = path.rfind(".");
      if(std::string::npos != pos)
      {
        suffix = path.substr(pos);
      }

      return suffix;
    }

    ~HttpRequest()
    {}
};

class HttpResponse{
  private:
    std::string status_line;
    std::vector<std::string> response_header;
    std::string blank;
    std::string response_body;
  public:
    HttpResponse():blank("\r\n")
    {}

    void SetStatusLine(std::string &sline)
    {
      status_line = sline;
    }

    std::string GetStatusLine()
    {
      return status_line;
    }
    const std::vector<std::string>& GetRspHeader()
    {
      response_header.push_back(blank);
      return response_header;
    }

    void AddHeader(const std::string &ctype)
    {
      response_header.push_back(ctype);
    }
    ~HttpResponse()
    {}
};

class EndPoint{
  private:
    int sock;
    HttpRequest req;
    HttpResponse rsp;
  private:
    //获取请求行
    void GetRequestLine()
    {
      std::string line;
      Sock::GetLine(sock, line);//读取行
      req.SetRequestLine(line);// 
      req.RequestLineParse();
    }

    void SetResponseStatusLine(int code)
    {
      std::string status_line; 
      status_line = VERSION;
      status_line += " ";
      status_line += std::to_string(code);
      status_line += " ";
      status_line += CodeTODesc(code);
      status_line += "\r\n";

      rsp.SetStatusLine(status_line);
    }

    //获取报头
    void GetRequestHeader()
    {
      std::string line;
      do{
        line.clear();
        Sock::GetLine(sock, line);
        req.InsertHeaderLine(line);
      }while(!line.empty());

      req.RequestHeaderParse();
    }

    //获取正文
    void GetRequestBody()
    {
      ssize_t len =req.GetContenLength();//获取长度
      char c; 
      std::string body;
      while(len)
      {
        ssize_t s = recv(sock, &c, 1, 0);
        body.push_back(c);
        len--;
      }

      req.SetRequestBody(body);//这里是EndPoint的对象，要往请求里面放入
    }


    void SetResponseHeaderLine()
    {
      std::string suffix = req.MakeSuffix();
      std::string content_type = "Content-Type: ";
      content_type += SuffixToDesc(suffix);//后缀转换
      content_type += "\r\n";
      rsp.AddHeader(content_type);
    }

  public:
    EndPoint(int _sock):sock(_sock)
    {}
    
    //接收请求 
    void RecvRequest()
    {
      //获取完整http请求
      //分析http请求
      //1.读取并分析完第一行
      GetRequestLine();//请求行 
      
      //2. 读取报头 && blank
      GetRequestHeader();

      //是否需要读取正文 
      if(req.IsNeedRecvBody())
      {
        //yes
        GetRequestBody();
      }

      //已经读完所有请求
    }

    void MakeResponse()
    {    
      //开始分析
      //处理GET和POST 
      int code = 200;
      ssize_t FileSize = 0;//文件大小
      std::string path;
      if(!req.ISMethodLegal())
      {
        LOG(Warning, "method id not legal!");
        code = 404;
        goto end;
      }
      
      if(req.IsGet())
      {
        req.UriParse();
      }
      else 
      {
        //POST
        req.SetUriEqPath();
      }

      req.IsAddHomePage();
      //如下三种情况
      //get && 没有参数 -> path 
      //get && 有参数 -> path && query_string
      //POST -> uri -> path && body 
      
      path = req.GetPath();
      LOG(Notice, path);
      struct stat st;
      if(stat(path.c_str(), &st) < 0)
      {
        LOG(Warning, "Html is not exist! 404");
        code = 404;
        goto end;
      }
      else 
      {
        if(S_ISDIR(st.st_mode))//是目录
        {
          //  /a/b/c/index.html
          path += "/";
          req.SetPath(path);
          req.IsAddHomePage();
        }
        else //不是目录 
        {
          if((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP) || (st.st_mode & S_IXOTH))//可执行程序
          {
            //CGI
            req.SetCgi();
            
          }
          else  
          {
            //正常的网页请求
            //DO nothing1
          }
        }
        if(!req.IsCgi())
        {
          req.SetFileSize(st.st_size);
        }
      }

end:
      //制作response
      SetResponseStatusLine(code);
      req.MakeSuffix();//制作浏览器识别的后缀
      SetResponseHeaderLine();
      //TODO
    }
      
    void ExecNonCgi(const std::string &path)
    {
      int fd = open(path.c_str(), O_RDONLY);
      if(fd < 0)
      {
        LOG(Error, "path is not exists bug!");
        return;
      }
      ssize_t size = req.GetFileSize();
      sendfile(sock, fd, nullptr, size);//俩个文件描述符之间发数据
      close(fd);
    }
    void ExecCgi()
    {
      //std::string arg;
      //if(req.IsGet())
      //{
      //  arg = req.GetQueryString();
      //}
      //else 
      //{
      //  arg = req.GetBody();
      //}
      std::string content_length_env;
      std::string path = req.GetPath();

      std::string method = req.GetMethod();
      std::string method_env = "METHOD=";
      method_env += method;

      std::string query_string;
      std::string query_string_env;
      
      std::string body;

      int pipe_in[2] = {0};
      int pipe_out[2] = {0};
      //站在被调用进程的角度
      pipe(pipe_in);
      pipe(pipe_out);

      putenv((char*)method_env.c_str());
      pid_t id = fork();
      if(id == 0)
      { 
        //子进程
        close(pipe_in[1]); //通过in读
        close(pipe_out[0]);
        
        dup2(pipe_in[0], 0);//将标准输入写道管道里
        dup2(pipe_out[1], 1);
        //exec
        //一种通过环境变量传给子进程 -》GET -> query-string 
        if(req.IsGet())
        {
          query_string = req.GetQueryString();
          query_string_env = "QUERY_STRING=";
          query_string_env += query_string;
          putenv((char*)query_string_env.c_str());
        }
        else if(req.IsPOST())
        {
          content_length_env = "CONTENT-LENGTH=";
          content_length_env += std::to_string(req.GetContenLength());
          putenv((char*)content_length_env.c_str());
        }
        else 
        {
          //TODO
        }

        execl(path.c_str(), path.c_str(), nullptr);
        exit(0);//失败就终止
      }
      //父进程
      close(pipe_in[0]);
      close(pipe_out[1]);
      
      //第二种通过管道传递给子进程 -> POST -> body 
      char c = 'X';
      if(req.IsPOST())
      {
        body =req.GetBody();
        int i = 0;
        for(;i < body.size(); ++i)
        {
          write(pipe_in[1], &body[i], 1);
        }
      }
      
      //发送cgi执行结果
      ssize_t s = 0;
      do{
        s = read(pipe_out[0], &c, 1);
        if(s > 0)
        {
          send(sock, &c, 1, 0);
        }
      }while(s > 0);

      waitpid(id, nullptr, 0);
    
    }
    void SendResponse()
    {
      std::string line = rsp.GetStatusLine();
      send(sock, line.c_str(), line.size(), 0);
      const auto &header = rsp.GetRspHeader();
      auto it = header.begin(); 
      for(; it != header.end(); ++it)
      {
        send(sock, it->c_str(), it->size(), 0);
      }
      
      if(req.IsCgi())
      {
        //yes->cgi 
        LOG(Notice, "use cgi model");
        ExecCgi();
      }
      else 
      {
        LOG(Notice, "use non cgi model");
        std::string path = req.GetPath();
        ExecNonCgi(path);

      }
      
    }

    ~EndPoint()
    {
      if(sock >= 0)
      {
        close(sock);
      }
    }

};

class Entry{
  public:
    static void HandlerHttp(int sock)
    {
      //int sock = *(int *)arg;
      //delete (int*)arg;

#ifdef DEBUG 
      char request[10240];
      recv(sock, request, sizeof(request), 0);
      close(sock);

#else 
      //1.读取请求 2.分析请求 3.发生请求
      EndPoint *ep = new EndPoint(sock);
      ep->RecvRequest();
      ep->MakeResponse();
      ep->SendResponse();
      
      delete ep;
#endif  
                
    }
};
