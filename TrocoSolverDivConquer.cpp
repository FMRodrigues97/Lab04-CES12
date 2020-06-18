#include <TrocoSolver.h>
#include <iostream>

int TrocoSolverDivConquer::DCMakeChange(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins, std::vector<unsigned int> &ultima) {

    recursivecalls++;

    if (value == 0)
        return 0;

    int q = value; // Solução óbvia com somente moedas de 1 centavo
    int aux;

    for (int i = 0; i < denom.size(); i++) {
        if (denom[i] > value)
            continue; // Essa moeda não serve

        aux = q;
        q = std::min (q, 1 + DCMakeChange(denom, value - denom[i], coins, ultima));

        if (aux > q)
            ultima[value] = i;

    }

    return q; // Quantidade ótima de moedas para troco

}

void TrocoSolverDivConquer::solve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) {

    recursivecalls = 0;

    std::vector<unsigned int> ultima;

    coins.resize(denom.size(),0);
    ultima.resize(value + 1, 0);
    ultima[0] = 0;

    DCMakeChange (denom, value, coins, ultima);

    while (value > 0){
        coins[ultima[value]]++;
        value -= denom[ultima[value]];
    }
    
} //solve