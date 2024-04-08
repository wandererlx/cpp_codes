// Concrete_bulider.h
#ifndef CONCRETE_BULIDER_H
#define CONCRETE_BULIDER_H

#include "Builder.h"

// ThinkPad 系列
class ThinkPadBuilder : public IBuilder
{
public:
    ThinkPadBuilder();
    void BuildCpu();
    void BuildMainboard();
    void BuildRam();
    void BuildVideoCard();
    Computer* GetResult();

private:
    Computer *m_pComputer;
};

// Yoga 系列
class YogaBuilder : public IBuilder
{
public:
    YogaBuilder();
    void BuildCpu();
    void BuildMainboard();
    void BuildRam();
    void BuildVideoCard();
    Computer* GetResult();

private:
    Computer *m_pComputer;
};

#endif // CONCRETE_BULIDER_H