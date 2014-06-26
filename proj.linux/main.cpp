#include <iostream>
#include <ctime>
#include <vector>
#include <numeric>

#include "../Classes/AppDelegate.h"
#include "cocos2d.h"

USING_NS_CC;

float ccArraySum(float count) {
    CCArray* array = CCArray::create();
    array->initWithCapacity((int)count);
    for(float f = 0.0f; f < count; ++f) {
        array->addObject(new CCFloat(f));
    }
    float sum = 0.0f;
    CCObject* elem = NULL;
    CCARRAY_FOREACH(array, elem) {
        CCFloat* f = static_cast<CCFloat*>(elem);
        sum += f->getValue();
    }
    return sum;
}

float stdVectorSum(float count) {
    std::vector<float> vec((long)count);
    for(float f = 0.0f; f < count; ++f) {
        vec.push_back(f);
    }
    return std::accumulate(vec.begin(), vec.end(), 0.0f);
}

float stdVectorSum2(float count) {
    std::vector<CCFloat> vec((long)count);
    for(float f = 0.0f; f < count; ++f) {
        vec.push_back(CCFloat(f));
    }
    std::cout << vec[0].getValue() << std::endl;
    float sum = 0.0f;
    for(size_t i = 0; i < vec.size(); ++i) {
        sum += vec[i].getValue();
    }
    return sum;
}

int main(int argc, char **argv)
{
    float count = 3000000.0f;
    {
        clock_t start = std::clock();
        std::cout << ccArraySum(count) << std::endl;
        std::cout << (double)std::difftime(std::clock(), start) / CLOCKS_PER_SEC << "s" << std::endl;
    }
    {
        clock_t start = std::clock();
        std::cout << stdVectorSum(count) << std::endl;
        std::cout << (double)std::difftime(std::clock(), start) / CLOCKS_PER_SEC << "s" << std::endl;
    }
    {
        clock_t start = std::clock();
        std::cout << stdVectorSum2(count) << std::endl;
        std::cout << (double)std::difftime(std::clock(), start) / CLOCKS_PER_SEC << "s" << std::endl;
    }
    return 0;
}
