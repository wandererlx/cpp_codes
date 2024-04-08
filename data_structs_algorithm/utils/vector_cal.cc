//
// Created by shawnunili on 2019/3/25.
//
#include "vector_cal.h"
#include <immintrin.h>
#include <vector>
#include <cmath>
#include <iostream>

float xct::dot(float* a, float* b, int n) {
    float res = 0.0;
    int k = n / 8 + 1;
    for(int i = 0; i < k; ++i)
    {
        __m256 ai = _mm256_loadu_ps(a + i * 8);
        __m256 bi = _mm256_loadu_ps(b + i * 8);
        __m256 r = _mm256_dp_ps(ai, bi, 0xF1);
        res += ((float*) &r)[0] + ((float*) &r)[4];
    }
    return res;
}
float xct::dot2(float* a, float* b, int n) {
    float res = 0.0;
    int k = n / 8;
    for(int i = 0; i < k; ++i)
    {
        __m256 ai = _mm256_loadu_ps(a + i * 8);
        __m256 bi = _mm256_loadu_ps(b + i * 8);
        __m256 r = _mm256_dp_ps(ai, bi, 0xF1);
        res += ((float*) &r)[0] + ((float*) &r)[4];
    }
    int index = k * 8;
    for (; index < n; ++index) {
        res += a[index] * b[index];
    }
    return res;
}

void xct::test_dot() {
    std::vector<float> v1(9, 1.1);
    std::vector<float> v2(9, 2.2);

    float* p1 = &v1.front();
    float* p2 = &v2.front();

    float m1 = sqrt(dot2(p1, p1, v1.size()));
    float m2 = sqrt(dot2(p2, p2, v2.size()));

    double d = dot2(p1, p2, v1.size());

    float result = d/(m1*m2);

    std::cout << "m1:" <<  m1 << std::endl;
    std::cout << "m2:" <<m2 << std::endl;
    std::cout << "d:" << d << std::endl;
    std::cout << "result: " << result << std::endl;
}
