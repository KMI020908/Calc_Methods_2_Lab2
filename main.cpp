#include<vector>
#include"methods.cpp"
#include"ioData.cpp"
#include"filePath.h"
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
void getHeatEquationSolutionFirstConds(std::size_t numOfEq, Type rho, Type c, Type(*K)(Type x), Type L, Type timeEnd,
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



template<typename Type>
void temp_main(){
    std::size_t numOfEq;
    Type rho, c, L, timeEnd;
    std::size_t numOfXIntervals, numOfTimeIntervals;
    CONDS_FLAG flag;
    Type anotherSigma;
    Type (*T0)(Type x) = nullptr;
    Type (*q1)(Type t) = nullptr;
    Type (*q2)(Type t) = nullptr;
    Type (*K)(Type x) = nullptr;
    
    // Первое уравнение
    numOfEq = 1;
    rho = 1.0;
    c = 1.0;
    L = 1.0;
    anotherSigma = 0.75;
    K = K1;
    T0 = T01;
    q1 = q1_1;
    q2 = q2_1;
    timeEnd = 10.0;
    numOfXIntervals = 10;
    numOfTimeIntervals = 100;
    flag = LT_RT;
    getHeatEquationSolutionFirstConds(numOfEq, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, anotherSigma, flag, T0);
    flag = LT_RQ;
    getHeatEquationSolutionFirstConds(numOfEq, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, anotherSigma, flag, T0, q1);
    flag = LQ_RT;
    getHeatEquationSolutionFirstConds(numOfEq, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, anotherSigma, flag, T0, q2);
    flag = LQ_RQ;
    getHeatEquationSolutionFirstConds(numOfEq, rho, c, K, L, timeEnd, numOfXIntervals, numOfTimeIntervals, anotherSigma, flag, T0, q1, q2);
}

int main(){
    temp_main<double>();
    return 0;
}