#include <SubsetSumSolver.h>
#include<iostream>

bool SSPSolverBranchBound::solve(const std::vector<long> &input,long value, std::vector<char> &output) {

    output.resize(input.size());

    long i = -1, indice = 0, n = input.size();
    bool solucionavel = false;

    while (indice < n)
        output[indice++] = false;

    solucionavel = SSPSolverBranchBound::backtracking(input, i, value, output);

    return solucionavel;
}

bool SSPSolverBranchBound::backtracking(const std::vector<long> &input,long i, long value, std::vector<char> &output) {

    i++;
    bool solucionavel1 = false, solucionavel2 = false;

    if (i == input.size() or value <= 0)
        return (value == 0);

    std::vector<char> output1(output), output2(output);

    solucionavel1 = SSPSolverBranchBound::backtracking(input, i, value - input[i], output1);

    if (!solucionavel1) {
        solucionavel2 = SSPSolverBranchBound::backtracking(input, i, value, output2);
        if (solucionavel2)
            output = output2;
    }

    else {
        output = output1;
        output[i] = true;
    }

    return (solucionavel1 or solucionavel2);
}
