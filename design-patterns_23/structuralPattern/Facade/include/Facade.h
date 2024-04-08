//Facade.h

#ifndef _FACADE_H_
#define _FACADE_H_

class Subsystem1
{
private:
    /* data */
public:
    Subsystem1(/* args */);
    ~Subsystem1();
    void Operation();
};

class Subsystem2
{
private:
    /* data */
public:
    Subsystem2(/* args */);
    ~Subsystem2();
    void Operation();
};

class Facade
{
private:
    Subsystem1* _subs1;
    Subsystem2* _subs2;

public:
    Facade(/* args */);
    ~Facade();
    void OperationWrapper();
};

#endif //~_FACADE_H_


