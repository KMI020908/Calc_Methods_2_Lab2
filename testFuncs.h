// Файл, содержащий функции для тестов
#ifndef TEST_FUNC_H
#define TEST_FUNC_H

#include<cmath>

// Функции для первого теста // 1ый вариант
template<typename Type>
Type K1(Type x){
    Type x1 = 1.0 / 3.0;
    Type x2 = 2.0 / 3.0;
    Type k1 = 1.0;
    Type k2 = 0.1;
    if (x  <= x1){
        return k1;
    }
    if (x > x1 && x < x2){
        return k1 * (x - x2) / (x1 - x2) + k2 * (x - x1) / (x2 - x1);
    }
    return k2;
}
template<typename Type>
Type T01(Type x){
    return 0.1;
}
template<typename Type>
Type q1_1(Type t){
    Type Q = 10.0;
    Type t0 = 0.5;
    if (t >= t0){
        return 0.0;
    }else{
        return Q;
    }
    return NAN;
}
template<typename Type>
Type T2_1(Type t){
    return 0.1;
}

// Функции для второго теста // 9ый вариант
template<typename Type>
Type K2(Type x){
    Type x1 = 1.0 / 3.0;
    Type x2 = 3.0 / 4.0;
    Type k1 = 0.5;
    Type k2 = 2.5;
    if (x  <= x1){
        return k1;
    }
    if (x > x1 && x < x2){
        return k1 * (x - x2) / (x1 - x2) + k2 * (x - x1) / (x2 - x1);
    }
    return k2;
}
template<typename Type>
Type T02(Type x){
    return 0.3;
}
template<typename Type>
Type q1_2(Type t){
    Type Q = 10.0;
    Type t0 = 0.5;
    if (t >= t0){
        return 0.0;
    }else{
        return Q;
    }
    return NAN;
}
template<typename Type>
Type T2_2(Type t){
    return 0.3;
}

// Функции для третьего теста // Изолированные концы
template<typename Type>
Type K3(Type x){
    return 1.0;
}
template<typename Type>
Type T03(Type x){
    return x;
}
template<typename Type>
Type q1_3(Type t){
    return 0.0;
}
template<typename Type>
Type q2_3(Type t){
    return 0.0;
}

// Функция для проверки квазилинейного уравнения из учебника
template<typename Type>
Type T04(Type x){
    return 0.0;
}
template<typename Type>
Type T1_4(Type t){
    Type sigma = 2.0;
    Type kappa0 = 0.5;
    Type c = 5.0;
    Type u0 = std::pow((sigma * c * c) / kappa0, 1.0 / sigma);
    return u0 * std::pow(t, 1.0/ sigma);
}
template<typename Type>
Type T2_4(Type t){
    return 0.0;
}

// Тест для проверки порядка точности
template<typename Type>
Type T05(Type x){
    return (x - 0.5) * (x - 0.5) + 1.0;
}
template<typename Type>
Type K5(Type x){
    return 1.0;
}
template<typename Type>
Type q1_5(Type t){
    return t + 1.0;
}
template<typename Type>
Type q2_5(Type t){
    return t + 1.0;
}

// Тест для проверки порядка точности с использованием аналитического решения
template<typename Type>
Type T06(Type x){
    Type alpha = 3.0;
    Type beta = 8.0;
    return std::cos(beta * x) + std::sin(beta * x);
}
template<typename Type>
Type K6(Type x){
    Type alpha = 3.0;
    Type beta = 8.0;
    return alpha / std::pow(beta, 2.0);
}
template<typename Type>
Type q1_6(Type t){
    Type alpha = 3.0;
    Type beta = 8.0;
    return -beta * std::exp(-alpha * t) * K6(0.0);
}
template<typename Type>
Type q2_6(Type t){
    Type alpha = 3.0;
    Type beta = 8.0;
    return std::exp(-alpha * t) * beta * (std::cos(beta) - std::sin(beta)) * K6(1.0);
}

template<typename Type>
Type realSol6(Type t, Type x){
    Type alpha = 3.0;
    Type beta = 8.0;
    return std::exp(-alpha * t) * (std::sin(beta * x) + std::cos(beta * x));
}

// Функции для обезразмерования
template<typename Type>
Type K7(Type x){
    return 4.0;
}
template<typename Type>
Type T07(Type x){
    return 0.0; 
}

template<typename Type>
Type T1_7(Type t){
    return 5.0;
}

template<typename Type>
Type T2_7(Type t){
    return 0.0;
}

// Функции для немонотонного
template<typename Type>
Type K8(Type x){
    Type x1 = 0.0;
    Type x2 = 1.0;
    Type k1 = 0.5;
    Type k2 = 1.5;
    if (x  <= x1){
        return k1;
    }
    if (x > x1 && x < x2){
        return k1 * (x - x2) / (x1 - x2) + k2 * (x - x1) / (x2 - x1);
    }
    return k2;
}

template<typename Type>
Type T08(Type x){
    return 0.04 + x * (1.0 - x);
}

template<typename Type>
Type q1_8(Type t){
    return 0.04;
}

template<typename Type>
Type q2_8(Type t){
    return 0.04;
}

// Функции для обезразмерования на шару
template<typename Type>
Type K9(Type x){
    return 1e-4;
}

template<typename Type>
Type T1_9(Type t){
    return 1.0;
}

template<typename Type>
Type T09(Type x){
    //return T1_9(0.0) * std::sqrt(100.0 - std::pow(x, 2.0)) / 10.0; 
    return 0.0;
}

template<typename Type>
Type T2_9(Type t){
    return 0.0;
}

template<typename Type>
Type D(Type ){
    return 1e-8;
}

#endif