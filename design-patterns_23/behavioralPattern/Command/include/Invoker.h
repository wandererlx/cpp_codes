// Invoker.h

#ifndef _INVOKER_H_
#define _INVOKER_H_

#include "Command.h"

class Invoker {
 public:
  Invoker(Command *pCommand);
  virtual ~Invoker();
  void call();

 private:
  Command *m_pCommand;
};

#endif  //_INVOKER_H_