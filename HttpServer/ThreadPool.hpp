#pragma once

#include <iostream>
#include <queue>
#include <pthread.h>
#include "Protocol.hpp"

typedef void (*handler_t)(int);

class Task{
  private:
    int sock;
    handler_t handler;
  
  public:
    Task(int sk):sock(sk),handler(Entry::HandlerHttp)
    {}
    void Run()
    {
      handler(sock);
    }
    ~Task()
    {}
};

class ThreadPool{
  private:
    std::queue<Task*> q;
    int num;
    pthread_mutex_t lock;
    pthread_cond_t cond;

  public:
    ThreadPool(int n = 3):num(n)
    {}
    void LockQueue()
    {
      pthread_mutex_lock(&lock);
    }
    void UnlockQueue()
    {
      pthread_mutex_unlock(&lock);
    }
    bool IsEmpty()
    {
      return q.size() == 0;
    }
    void ThreadWait()
    {
      pthread_cond_wait(&cond, &lock);
    }
    void ThreadWakeup()
    {
      pthread_cond_signal(&cond);
    }
    static void *Routinue(void *args)
    {
      ThreadPool *tp = (ThreadPool*)args;
      tp->LockQueue();
      while(tp->IsEmpty())
      {
        tp->ThreadWait();
      }
      Task *tk = tp->PopTask();
      tp->UnlockQueue();

      tk->Run();

      delete tk;
      //todo
    }
    void InitThreadPool()
    {
      pthread_mutex_init(&lock, nullptr);
      pthread_cond_init(&cond, nullptr);

      pthread_t tid;
      for(auto i = 0; i < num; ++i)
      {
        pthread_create(&tid, nullptr, Routinue, this);
        pthread_detach(tid);
      }
    }
    void PushTask(Task* tk)
    {
      LockQueue();
      q.push(tk);
      UnlockQueue();
      ThreadWakeup();
    }
    Task* PopTask()
    {
      Task* tk = q.front();
      q.pop();
      return tk;
    }
    ~ThreadPool()
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&cond);
    }
};
