#include<vector>
#include"methods.cpp"
#include"ioData.cpp"
#include<iomanip>
#include"testFuncs.h"
#include<algorithm>
#include<cstdio>

// Процедура для заполнения названий файла
void getFileNames(std::size_t numOfEq, std::string &SOLUTION_FILE, std::string &DATA_FILE, std::string &INTERVAL_FILE){
    SOLUTION_FILE = "D:\\Calc_Methods_2\\Lab3\\CrossScheme\\solution" + std::to_string(numOfEq) + ".txt";
    DATA_FILE = "D:\\Calc_Methods_2\\Lab3\\CrossScheme\\data" + std::to_string(numOfEq) + ".txt";
    INTERVAL_FILE = "D:\\Calc_Methods_2\\Lab3\\CrossScheme\\interval" + std::to_string(numOfEq) + ".txt";
}

// Решенние уравнений при разных sigma
template<typename Type>
void getWaveEquationSolution(std::size_t numOfEq, Type a, Type L, Type timeEnd,
std::size_t numOfXIntervals, std::size_t numOfTimeIntervals,  Type(*U0)(Type x), Type(*Ut0)(Type x), Type(*bound1)(Type t), Type(*bound2)(Type t), Type x0 = 0.0){ 
    std::string SOLUTION_FILE;
    std::string DATA_FILE;
    std::string INTERVAL_FILE;
    std::vector<Type> dataVec = {a, L, timeEnd, x0};
    std::vector<std::size_t> numOfIntervalsVec = {numOfXIntervals, numOfTimeIntervals};
    
    getFileNames(numOfEq, SOLUTION_FILE, DATA_FILE, INTERVAL_FILE);
    solveWaveEquation(SOLUTION_FILE, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2, x0);
    writeVectorFile(dataVec, DATA_FILE);
    writeVectorFile(numOfIntervalsVec, INTERVAL_FILE);
}

// Оценка сходимости при разных sigma при известном аналитическом решении
template<typename Type>
void getRealSpeedEstimate(std::size_t numOfEq, Type (*realSol)(Type t, Type x), Type a, Type L, Type timeEnd,
std::size_t numOfXIntervals, std::size_t numOfTimeIntervals, Type(*U0)(Type x), Type(*Ut0)(Type x), Type(*bound1)(Type t), Type(*bound2)(Type t)){ 
    std::string SOLUTION_FILE = "D:\\Calc_Methods_2\\Lab3\\speedEstCrossScheme\\speed" + std::to_string(numOfEq) + ".txt";
    getRealSpeedEstimateWaveEq(SOLUTION_FILE, realSol, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2);
}


template<typename Type>
void temp_main(){
    std::size_t numOfEq;
    Type a, L, timeEnd;
    std::size_t numOfXIntervals, numOfTimeIntervals;
    Type (*U0)(Type x) = nullptr;
    Type (*Ut0)(Type t) = nullptr;
    Type (*bound1)(Type t) = nullptr;
    Type (*bound2)(Type t) = nullptr;

    // Первый тест из методички
    numOfEq = 1;
    a = 1.0;

    L = 1.0;
    timeEnd = 5.0;

    U0 = U0_1;
    Ut0 = Ut0_1;
    bound1 = bound1_1;
    bound2 = bound2_1;

    numOfXIntervals = 50;
    numOfTimeIntervals = 500;
    //getWaveEquationSolution(numOfEq, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2);
    //getRealSpeedEstimate(numOfEq, realSolution1, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2);

    // Второй тест из методички
    numOfEq = 2;
    a = 1.0;

    L = 1.0;
    timeEnd = 5.0;

    U0 = U0_2;
    Ut0 = Ut0_2;
    bound1 = bound1_2;
    bound2 = bound2_2;

    numOfXIntervals = 100;
    numOfTimeIntervals = 500;
    //getWaveEquationSolution(numOfEq, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2);
    //getRealSpeedEstimate(numOfEq, realSolution2, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2);

    // Первый тест из доп. задач
    numOfEq = 3;
    a = 1.0;

    L = 4.0;
    timeEnd = 5.0;

    U0 = U0_3;
    Ut0 = Ut0_3;
    bound1 = bound1_3;
    bound2 = bound2_3;

    numOfXIntervals = 40;
    numOfTimeIntervals = 50;
    getWaveEquationSolution(numOfEq, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2, -2.0);
    //getRealSpeedEstimate(numOfEq, realSolution2, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2);

    // Второй тест из доп. задач
    numOfEq = 4;
    a = 1.0;

    L = 2.0;
    timeEnd = 5.0;

    U0 = U0_4;
    Ut0 = Ut0_4;
    bound1 = bound1_4;
    bound2 = bound2_4;

    numOfXIntervals = 200;
    numOfTimeIntervals = 500;
    //getWaveEquationSolution(numOfEq, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2, -1.0);
    //getRealSpeedEstimate(numOfEq, realSolution2, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2);

    // Второй тест из доп. задач
    numOfEq = 5;
    a = 1.0;

    L = 4.0 * M_PI;
    timeEnd = 30.0;

    U0 = U0_5;
    Ut0 = Ut0_5;
    bound1 = bound1_5;
    bound2 = bound2_5;

    numOfXIntervals = 100;
    numOfTimeIntervals = 1500;
    //getWaveEquationSolution(numOfEq, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2);
    //getRealSpeedEstimate(numOfEq, realSolution2, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2);


}

int main(){
    temp_main<double>();
    return 0;
}