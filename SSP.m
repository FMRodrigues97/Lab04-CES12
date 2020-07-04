BB_AVIS = csvread('SSP_Tests_Timed_BB_AVIS.dat');
DD_AVIS = csvread('SSP_Tests_Timed_DD_AVIS.dat');
PD_AVIS = csvread('SSP_Tests_Timed_PD_AVIS.dat');

BB_EVOD = csvread('SSP_Tests_Timed_BB_EVOD.dat');
DD_EVOD = csvread('SSP_Tests_Timed_DD_EVOD.dat');
PD_EVOD = csvread('SSP_Tests_Timed_PD_EVOD.dat');

BB_P3 = csvread('SSP_Tests_Timed_BB_P3.dat');
DD_P3 = csvread('SSP_Tests_Timed_DD_P3.dat');
PD_P3 = csvread('SSP_Tests_Timed_PD_P3.dat');

BB_P4 = csvread('SSP_Tests_Timed_BB_P4.dat');
DD_P4 = csvread('SSP_Tests_Timed_DD_P4.dat');
PD_P4 = csvread('SSP_Tests_Timed_PD_P4.dat');

BB_P5 = csvread('SSP_Tests_Timed_BB_P5.dat');
DD_P5 = csvread('SSP_Tests_Timed_DD_P5.dat');
PD_P5 = csvread('SSP_Tests_Timed_PD_P5.dat');

BB_RAND = csvread('SSP_Tests_Timed_BB_RAND.dat');
DD_RAND = csvread('SSP_Tests_Timed_DD_RAND.dat');
PD_RAND = csvread('SSP_Tests_Timed_PD_RAND.dat');

%% AVIS
% Figura 1
figure;
hold on;
grid on;
plot (BB_AVIS(:, 1), BB_AVIS(:, 2));
plot (DD_AVIS(:, 1), DD_AVIS(:, 2));
plot (PD_AVIS(:, 1), PD_AVIS(:, 2));
xlabel ('Tamanho do input');
ylabel ('Tempo de execução (s)');
title ('AVIS');
legend('BB', 'DD', 'PD');
print -dpng -r400 AVIS.png;

%% EVOD
% Figura 2
figure;
hold on;
grid on;
plot (BB_EVOD(:, 1), BB_EVOD(:, 2));
plot (DD_EVOD(:, 1), DD_EVOD(:, 2));
plot (PD_EVOD(:, 1), PD_EVOD(:, 2));
xlabel ('Tamanho do input');
ylabel ('Tempo de execução (s)');
title ('EVOD');
legend('BB', 'DD', 'PD');
print -dpng -r400 EVOD.png;

%% P3
% Figura 3
figure;
hold on;
grid on;
plot (BB_P3(:, 1), BB_P3(:, 2));
plot (DD_P3(:, 1), DD_P3(:, 2));
plot (PD_P3(:, 1), PD_P3(:, 2));
xlabel ('Tamanho do input');
ylabel ('Tempo de execução (s)');
title ('P3');
legend('BB', 'DD', 'PD');
print -dpng -r400 P3.png;

%% P4
% Figura 4
figure;
hold on;
grid on;
plot (BB_P4(:, 1), BB_P4(:, 2));
plot (DD_P4(:, 1), DD_P4(:, 2));
plot (PD_P4(:, 1), PD_P4(:, 2));
xlabel ('Tamanho do input');
ylabel ('Tempo de execução (s)');
title ('P4');
legend('BB', 'DD', 'PD');
print -dpng -r400 P4.png;

%% P5
% Figura 5
figure;
hold on;
grid on;
plot (BB_P5(:, 1), BB_P5(:, 2));
plot (DD_P5(:, 1), DD_P5(:, 2));
plot (PD_P5(:, 1), PD_P5(:, 2));
xlabel ('Tamanho do input');
ylabel ('Tempo de execução (s)');
title ('P5');
legend('BB', 'DD', 'PD');
print -dpng -r400 P5.png;

%% RAND
% Figura 6
figure;
hold on;
grid on;
plot (BB_RAND(:, 1), BB_RAND(:, 2));
plot (DD_RAND(:, 1), DD_RAND(:, 2));
plot (PD_RAND(:, 1), PD_RAND(:, 2));
xlabel ('Tamanho do input');
ylabel ('Tempo de execução (s)');
title ('RAND');
legend('BB', 'DD', 'PD');
print -dpng -r400 RAND.png;
