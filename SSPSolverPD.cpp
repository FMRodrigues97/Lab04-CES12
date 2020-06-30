#include <SubsetSumSolver.h>

bool SSPSolverPD::solve(const std::vector< long> &input, long value, std::vector< char> &output) {

    long n = input.size();
    bool solucionavel;

    Knapsack01() {
        for (int i = 0; i <= c; i++)
            B[0][i] = 0;
        
        for (int k = 1; k <= n; k++)
            for (i = 0; i <= c; i++)
                if (w[k] > i)
                    B[k][i] = B[k - 1][i];
                else 
                    B[k][i] = max{ B[k - 1][i], B[k - 1][i - w[k]] + p[k] };

        return B[n][c];
     }

    output.resize(input.size());
    return solucionavel;
    
}

bool SSPSolverPD::solve(const std::vector< long> &input, long value, std::vector< char> &output) {

    long w = 0, i = 0;
    bool encontrouSol = false;
    std::vector<std::vector<long>> tabela;
    output.resize(input.size());
    tabela.resize(input.size());

    long index = 0,n = input.size();

    while (index < n)
        output[index++] = false;

    for (int i=input.size() - 1;i >= 0; i--)
        tabela[i].resize(value+1,0);

    i = 0;
    for(long n = input.size(); i < n && (!encontrouSol); i++) {
        w = 0;
        for(; w <= value && (!encontrouSol); w++) {
            if (input[i]<=w) {
                if (i==0)
                    tabela[i][w] = input[i];

                else if (input[i] + tabela[i-1][w-input[i]] >= tabela[i-1][w])
                    tabela[i][w] = input[i] + tabela[i-1][w-input[i]];
                else
                    tabela[i][w] = tabela[i-1][w];
                
            }
            else
                if (i != 0)
                    tabela[i][w] = tabela[i-1][w];
                else
                    tabela[i][w] = 0;

                // tabela[i][w] = (i!=0?tabela[i-1][w]:0);

            if(tabela[i][w] == value)
                encontrouSol = true;
        }
    }

    i--;
    w--;

    if (encontrouSol)
        while(i >= 0 && w > 0) {
            if (i > 0) {
                if (tabela[i][w] != tabela[i-1][w]) {
                    output[i] = true;
                    w -= input[i];
                }
                i--;
            }
            else {
               if (tabela[i][w] == input[i]) {
                    output[i] = true;
                    w -= input[i];
                }
                i--; 
            }
        }
    return encontrouSol;
}