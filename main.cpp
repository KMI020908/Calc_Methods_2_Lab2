#include<vector>
#include"methods.cpp"
#include"ioData.cpp"
#include"filePath.h"
#include<iomanip>
#include"testFuncs.h"
#include<algorithm>

template<typename Type>
Type K1(Type x){
    return 1.0;
}

template<typename Type>
Type P1(Type t){
    return t;
}

template<typename Type>
void temp_main(){
    Type rho = 1.0;
    Type c = 1.0;
    Type L = 1.0;
    Type timeEnd = 10.0;
    Type T0 = 1.0;
    std::size_t numOfTimeIntervals = 10;
    std::size_t numOfXIntervals = 5;
    Type sigma = 1.0;
    std::vector<std::vector<Type>> solution;
    solveHeatEquationMixedCondsLeftT(rho, c , K1, L, timeEnd, T0, P1, numOfXIntervals, numOfTimeIntervals, sigma, solution);

}

int main(){
    temp_main<double>();
    return 0;
}