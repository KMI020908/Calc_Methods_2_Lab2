#include<vector>
#include"methods.cpp"
#include"ioData.cpp"
#include"filePath.h"
#include<iomanip>
#include"testFuncs.h"
#include<algorithm>

// T_left && Q_right
template<typename Type>
void getHeatEquationMixedCondsLeftT(Type rho, Type c, Type(*K)(Type x), Type L, Type timeEnd, Type(*T0)(Type x), MIXED_CONDS_FLAG flag, Type(*q)(Type t),
std::size_t numOfXIntervals, std::size_t numOfTimeIntervals, Type sigma, 
const std::string &SOLUTION_FILE, const std::string &DATA_FILE, const std::string &INTERVAL_FILE){ 
    std::vector<Type> dataVec = {rho, c, L, timeEnd, sigma};
    std::vector<std::size_t> numOfIntervalsVec = {numOfXIntervals, numOfTimeIntervals};
    solveHeatEquationMixedConds(rho, c , K, L, timeEnd, T0, flag, q, numOfXIntervals, numOfTimeIntervals, sigma, SOLUTION_FILE);
    writeVectorFile(dataVec, DATA_FILE);
    writeVectorFile(numOfIntervalsVec, INTERVAL_FILE);
}

template<typename Type>
void temp_main(){
    Type rho, c, L, timeEnd, sigma;
    std::size_t numOfXIntervals, numOfTimeIntervals;
    MIXED_CONDS_FLAG flag;
    
    // Первое уравнение
    rho = 1.0;
    c = 1.0;
    L = 1.0;
    timeEnd = 10.0;
    numOfXIntervals = 10;
    numOfTimeIntervals = 100;

    flag = LT_RQ;
    sigma = 0.0;
    getHeatEquationMixedCondsLeftT(rho, c , K1, L, timeEnd, T01, flag, P1, numOfXIntervals, numOfTimeIntervals, sigma, MIX_LEFT_FW_SOLUTION_FILE_1, MIX_LEFT_FW_DATA_FILE_1, MIX_LEFT_FW_INTERVAL_FILE_1);
    sigma = 0.5;
    getHeatEquationMixedCondsLeftT(rho, c , K1, L, timeEnd, T01, flag, P1, numOfXIntervals, numOfTimeIntervals, sigma, MIX_LEFT_SYM_SOLUTION_FILE_1, MIX_LEFT_SYM_DATA_FILE_1, MIX_LEFT_SYM_INTERVAL_FILE_1);
    sigma = 1.0;
    getHeatEquationMixedCondsLeftT(rho, c , K1, L, timeEnd, T01, flag, P1, numOfXIntervals, numOfTimeIntervals, sigma, MIX_LEFT_BW_SOLUTION_FILE_1, MIX_LEFT_BW_DATA_FILE_1, MIX_LEFT_BW_INTERVAL_FILE_1);
    sigma = 0.52;
    getHeatEquationMixedCondsLeftT(rho, c , K1, L, timeEnd, T01, flag, P1, numOfXIntervals, numOfTimeIntervals, sigma, MIX_LEFT_AN_SOLUTION_FILE_1, MIX_LEFT_AN_DATA_FILE_1, MIX_LEFT_AN_INTERVAL_FILE_1);
    flag = RT_LQ;
    sigma = 0.0;
    getHeatEquationMixedCondsLeftT(rho, c , K1, L, timeEnd, T01, flag, P1, numOfXIntervals, numOfTimeIntervals, sigma, MIX_LEFT_FW_SOLUTION_FILE_1, MIX_LEFT_FW_DATA_FILE_1, MIX_LEFT_FW_INTERVAL_FILE_1);
    sigma = 0.5;
    getHeatEquationMixedCondsLeftT(rho, c , K1, L, timeEnd, T01, flag, P1, numOfXIntervals, numOfTimeIntervals, sigma, MIX_LEFT_SYM_SOLUTION_FILE_1, MIX_LEFT_SYM_DATA_FILE_1, MIX_LEFT_SYM_INTERVAL_FILE_1);
    sigma = 1.0;
    getHeatEquationMixedCondsLeftT(rho, c , K1, L, timeEnd, T01, flag, P1, numOfXIntervals, numOfTimeIntervals, sigma, MIX_LEFT_BW_SOLUTION_FILE_1, MIX_LEFT_BW_DATA_FILE_1, MIX_LEFT_BW_INTERVAL_FILE_1);
    sigma = 0.52;
    getHeatEquationMixedCondsLeftT(rho, c , K1, L, timeEnd, T01, flag, P1, numOfXIntervals, numOfTimeIntervals, sigma, MIX_LEFT_AN_SOLUTION_FILE_1, MIX_LEFT_AN_DATA_FILE_1, MIX_LEFT_AN_INTERVAL_FILE_1);
}

int main(){
    temp_main<double>();
    return 0;
}