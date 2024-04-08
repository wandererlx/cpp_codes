// main.cpp

#include <iostream>
#include "../include/Command.h"
#include "../include/Concrete.h"
#include "../include/Invoker.h"
#include "../include/Receiver.h"

using namespace std;

int main(int argc, char *argv[]) {
  Receiver *pReceiver = new Receiver();
  ConcreteCommand *pCommand = new ConcreteCommand(pReceiver);
  Invoker *pInvoker = new Invoker(pCommand);
  pInvoker->call();

  if (NULL != pReceiver) delete pReceiver;
  if (NULL != pCommand) delete pCommand;
  if (NULL != pInvoker) delete pInvoker;

  return 0;
}