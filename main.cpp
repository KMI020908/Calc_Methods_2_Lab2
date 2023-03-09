#include<vector>
#include"methods.cpp"
#include"ioData.cpp"
#include<iomanip>
#include"testFuncs.h"
#include<algorithm>

// Процедура для заполнения названий файла
template<typename Type>
void getFileNames(std::size_t numOfEq, CONDS_FLAG flag, Type sigma, std::string &SOLUTION_FILE, std::string &DATA_FILE, std::string &INTERVAL_FILE){
    SOLUTION_FILE = getFileNameHeatEq(numOfEq, flag, sigma, "solution");
    DATA_FILE = getFileNameHeatEq(numOfEq, flag, sigma, "data");
    INTERVAL_FILE = getFileNameHeatEq(numOfEq, flag, sigma, "interval");
}

// Решенние уравнений при разных sigma
template<typename Type>
void getHeatEquationSolution(std::size_t numOfEq, Type rho, Type c, Type(*K)(Type x), Type L, Type timeEnd,
std::size_t numOfXIntervals, std::size_t numOfTimeIntervals, Type anotherSigma, CONDS_FLAG flag, Type(*T0)(Type x) = zeroFunction, Type(*q1)(Type t) = zeroFunction, Type(*q2)(Type t) = zeroFunction){ 
    std::vector<std::size_t> numOfIntervalsVec = {numOfXIntervals, numOfTimeIntervals};
    std::string SOLUTION_FILE;
    std::string DATA_FILE;
    std::string INTERVAL_FILE;
    Type sigma;
    std::vector<Type> dataVec = {rho, c, L, timeEnd, sigma};

    sigma = 0.0;
    dataVec[4] = sigma;
    getFileNames(numOfEq, flag, sigma, SOLUTION_FILE, DATA_FILE, INTERVAL_FILE);
    solveHeatEquation(SOLUTION_FILE, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, sigma, flag, T0, q1, q2);
    writeVectorFile(dataVec, DATA_FILE);
    writeVectorFile(numOfIntervalsVec, INTERVAL_FILE);

    sigma = 1.0;
    dataVec[4] = sigma;
    getFileNames(numOfEq, flag, sigma, SOLUTION_FILE, DATA_FILE, INTERVAL_FILE);
    solveHeatEquation(SOLUTION_FILE, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, sigma, flag, T0, q1, q2);
    writeVectorFile(dataVec, DATA_FILE);
    writeVectorFile(numOfIntervalsVec, INTERVAL_FILE);

    sigma = 0.5;
    dataVec[4] = sigma;
    getFileNames(numOfEq, flag, sigma, SOLUTION_FILE, DATA_FILE, INTERVAL_FILE);
    solveHeatEquation(SOLUTION_FILE, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, sigma, flag, T0, q1, q2);
    writeVectorFile(dataVec, DATA_FILE);
    writeVectorFile(numOfIntervalsVec, INTERVAL_FILE);

    sigma = anotherSigma;
    dataVec[4] = sigma;
    getFileNames(numOfEq, flag, sigma, SOLUTION_FILE, DATA_FILE, INTERVAL_FILE);
    solveHeatEquation(SOLUTION_FILE, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, sigma, flag, T0, q1, q2);
    writeVectorFile(dataVec, DATA_FILE);
    writeVectorFile(numOfIntervalsVec, INTERVAL_FILE);
}

// Решенние квазилинейных уравнений
template<typename Type>
void getQuasiHeatEquationSolution(std::size_t numOfEq, Type rho, Type c, Type alpha, Type beta, Type gamma, Type L, Type timeEnd,
std::size_t numOfXIntervals, std::size_t numOfTimeIntervals, CONDS_FLAG flag = LT_RT, Type(*T0)(Type x) = zeroFunction, Type(*q1)(Type t) = zeroFunction, Type(*q2)(Type t) = zeroFunction, std::size_t numOfIters = 5){ 
    std::vector<std::size_t> numOfIntervalsVec = {numOfXIntervals, numOfTimeIntervals};
    std::string SOLUTION_FILE;
    std::string DATA_FILE;
    std::string INTERVAL_FILE;
    std::vector<Type> dataVec = {rho, c, L, timeEnd, alpha, beta, gamma, static_cast<Type>(numOfIters)};

    SOLUTION_FILE = getFileNameQuasiHeatEq(numOfEq, flag, "solution");
    DATA_FILE = getFileNameQuasiHeatEq(numOfEq, flag, "data");
    INTERVAL_FILE = getFileNameQuasiHeatEq(numOfEq, flag, "interval");
    solveHeatQuasilinearEquation(SOLUTION_FILE, rho, c, alpha, beta, gamma, L, timeEnd, numOfXIntervals, numOfTimeIntervals, flag, T0, q1, q2, numOfIters);

    writeVectorFile(dataVec, DATA_FILE);
    writeVectorFile(numOfIntervalsVec, INTERVAL_FILE);
}

