#ifndef ACC_BIBLIOTECA_H_INCLUDED
#define ACC_BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stddef.h>
#include <stdbool.h>

/*
    Cada uma das funções aqui estão definidas na mesma ordem que o Acc.c
    Uma nota importante, por algum motivo (não sei qual) o scruct definido no .c não valia para o .h e algumas
    definidas aqui não valiam para o .c, portanto tem algumas definições que estão duplicadas que o compilador aceitou.
*/
void show_menu();

void clear_menu();

bool check_exit(char input[]);

void *ch0_henlo();
void ch0_callhenlo(char*(*func)());

void ch1_apresentese(int ano_atual);

double ch2_A_sum(int *Valor1, int *Valor2);
double ch2_B_multiply(int *Valor1, int *Valor2);
double ch2_C_pow(int *Valor1, int *Valor2);
double ch2_D_hypo(int *Valor1, int *Valor2);
double ch2_E_sindi(int *Valor1, int *Valor2);
double ch2_F_mod(int *Valor1, int *Valor2);

struct temperatura
{
    double Grau;
    char Unidade[20];
}
typedef temperatura_t;

void ch3_temperatura(double t_fah, temperatura_t **t_out);

int ch4_fatorial(int input_Tofatorial);

void ch5_media();

int ch6n7_criarmatriz(int Linha, int Coluna);

void ch6_malloctabuada(int TAMANHO_MATRIZ);

void ch7_operacaomatriz(int Linha, int Coluna);

void ch8_cem_a_um();

void ch9_countnreplace(char *input_String, char char_Contar);

void ch10_returnascii();

#endif //  ACC_BIBLIOTECA_H_INCLUDED
