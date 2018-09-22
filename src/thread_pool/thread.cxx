// Local
#include "thread.h"
#include "payload.h"

// std
#include <stddef.h>
#include <thread>

namespace Execution
{

  //----------------------------------------------------------------------------
  // ~Thread
  //----------------------------------------------------------------------------
  Thread::Thread(int pThreadId) :
      mThreadId   (pThreadId),
      isCheckedOut(false),
      isActive    (false)
  {
    mLocalThread = NULL;
    mPayload = NULL;
  }

  //----------------------------------------------------------------------------
  // ~Thread
  //----------------------------------------------------------------------------
  Thread::~Thread()
  {
    if(IsValid())
    {
      delete mPayload;
    }
  }

  //----------------------------------------------------------------------------
  // IsValid
  //----------------------------------------------------------------------------
  bool Thread::IsValid()
  {
    bool isValid = false;

    if (NULL != mPayload)
    {
      isValid = true;
    }
    return isValid;
  }


  //----------------------------------------------------------------------------
  // Init
  //----------------------------------------------------------------------------
  int Thread::Init(Payload * pPayload)
  {
    *mPayload = *pPayload;

    return IsValid();
  }

  //----------------------------------------------------------------------------
  // Execute
  //----------------------------------------------------------------------------
  int Thread::Execute()
  {
    isActive = true;

    mLocalThread = new std::thread(*mPayload);
  }

  //----------------------------------------------------------------------------
  // Wait
  //----------------------------------------------------------------------------
  void Thread::Wait()
  {
    mLocalThread->join();

    isActive = false;
  }
}
