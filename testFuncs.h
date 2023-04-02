// Файл, содержащий функции для тестов
#ifndef TEST_FUNC_H
#define TEST_FUNC_H
#include<cmath>

    // Первый тест из методички
    template<typename Type>
    Type U0_1(Type x){
        return std::sin(M_PI * x);
    }
    template<typename Type>
    Type Ut0_1(Type x){
        return 0.0;
    }
    template<typename Type>
    Type bound1_1(Type t){
        return 0.0;
    }
    template<typename Type>
    Type bound2_1(Type t){
        return 0.0;
    }

    // Второй тест из методички
    template<typename Type>
    Type U0_2(Type x){
        return x * (1.0 - x);
    }
    template<typename Type>
    Type Ut0_2(Type x){
        return 0.0;
    }
    template<typename Type>
    Type bound1_2(Type t){
        return 0.0;
    }
    template<typename Type>
    Type bound2_2(Type t){
        return 0.0;
    }

#endif