#pragma once 

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/sendfile.h>
#include "Log.hpp"

#define BACKLOG 5

class Sock{
  public:
    static int Socket()
    {
      int sock = socket(AF_INET, SOCK_STREAM, 0);
      if(sock < 0)
      {
        LOG(Fatal, "socket create error");
        exit(SocketErr);
      }

      return sock;
    }

    static void Bind(int sock, int port)
    {
      struct sockaddr_in local;
      bzero(&local, sizeof(local));

      local.sin_family = AF_INET;
      local.sin_port = htons(port);
      local.sin_addr.s_addr = htonl(INADDR_ANY);

      if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
      {
        LOG(Fatal, "socket bind error");
        exit(BindErr);
      }
    }

    static void Listen(int sock)
    {
      if(listen(sock, BACKLOG) < 0)
      {
        LOG(Fatal, "socket listen error");
        exit(ListenErr);
      }
    }

    static void SetSockOpt(int sock)
    {
      int opt = 1;
      setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    }

    static int Accept(int sock)
    {
      struct sockaddr_in peer;
      socklen_t len = sizeof(peer);
      int s = accept(sock, (struct sockaddr*)&peer, &len);
      if(s < 0)
      {
        LOG(Warning, "accept error");
      }

      return s;
    }

    //作用：整体读取一行内容
    static void GetLine(int sock, std::string& line)
    {
      // \n, \r, \r\n
      //按字符读取
      char c = 'X';
      while(c != '\n')
      {
        ssize_t s = recv(sock, &c, 1, 0);
        if(s > 0)//读取正确
        {
          if(c == '\r')
          {
            ssize_t ss = recv(sock, &c, 1, MSG_PEEK);//MSG_PEEK:把数据从接收缓冲区读上来，但不拿走  
            if(ss > 0 && c == '\n')
            {
              //说明行分隔符是\r\n
              recv(sock, &c, 1, 0);//直接把\n拿上来
            }
            else 
            {
              //\r
              c = '\n';
            }
          
          }
          //1.读取到的是常规字符
          //2.读取的就是'\n'
          //3.\r,\r\n 转换成了\n
          if(c != '\n')
          {
            line.push_back(c);
          }
            
        }
      
      }
    }

};
