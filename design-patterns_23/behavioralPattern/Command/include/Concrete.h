// Concrete.h

#ifndef _CONCRETE_H_
#define _CONCRETE_H_

#include "Command.h"
#include "Receiver.h"

class ConcreteCommand : public Command {
 public:
  ConcreteCommand(Receiver *pReceiver);
  virtual ~ConcreteCommand();
  virtual void execute();

 private:
  Receiver *m_pReceiver;
};

#endif  //_CONCRETE_H_