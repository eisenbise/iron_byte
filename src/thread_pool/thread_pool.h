#pragma once

#include <map>

namespace Execution
{
  class Thread;

  class ThreadPool
  {
    public:
      ThreadPool(void);

      ~ThreadPool(void);

      Thread* CheckOut(void);

      void CheckIn(int pThreadId);

    private:
      std::map<int, Thread*> mThreads;
  };
}
