#include <TrocoSolver.h>

void TrocoSolverPD::solve(const std::vector<unsigned int> &denom,unsigned int value, std::vector<unsigned int> &coins) {

    std::vector<int> quant;
    std::vector<unsigned int> ultima;

    quant.resize(value + 1, -1);
    quant[0] = 0; 
    coins.resize(denom.size(), 0);
    ultima.resize(value + 1, 0);

    for (unsigned int cents = 1; cents <= value; cents++) {
        unsigned int quantProvisoria = -1;
        unsigned int ultProvisoria = 0;

        for (int j = 0; j < denom.size(); j++) {
            if (denom[j] > cents) 
                continue;

            if (quant[cents - denom[j]] + 1 < quantProvisoria) {
                quantProvisoria = quant[cents - denom[j]] + 1;
                ultProvisoria = j;
            }
        }

        quant[cents] = quantProvisoria;
        ultima[cents] = ultProvisoria;
    }

    // Determinar as moedas do troco
    while(value > 0) {

        if (quant[value] == -1)
            break;
            
        coins[ultima[value]]++;
        value -= denom[ultima[value]];
    }

    if (value == 0)
        return;

    // fills a dummy answer with 2 coins of each denomination    
    coins.resize(denom.size(),2);
 
}//solve