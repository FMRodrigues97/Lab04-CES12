#include <TrocoSolver.h>

void TrocoSolverDivConquer::solve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) {

    coins.resize(denom.size(), 0);
    recursivecalls = -1;
    
    int quant = TrocoRecursivo(denom, denom.size() - 1, value, coins);

    if (quant >= 0) 
        return;

    // fills a dummy answer with 1 coin of each denomination    
    coins.resize(denom.size(), 1);
    
} //solve

int TrocoSolverDivConquer::TrocoRecursivo(const std::vector<unsigned int> &denom, int ultima, unsigned int value, std::vector<unsigned int> &coinsProvisoria){

    std::vector<unsigned int> coins1(coinsProvisoria);
    std::vector<unsigned int> coins2(coinsProvisoria);

    int aux1 = -1;
    int aux2 = -1;

    recursivecalls++;

    if (ultima < 0 or value < 0)
        return -1;

    if (value == 0)
        return 0;

    coins1[ultima]++;

    if (value >= denom[ultima])
        aux1 = TrocoSolverDivConquer::TrocoRecursivo(denom, ultima, value - denom[ultima], coins1);

    aux2 = TrocoSolverDivConquer::TrocoRecursivo(denom, ultima - 1, value, coins2);

    if ((aux1 < aux2 or aux2 == -1) and aux1 != -1) {
        coinsProvisoria = coins1;
        return aux1 + 1;
    }
    else {
        coinsProvisoria = coins2;
        return aux2;
    }

} //TrocoRecursivo