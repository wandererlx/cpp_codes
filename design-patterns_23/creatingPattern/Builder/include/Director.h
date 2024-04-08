// Director.h
#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"

// 指挥者
class Direcror
{
public:
    void Create(IBuilder *builder);
};

#endif // DIRECTOR_H