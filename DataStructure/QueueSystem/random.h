#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED
#include "allheader.h"
class Random {
public:
    // [0, 30) ֮��ķ��Ӿ��ȷֲ������ֵ
    static double uniform(double max = 0.5) {
        return ((double)std::rand() / (RAND_MAX))*max;
    }
};


#endif // RANDOM_H_INCLUDED
