DC = csvread('troco_DC40.csv');
GR = csvread('troco_GR_BR200.csv');
PD = csvread('troco_PD_BR200.csv');

GRL = csvread('troco_GR_GRLoses.csv');
PDL = csvread('troco_PD_GRLoses.csv');

%% Divisão e Conquista (DC)

% Figura 1
figure;
plot (DC(1:40, 1), DC(1:40, 2));
xlabel ('Valor do Troco');
ylabel ('Tempo de execução (ms)');
title ('Tempo de execução para o método DC');
grid on;
print -dpng -r400 1.png;

% Figura 2
figure;
plot (DC(1:40, 1), DC(1:40, 3));
xlabel ('Valor do Troco');
ylabel ('Número de Moedas');
title ('Número de moedas para o método DC');
grid on;
print -dpng -r400 2.png;

%% Método Greedy (GR)

% Figura 3
figure;
plot (GR(1:200, 1), GR(1:200, 2));
xlabel ('Valor do Troco');
ylabel ('Tempo de execução (ms)');
title ('Tempo de execução para o método GR');
grid on;
print -dpng -r400 3.png;

% Figura 4
figure;
plot (GR(1:200, 1), GR(1:200, 3));
xlabel ('Valor do Troco');
ylabel ('Número de Moedas');
title ('Número de moedas para o método GR');
grid on;
print -dpng -r400 4.png;

%% Programação Dinâmica (PD)

% Figura 5
figure;
plot (PD(1:200, 1), PD(1:200, 2));
xlabel ('Valor do Troco');
ylabel ('Tempo de execução (ms)');
title ('Tempo de execução para o método PD');
grid on;
print -dpng -r400 5.png;

% Figura 6
figure;
plot (PD(1:200, 1), PD(1:200, 3));
xlabel ('Valor do Troco');
ylabel ('Número de Moedas');
title ('Número de moedas para o método PD');
grid on;
print -dpng -r400 6.png;

%% Comparativo GR e PD (loses)

% Figura 7
figure;
hold on;
plot (GRL(1:200, 1), GRL(1:200, 3), 'black');
plot (PDL(1:200, 1), PDL(1:200, 3), 'r--');
xlabel ('Valor do Troco');
ylabel ('Número de Moedas');
title ('Comparativo GR e PD');
legend ('Greedy', 'Programação Dinâmica');
grid on;
print -dpng -r400 7.png;

%% Recursão

figure;
plot (DC(1:40, 1), DC(1:40, 4));
xlabel ('Valor do Troco');
ylabel ('Chamadas Recursivas');
title ('Chamadas Recursivas para o método DC');
grid on;
print -dpng -r400 8.png;

%% Comparativo

figure;
hold on;
plot (GR(1:200, 1), GR(1:200, 2));
plot (GRL(1:200, 1), GRL(1:200, 2));
plot (PD(1:200, 1), PD(1:200, 2));
plot (PDL(1:200, 1), PDL(1:200, 2));
xlabel ('Valor do Troco');
ylabel ('Tempo de Execução (ms)');
title ('Comparativo GR e PD');
legend ('GR', 'GRL', 'PD', 'PDL');
grid on;
print -dpng -r400 9.png;
