// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

using namespace std;

// 电脑
class Computer
{
public:
    void SetmCpu(string cpu);
    void SetmMainboard(string mainboard);
    void SetmRam(string ram);
    void SetVideoCard(string videoCard);

    string GetCPU();
    string GetMainboard();
    string GetRam();
    string GetVideoCard();

private:
    string m_strCpu;  // CPU
    string m_strMainboard;  // 主板
    string m_strRam;  // 内存
    string m_strVideoCard;  // 显卡
};

#endif // PRODUCT_H