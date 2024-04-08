//main.cpp

#include "../include/Context.h"
#include "../include/State.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
    State* st = new ConcreteStateA();
    Context* con = new Context(st);
    con->OprationInterface();
    con->OprationInterface();
    con->OprationInterface();

    if (con != NULL) delete con;
    if (st != NULL) st = NULL;

    return 0;
}