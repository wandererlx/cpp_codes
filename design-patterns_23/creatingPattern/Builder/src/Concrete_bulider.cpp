// Concrete_bulider.cpp

#include "../include/Concrete_bulider.h"
#include <iostream>

using namespace std;

ThinkPadBuilder::ThinkPadBuilder() { m_pComputer = new Computer(); }
void ThinkPadBuilder::BuildCpu() { m_pComputer->SetmCpu("i5-6200U"); }
void ThinkPadBuilder::BuildMainboard() { m_pComputer->SetmMainboard("Intel DH57DD"); }
void ThinkPadBuilder::BuildRam() { m_pComputer->SetmRam("DDR4"); }
void ThinkPadBuilder::BuildVideoCard() { m_pComputer->SetVideoCard("NVIDIA Geforce 920MX"); }
Computer* ThinkPadBuilder::GetResult() { return m_pComputer; }

YogaBuilder::YogaBuilder() { m_pComputer = new Computer(); }
void YogaBuilder::BuildCpu() { m_pComputer->SetmCpu("i7-7500U"); }
void YogaBuilder::BuildMainboard() { m_pComputer->SetmMainboard("Intel DP55KG"); }
void YogaBuilder::BuildRam() { m_pComputer->SetmRam("DDR5"); }
void YogaBuilder::BuildVideoCard() { m_pComputer->SetVideoCard("NVIDIA GeForce 940MX"); }
Computer* YogaBuilder::GetResult() { return m_pComputer; }