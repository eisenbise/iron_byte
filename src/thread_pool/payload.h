#pragma once

namespace Execution
{
  class Payload
  {
  public:
    Payload(void);

    ~Payload(void);

    void operator()() { Execute(); }
  private:
    int Execute(void);

  };
}
