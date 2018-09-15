#pragma once

namespace Execution
{
  class Payload;

  class Thread
  {
  public:
    Thread(int pThreadId);

    ~Thread(void);

    void CheckOut(void)     { isCheckedOut = true; }
    void CheckIn (void)     { isCheckedOut = false; }
    bool IsCheckedOut(void) { return isCheckedOut; }
    bool IsActive(void)     { return isActive; }

    int Init(Payload* pPayload);
    int Execute(void);

  private:
    bool IsValid(void);

    Payload* mPayload;

    const int mThreadId;

    bool isCheckedOut;
    bool isActive;
  };
}
