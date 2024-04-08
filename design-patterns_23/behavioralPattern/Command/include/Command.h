//Command.h

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Receiver.h"

class Command
{
public:
    Command();
    virtual ~Command();
    virtual void execute() = 0;
};

#endif //_COMMAND_H_