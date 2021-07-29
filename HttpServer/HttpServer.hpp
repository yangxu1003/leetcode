#pragma once 

#include <pthread.h>
#include "Sock.hpp"
#include "Protocol.hpp"
#include "ThreadPool.hpp"

#define PORT 8083

class HttpServer 
{
  private:
    int port;
    int lsock;
    ThreadPool *tp;
    static HttpServer *http_svr;
    static pthread_mutex_t lock;
  public:
    HttpServer(int _port=PORT)
      :port(_port),lsock(-1),tp(nullptr)
    {}
    
    static HttpServer *GetInstance(int sk)
    {
      if(nullptr == http_svr)//效率
      {
        pthread_mutex_lock(&lock);
        if(nullptr == http_svr)//安全
        {
          http_svr = new HttpServer(sk);
        }
        pthread_mutex_unlock(&lock);
      }  

      return http_svr;
    }
    void InitServer()
    {
      lsock = Sock::Socket();
      Sock::SetSockOpt(lsock);//设为可复用状态
      Sock::Bind(lsock, port);
      Sock::Listen(lsock);

      tp = new ThreadPool();
      tp->InitThreadPool();
    }

    void Start()
    {
      for(;;)
      {
        int sock = Sock::Accept(lsock);
        if(sock < 0)
        {
          continue;
        }
        
        LOG(Notice, "get a new link...");
        
        Task *tk = new Task(sock);
        tp->PushTask(tk);
        //demo
        //int *sockp = new int(sock);
        //pthread_t tid;
        //pthread_create(&tid, nullptr, Entry::HandlerHttp, sockp);//线程处理请求响应
        //
        //pthread_detach(tid);
      }
    }

    ~HttpServer()
    {
      if(lsock >= 0)
      {
        close(lsock);
      }
    }
};

HttpServer *HttpServer::http_svr = nullptr;
pthread_mutex_t HttpServer::lock = PTHREAD_MUTEX_INITIALIZER; 
