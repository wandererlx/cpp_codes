//Composite.h

#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include "Component.h"
#include <vector>

using namespace std;

class Composite:public Component
{
private:
    vector<Component*> comVec;

public:
    Composite();
    ~Composite();

    void Operation();
    void Add(Component* com);
    void Remove(Component* com);
    Component* GetChild(int index);

};

#endif //~_COMPOSITE_H_
