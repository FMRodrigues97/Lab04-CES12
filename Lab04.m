DC = csvread('troco_DC40.csv');
GR = csvread('troco_GR_BR200.csv');
PD = csvread('troco_PD_BR200.csv');

%% Divis�o e Conquista (DC)

% Figura 1
figure;
plot (DC(1:40, 1), DC(1:40, 2));
xlabel ('Valor do Troco');
ylabel ('Tempo de execu��o (ms)');
title ('Tempo de execu��o de acordo com o valor do troco para o m�todo DC');
grid on;

% Figura 2
figure;
plot (DC(1:40, 1), DC(1:40, 3));
xlabel ('Valor do Troco');
ylabel ('N�mero de Moedas');
title ('N�mero de moedas de acordo com o valor do troco para o m�todo DC');
grid on;


%% M�todo Greedy (GR)

% Figura 3
figure;
plot (GR(1:200, 1), GR(1:200, 2));
xlabel ('Valor do Troco');
ylabel ('Tempo de execu��o (ms)');
title ('Tempo de execu��o de acordo com o valor do troco para o m�todo GR');
grid on;

% Figura 4
figure;
plot (GR(1:200, 1), GR(1:200, 3));
xlabel ('Valor do Troco');
ylabel ('N�mero de Moedas');
title ('N�mero de moedas de acordo com o valor do troco para o m�todo GR');
grid on;

%% Programa��o Din�mica (PD)

% Figura 5
figure;
plot (PD(1:200, 1), PD(1:200, 2));
xlabel ('Valor do Troco');
ylabel ('Tempo de execu��o (ms)');
title ('Tempo de execu��o de acordo com o valor do troco para o m�todo PD');
grid on;

% Figura 6
figure;
plot (PD(1:200, 1), PD(1:200, 3));
xlabel ('Valor do Troco');
ylabel ('N�mero de Moedas');
title ('N�mero de moedas de acordo com o valor do troco para o m�todo PD');
grid on;