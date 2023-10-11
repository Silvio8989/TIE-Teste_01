clear all; close all; clc; more off;

R1 = 100;
R2 = 156;
R3 = 220;
R4 = 280;
R5 = 386;
R6 = 430;
R7 = 470;
R8 = 560;

global R = [R1 R2 R3 R4 R5 R6 R7 R8];

R_inicio = R;

global M = [95.6 145.3 200 248 324 353 386 437];

function Req = calc_req(n)
  global R;
  Rb = 0;
  for idx = 1:8
    if idx == n
      Ra = R(idx);
    else
      Rb = Rb + R(idx);
    endif
  endfor
  Req = 1/((1/Ra)+(1/Rb));
endfunction

function [Req, Ra, Rb] = calc_req_pula(Rin,pula,idxR)
  Rin2 = shift(Rin,-(idxR-1));
  Rb = 0;
  Ra = 0;
  for idx = 1:8
    if idx <= (pula+1)
      Ra = Ra + Rin2(idx);
    else
      Rb = Rb + Rin2(idx);
    endif
  endfor
  Req = 1/((1/Ra)+(1/Rb));
endfunction


function R_calc = calc_Rcalc()
  for elet = 1:8
    R_calc(elet) = calc_req(elet);
  endfor
endfunction

function erro = calc_erro(R_calc)
  global M;
  erro_vec = M - R_calc;
  erro = norm(erro_vec);
endfunction

Rcalc = calc_Rcalc()
erro_ant = calc_erro(Rcalc)
erro_it_ant = erro_ant;

passo = 1e-2;
for it = 1:100
  for elet = 1:8
    for itt = 1:100
      R(elet) = R(elet) + passo;
      Rcalc = calc_Rcalc();
      erro = calc_erro(Rcalc);
      if erro > erro_ant
        passo = -passo;
      endif
      erro_ant = erro;
    endfor
  endfor
  disp(erro);
  if(erro_it_ant-erro<0.001)
    break;
  endif
  erro_it_ant = erro;
endfor

function Vout = calc_tab(pula)
  global R;
  Iin = 0.5;
  Vout = zeros(8,8);
  for idxR = 1:8
    [Req, Ra, Rb] = calc_req_pula(R,pula,idxR);
    V = Req * Iin;
    Ia = V/Ra;
    Ib = V/Rb;
    Rbkp = shift(R,-(idxR-1));
    Vref = 0;
    for p = (pula+1):-1:1
      Vm(p) = Ia*Rbkp(p)+Vref;
      Vref = Vm(p);
    endfor
    Vm(pula+2) = 0;
    Vref = 0;
    for p = (pula+2):7
      Vm(p+1) = Ib*Rbkp(p)+Vref;
      Vref = Vm(p+1);
    endfor
    Vm2 = shift(Vm,(idxR-1));
    Vout(:,idxR) = Vm2';
  endfor
  %disp(Vout);
endfunction

Req = calc_req(2);
Rcalc = calc_Rcalc();
erro_depois = calc_erro(Rcalc)

disp('');
disp("Valores dos resistores isolados [R_inicio; R]")
disp([R_inicio; R]);

disp('');
disp("Valores entre os eletrodos na placa (associacao) [M; Rcalc]")
disp([M; Rcalc])

disp('');
disp("Tabelas (pula 0)")
disp(calc_tab(0));

disp('');
disp("Tabelas (pula 1)")
disp(calc_tab(1));

disp('');
disp("Tabelas (pula 2)")
disp(calc_tab(2));

disp('');
disp("Tabelas (pula 3)")
disp(calc_tab(3));


