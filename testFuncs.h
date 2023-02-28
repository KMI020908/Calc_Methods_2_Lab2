// Файл, содержащий функции для тестов
#ifndef TEST_FUNC_H
#define TEST_FUNC_H

#include<cmath>

// Функции для первого теста
template<typename Type>
Type K1(Type x){
    return 1.0;
}
template<typename Type>
Type T01(Type x){
    return 1.0 + x * (1.0 - x);
}
template<typename Type>
Type P1(Type t){
    return t + 1;
}

#endif