DC = csvread('troco_DC40.csv');
GR = csvread('troco_GR_BR200.csv');
PD = csvread('troco_PD_BR200.csv');

GRL = csvread('troco_GR_GRLoses.csv');
PDL = csvread('troco_PD_GRLoses.csv');

%% Divis�o e Conquista (DC)

% Figura 1
figure;
plot (DC(1:40, 1), DC(1:40, 2));
xlabel ('Valor do Troco');
ylabel ('Tempo de execu��o (ms)');
title ('Tempo de execu��o para o m�todo DC');
grid on;
print -dpng -r400 1.png;

% Figura 2
figure;
plot (DC(1:40, 1), DC(1:40, 3));
xlabel ('Valor do Troco');
ylabel ('N�mero de Moedas');
title ('N�mero de moedas para o m�todo DC');
grid on;
print -dpng -r400 2.png;

%% M�todo Greedy (GR)

% Figura 3
figure;
plot (GR(1:200, 1), GR(1:200, 2));
xlabel ('Valor do Troco');
ylabel ('Tempo de execu��o (ms)');
title ('Tempo de execu��o para o m�todo GR');
grid on;
print -dpng -r400 3.png;

% Figura 4
figure;
plot (GR(1:200, 1), GR(1:200, 3));
xlabel ('Valor do Troco');
ylabel ('N�mero de Moedas');
title ('N�mero de moedas para o m�todo GR');
grid on;
print -dpng -r400 4.png;

%% Programa��o Din�mica (PD)

% Figura 5
figure;
plot (PD(1:200, 1), PD(1:200, 2));
xlabel ('Valor do Troco');
ylabel ('Tempo de execu��o (ms)');
title ('Tempo de execu��o para o m�todo PD');
grid on;
print -dpng -r400 5.png;

% Figura 6
figure;
plot (PD(1:200, 1), PD(1:200, 3));
xlabel ('Valor do Troco');
ylabel ('N�mero de Moedas');
title ('N�mero de moedas para o m�todo PD');
grid on;
print -dpng -r400 6.png;

%% Comparativo GR e PD (loses)

% Figura 7
figure;
hold on;
plot (GRL(1:200, 1), GRL(1:200, 3), 'black');
plot (PDL(1:200, 1), PDL(1:200, 3), 'r--');
xlabel ('Valor do Troco');
ylabel ('N�mero de Moedas');
title ('Comparativo GR e PD');
legend ('Greedy', 'Programa��o Din�mica');
grid on;
print -dpng -r400 7.png;

%% Recurs�o

figure;
plot (DC(1:40, 1), DC(1:40, 4));
xlabel ('Valor do Troco');
ylabel ('Chamadas Recursivas');
title ('Chamadas Recursivas para o m�todo DC');
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
ylabel ('Tempo de Execu��o (ms)');
title ('Comparativo GR e PD');
legend ('GR', 'GRL', 'PD', 'PDL');
grid on;
print -dpng -r400 9.png;
