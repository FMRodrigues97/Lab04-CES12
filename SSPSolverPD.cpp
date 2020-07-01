#include <SubsetSumSolver.h>

bool SSPSolverPD::solve(const std::vector<long> &input, long value, std::vector<char> &output) {

    long i = 0, k = 0, indice = 0, n = input.size();
    bool solucionavel = false;
    std::vector<std::vector<long>> B;
    B.resize(input.size());
    output.resize(input.size());

    while (indice < n)
        output[indice++] = false;

    for (i = input.size() - 1; i >= 0; i--)
        B[i].resize(value + 1, 0); // Nenhum item é considerado

    for (k = 0; k < n; k++) { // Incremento nos itens
        for (i = 0; i <= value; i++) { // Incremento na capacidade
            if (input[k] > i) {
                if (k == 0)
                    B[k][i] = 0;
                else
                    B[k][i] = B[k-1][i];
            }

            else {
                if (k != 0){
                    if (B[k-1][i-input[k]] + input[k] > B[k-1][i])
                        B[k][i] = B[k-1][i-input[k]] + input[k];

                    if (B[k-1][i] >= B[k-1][i-input[k]] + input[k])
                        B[k][i] = B[k-1][i];
                }
                
                if (k == 0)
                    B[k][i] = input[k];
            }

            if (B[k][i] == value)
                solucionavel = true;
        }
    }

    k--;
    i--;

    if (solucionavel){
        while (k >= 0 && i > 0) {
            if (k > 0) {
                if (B[k][i] != B[k-1][i]) {
                    output[k] = true;
                    i -= input[k];
                }
            }

            else {
                if (B[k][i] == input[k]) {
                        output[k] = true;
                        i -= input[k];
                    }
            }

            k--;
        }
    }

    return solucionavel;
}
