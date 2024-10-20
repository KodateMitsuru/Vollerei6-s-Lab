#pragma once

#include <random>

class RandomGenerator {
public:
    static std::mt19937& getGenerator() {
        static std::mt19937 generator(std::random_device{}()); // ��̬�ֲ�������ֻ��ʼ��һ��  
        return generator;
    }

    static std::normal_distribution<>& getNormalDistribution() {
        static std::normal_distribution<> distribution(1.0, 0.1); // ��̬�ֲ�������ֻ��ʼ��һ��  
        return distribution;
    }

    // ������Ա����...  
};

inline double getDis() 
{
    return RandomGenerator::getNormalDistribution()(RandomGenerator::getGenerator());
}
