#include "thread_pool.h"
#include "thread.h"

int main()
{

  for (int i = 0; i < 10; i++)
  {
    Execution::ThreadPool tp;

    Execution::Thread* t = tp.CheckOut();

    t->Execute();
  }
}
