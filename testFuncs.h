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
    template<typename Type>
    Type realSolution1(Type t, Type x){
        return std::sin(M_PI * x) * std::cos(M_PI * t);
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
    template<typename Type>
    Type realSolution2(Type t, Type x){
        std::size_t k = 10;
        Type sum = 0.0;
        for (size_t n = 0; n < k; n++){
            sum += 8.0 / std::pow(M_PI, 3.0) / std::pow(2.0 * n + 1, 3.0) * std::sin((2.0 * n + 1) * M_PI * x) * std::cos((2.0 * n + 1) * M_PI * t); 
        }
        return sum;
    }

    // Первый тест из доп. задач
    template<typename Type>
    Type U0_3(Type x){
        if (std::abs(x) <= 1.0 / 3.0){
            return 1.0;
        }
        return 0.0;
    }
    template<typename Type>
    Type Ut0_3(Type x){
        return 0.0;
    }
    template<typename Type>
    Type bound1_3(Type t){
        return 0.0;
    }
    template<typename Type>
    Type bound2_3(Type t){
        return 0.0;
    }

    // Второй тест из доп. задач
    template<typename Type>
    Type U0_4(Type x){
        return 0.0;
    }
    template<typename Type>
    Type Ut0_4(Type x){
        if (std::abs(x) <= 0.5){
            return 1.0 - 2.0 * std::abs(x);
        }
        return 0.0;
    }
    template<typename Type>
    Type bound1_4(Type t){
        return 0.0;
    }
    template<typename Type>
    Type bound2_4(Type t){
        return 0.0;
    }

    // Третий тест из доп. задач
    template<typename Type>
    Type U0_5(Type x){
        return 0.0;
    }
    template<typename Type>
    Type Ut0_5(Type x){
        return 0.0;
    }
    template<typename Type>
    Type bound1_5(Type t){
        return std::sin(t);
    }
    template<typename Type>
    Type bound2_5(Type t){
        return 0.0;
    }

#endif