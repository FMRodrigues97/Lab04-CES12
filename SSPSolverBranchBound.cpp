#include <SubsetSumSolver.h>
#include <math.h>
#include <vector>

std::vector<long> SSPSolverBranchBound::subsetSums (const std::vector<long> &input, long l, long r, long soma, std::vector<long> subsomas) {  

    if (l > r) {
        subsomas.push_back(soma);
        return subsomas;
    }

    //i++;

    // Subset including input[l]
    subsetSums(input, l+1, r, soma + input[l], subsomas);

    // Subset excluding input[l]
    subsetSums(input, l+1, r, soma, subsomas);
}

std::vector<char> SSPSolverBranchBound::binario (long &input) {

    std::vector<long> bin;
    std::vector<char> I;
    long i = 0, aux = 0;

    while (input >= 1) {
        if (input % 2 == 0)
            bin[aux] = 0;
        else
            bin[aux] = 1;

        input = (long) input / 2;
        aux++;
    }

    // Inverter bin
    aux = 0;
    long n = bin.size();
    for (i = 0; i < bin.size()/2; i++){
        aux = bin[i];
        bin[i] = bin[n-1 - i];
        bin[n-1 - i] = aux;
    }

    for (aux = 0; aux < bin.size(); aux++)
        I[aux] = (char) bin[aux];

    return I;
}

bool SSPSolverBranchBound::solve (const std::vector<long> &input, long value, std::vector<char> &output) {
    
    bool solucionavel = false;
    long i = 0, j = 0, k = 0, indice = 0, n = input.size();

    std::vector<char> I, J;
    std::vector<long> input1, input2, subsomas1, subsomas2, sub1, sub2;

    I.resize(1, 0);
    J.resize(1, 0);

    input1.resize((long) (input.size() / 2));
    input2.resize(input.size() - input1.size());

    subsomas1.resize((long) pow(2, input1.size()));
    subsomas2.resize((long) pow(2, input2.size()));
    output.resize(input.size());

    while (indice < n)
        output[indice++] = false;
    
    // Dividir o vetor na metade
    for (indice = 0; indice < input1.size(); indice++)
        input1[indice] = input[indice];

    for (indice = 0; indice < input2.size(); indice++)
        input2[indice] = input[indice + input1.size()];

    // Calcular as somas de todos os subconjuntos da primeira parte e guardar os resultados
    for (indice = 0; indice < subsomas1.size(); indice++){
        subsomas1[indice] = 0;
        sub1[indice] = 0;
    }

    for (indice = 0; indice < subsomas2.size(); indice++){
        subsomas2[indice] = 0;
        sub2[indice] = 0;        
    }

    subsomas1 = subsetSums (input1, input1.size() - 1, 0, 0, sub1);
    subsomas2 = subsetSums (input2, input2.size() - 1, 0, 0, sub2);

    // Ordenar os resultados

    // Calcular uma a uma a soma de subconjuntos da segunda parte, buscar a diferença a W nos resultados da primeira parte
    for (i = 0; i < subsomas1.size(); i++)
        for (j = 0; j < subsomas2.size(); j++)
            if (value - subsomas2[j] == subsomas1[i]) {
                for (long a = 0; a < binario(i).size(); a++)
                    I.push_back(binario(i)[a]);

                for (long b = 0; b < binario(j).size(); b++)
                    J.push_back(binario(j)[b]);
            }

    for (k = 1; k < J.size(); k++) {
        I.push_back(J[k]);
    }

    for (i = 1; i < I.size(); i++) {
        if (I[i] == '1')
            output[i-1] = true;
            solucionavel = true;
    }

    return solucionavel;
}

/*#include <SubsetSumSolver.h>
#include<iostream>

bool SSPSolverBranchBound::solve(const std::vector<long> &input,long value, std::vector<char> &output) {

    output.resize(input.size());
    
    long i = -1;
    bool encontrouSol = false;

    long index = 0, n = input.size();
    index = 0;
    while (index < n)
        output[index++] = false;
    index = 0;

    encontrouSol = SSPSolverBranchBound::recursiveBranchBound(input, i, value, output);

    return encontrouSol;
}

bool SSPSolverBranchBound::recursiveBranchBound(const std::vector<long> &input,long i, long value, std::vector<char> &output) {
    i++;
    bool encontrouSol1 = false, encontrouSol2 = false;

    if (i == input.size())
        return (value == 0);

    else if (value <= 0)
        return (value == 0);

    std::vector<char> output1(output), output2(output);
    encontrouSol1 = SSPSolverBranchBound::recursiveBranchBound(input, i, value - input[i], output1);

    if (!encontrouSol1) {
        encontrouSol2 = SSPSolverBranchBound::recursiveBranchBound(input, i, value, output2);
        if(encontrouSol2)
            output = output2;
    }
    else {
        output = output1;
        output[i] = true;
    }
    
    return (encontrouSol1 || encontrouSol2);
}*/