template<typename Type>
void temp_main(){
    std::size_t numOfEq;
    Type rho, c, L, timeEnd, alpha, beta, gamma;
    std::size_t numOfXIntervals, numOfTimeIntervals, numOfIters, numOfXIntervalsQuasi, numOfTIntervalsQuasi;
    CONDS_FLAG flag;
    Type anotherSigma;
    Type (*T0)(Type x) = nullptr;
    Type (*T1)(Type t) = nullptr;
    Type (*T2)(Type t) = nullptr;
    Type (*q1)(Type t) = nullptr;
    Type (*q2)(Type t) = nullptr;
    Type (*K)(Type x) = nullptr;
    
    // Первое уравнение // 1ый вариант
    numOfEq = 1;
    rho = 1.0;
    c = 1.0;
    L = 1.0;
    anotherSigma = 0.75;
    K = K1;
    T0 = T01;
    q1 = q1_1;
    T2 = T2_1;
    timeEnd = 5.0;
    numOfXIntervals = 100;
    numOfTimeIntervals = 1000;
    alpha = 2.0;
    beta = 0.5;
    gamma = 3.0;
    numOfXIntervalsQuasi = 20;
    numOfTIntervalsQuasi = 50000;

    flag = LQ_RT;
    //getHeatEquationSolution(numOfEq, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, anotherSigma, flag, T0, q1, T2);
    getQuasiHeatEquationSolution(numOfEq, rho, c, alpha, beta, gamma, L, timeEnd, numOfXIntervalsQuasi, numOfTIntervalsQuasi, flag, T0, q1, T2);


    // Второе уравнение // 9ый вариант
    numOfEq = 2;
    rho = 4.0;
    c = 0.5;
    L = 1.0;
    anotherSigma = 0.75;
    K = K2;
    T0 = T02;
    q1 = q1_2;
    T2 = T2_2;
    timeEnd = 5.0;
    numOfXIntervals = 100;
    numOfTimeIntervals = 1000;
    alpha = 0.1;
    beta = 1.0;
    gamma = 3.0;
    numOfXIntervalsQuasi = 5;
    numOfTIntervalsQuasi = 50000;

    flag = LQ_RT;
    //getHeatEquationSolution(numOfEq, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, anotherSigma, flag, T0, q1, T2);
    getQuasiHeatEquationSolution(numOfEq, rho, c, alpha, beta, gamma, L, timeEnd, numOfXIntervalsQuasi, numOfTIntervalsQuasi, flag, T0, q1, T2);


    // Проверка изолированных концов
    numOfEq = 3;
    rho = 1.0;
    c = 1.0;
    L = 1.0;
    anotherSigma = 0.75;
    K = K3;
    T0 = T03;
    q1 = q1_3;
    q2 = q2_3;
    timeEnd = 10.0;
    numOfXIntervals = 100;
    numOfTimeIntervals = 1000;

    flag = LQ_RQ;
    //getHeatEquationSolution(numOfEq, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, anotherSigma, flag, T0, q1, q2);


    // Проверка квазилинейного уравнения из учебника
    numOfEq = 4;
    rho = 1.0;
    c = 1.0;
    L = 10.0;
    T0 = T04;
    T1 = T1_4;
    T2 = T2_4;
    timeEnd = 2.0;
    alpha = 0.0;
    beta = 0.5;
    gamma = 2.0;
    numOfXIntervalsQuasi = 50;
    numOfTIntervalsQuasi = 10000;

    flag = LT_RT;
    getQuasiHeatEquationSolution(numOfEq, rho, c, alpha, beta, gamma, L, timeEnd, numOfXIntervalsQuasi, numOfTIntervalsQuasi, flag, T0, T1, T2);

}

int main(){
    temp_main<double>();
    return 0;
}