#include "thread_pool.h"

#include "thread.h"

#include <iostream>

namespace Execution
{
  const int NumberOfThreads = 10;

  //----------------------------------------------------------------------------
  // ThreadPool
  //----------------------------------------------------------------------------
  ThreadPool::ThreadPool()
  {
    for(int i = 0; i < NumberOfThreads; i++)
    {
      mThreads[i] = new Thread(i);
    }
  }

  //----------------------------------------------------------------------------
  // ~ThreadPool
  //----------------------------------------------------------------------------
  ThreadPool::~ThreadPool()
  {
    for(auto thread = mThreads.begin(); thread != mThreads.end(); thread++)
    {
      delete(thread->second);
    }
  }

  //----------------------------------------------------------------------------
  // CheckOut
  //----------------------------------------------------------------------------
  Thread* ThreadPool::CheckOut(void)
  {
    Thread* outThread = NULL;
    for(auto thread = mThreads.begin(); thread != mThreads.end(); thread++)
    {
      if (!thread->second->IsCheckedOut())
      {
        outThread = thread->second;
        outThread->CheckOut();
        break;
      }
    }
    if (NULL == outThread)
    {
      std::cout << "No threads in the pool" << std::endl;
    }
    return outThread;
  }

  //----------------------------------------------------------------------------
  // CheckIn
  //----------------------------------------------------------------------------
  void ThreadPool::CheckIn(int pThreadId)
  {
    if (NULL != mThreads[pThreadId])
    {
      mThreads[pThreadId]->CheckIn();
    }
  }
}
