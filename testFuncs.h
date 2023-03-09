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
Type q2_1(Type t){
    return 0.0;
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
Type q2_2(Type t){
    return 0.0;
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

#endif