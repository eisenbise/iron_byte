#include "thread_pool.h"
#include "thread.h"

#include <map>
int main()
{
  Execution::ThreadPool tp;
  std::map<int, Execution::Thread*> threads;

  for (int i = 0; i < 100; i++)
  {

    Execution::Thread* t = tp.CheckOut();

    if (NULL != t)
    {
      t->Execute();
      threads[i] = t;
    }
  }

  for (auto t = threads.begin(); t != threads.end(); t++)
  {
    t->second->Wait();
  }
}
