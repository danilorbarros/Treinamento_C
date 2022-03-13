/**
* @file Accenture_Exerc�cio_3.c
* @author Danilo Raposo Barros - culpinharbarros@gmail.com
* @date 11-01-2021 23:34:00
* @brief Esse c�digo � um menu que agrega diversas fun��es que realizam diversos outros processos.
*/

// Inicializa��o do arquivo de fun��es predefinido
#include"Acc_Biblioteca.h"

// Defini��o de constantes para apresenta��o
#define CODE "Main Menu"
#define AUTOR "Danilo Raposo Barros"
#define EMAIL "culpinharbarros@gmail.com"

// Defini��o de constantes para o funcionamento do c�digo
#define INPUT_LENGHT 4
#define ANO 2022
#define TAMANHO_MATRIZ 10

// In�cio do c�digo
int main(int argcg, char * argv[])
{
        /*
            Inicializa��o de vari�veis para o menu do c�digo
            input_Menu armazena o tamanho da string (4 porque a gente t� trabalhando de 1 a 10 com a possibidade de um exit)
            loop_Menu armazena se vai entrar no loop do menu ou n�o
        */
        char input_Menu[INPUT_LENGHT];
        int loop_Menu = 1;
        time_t t;

        // Inicicializando a data atual e fazendo a apresenta��o do c�digo
        time(&t);
        printf("\n[%s]"
               "\nDesenvolvido por: %s. <11-01-2021 23:37:20>\n"
               "Email: %s. %s \n", CODE, AUTOR, EMAIL,ctime(&t));

        // Chamada da fun��o que limpa a tela
        clear_menu();

        while (loop_Menu == 1)
        {
            // Op��es do Menu
            show_menu();
            scanf("%s", input_Menu);
            printf("\n");

            /*
                is_Exit � o que armazena se o input do usu�rio � realmente exit
                len_Input � uma vari�vel que armazena o tamanho, para evitar que qualquer palavra com 4 caracteres valide o if
            */

            bool is_Exit = !check_exit(input_Menu);
            int len_Input = strlen(input_Menu);

            // Inicia as condi��es para cada uma das op��es do menu
            switch(input_Menu[0])
            {
                /*
                    Op��o 0
                    Esta op��o printa helloworld
                */
                case '0':
                {
                    // Chamada da fun��o que chama o hello world
                    ch0_callhenlo(ch0_henlo());
                    break;
                }
                /*
                    Op��o 1 e 10
                */
                case '1':
                {
                    /*
                        Op��o 1)
                        Esta op��o recebe como par�metro e a partir de inputs do usu�rio printa:
                        Nome completo, Idade e Idade + caracateres do Nome completo.
                    */
                    if (input_Menu[1] != '0' && len_Input < 2)
                    {
                        // Chamada da fun��o de apresenta��o
                        ch1_apresentese(ANO);
                    }
                    /*
                        Op��o 10)
                        Esta op��o recebe como input um caractere do usu�rio e printa:
                        O caracter digitado e seu ASCII correspondente.
                    */
                    else if (input_Menu[1] == '0')
                    {
                        // Chamada da fun��o returnaacii
                        ch10_returnascii();
                    }
                    else
                    {
                        printf("\nOpcao invalida.\n");
                    }
                    break;
                }
                /*
                    Op��o 2
                    Esta op��o recebe dois n�meros como par�metro e printa:
                    A)A + B, B)A * B ** 2, C)A ** 2, D)Hipotenusa, E)Sin(A-B), F)|A|.
                */
                case '2':
                {
                    int input_FValue;
                    int input_SValue;
                    int contador_1;
                    int operacoes = 6;
                    double result;

                    // Inicializando os ponteiros apontando para o Null (olhando pra cima)
                    int *pFValue = NULL;
                    int *pSValue = NULL;

                    /*
                        Aqui t� sendo criado um ponteiro para cada uma das fun��es criadas, sendo elas as quest�es de A a F.
                        Estas foram definidas na Acc_Biblioteca junto com as outras fun��es.
                    */
                    double (*ch2_func[])(int, int) = {ch2_A_sum, ch2_B_multiply, ch2_C_pow, ch2_D_hypo, ch2_E_sindi, ch2_F_mod};

                    printf("Insira um valor:");
                    scanf("%d", &input_FValue);
                    printf("Insira outro valor:");
                    scanf("%d", &input_SValue);

                    // Fazendo com que os ponteiros criados apontem para o endere�o alocado para os inputs (olhando para x�cara)
                    pFValue = &input_FValue;
                    pSValue = &input_SValue;

                    for(contador_1 = 0; contador_1< operacoes; contador_1++)
                    {
                        // Chamada da fun��o a depender do contador
                        result = (*ch2_func[contador_1])(pFValue, pSValue);
                        printf("%lf.\n\n", result);
                    }

                    break;
                }
                /*
                    Op��o 3
                    Esta op��o recebe um n�mero double como par�metro e printa:
                    A temperatura em Fahrenheit convertida em Celcius
                */
                case '3':
                {
                    double input_Temperature;

                    // Inicializando o ponteiro apontando para o Null (olhando pra cima)
                    temperatura_t *t_Celcius = NULL;

                    // Obten��o da temperatura informada
                    printf("Insira aqui uma temperatura em Fahrenheit: ");
                    scanf("%lf", &input_Temperature);

                    // Chamada da fun��o de convers�o
                    ch3_temperatura(input_Temperature, &t_Celcius);

                    printf("A temperatura informada convertida para %s e: %lf\n", t_Celcius->Unidade,t_Celcius->Grau);

                    // Liberando o Malloc
                    free(t_Celcius);

                    break;
                }
                /*
                    Op��o 4
                    Esta op��o recebe um n�mero inteiro como par�metro e printa:
                    O fatorial deste n�mero.
                */
                case '4':
                {
                    int input_Tofatorial;
                    int result;

                    // Obten��o do valor informado
                    printf("Calcular o fatorial de: ");
                    scanf("%d", &input_Tofatorial);

                    // Chamada da fun��o que calcula o fatorial
                    result = ch4_fatorial(input_Tofatorial);

                    if (result != 0)
                    {
                        printf("O fatorial de %d e %d.\n", input_Tofatorial, result);
                    }

                    break;
                }
                /*
                    Op��o 5
                    Esta op��o recebe dez strings num�ricas como par�metro e printa:
                    O vetor e a m�dia correndente ao mesmo.
                */
                case '5':
                {
                    // Chamada da fun��o que solicita input e calcula sua m�dia
                    ch5_media();
                    break;
                }
                /*
                    Op��o 6
                    Esta op��o coloca o tamanho da matriz como par�metro e printa:
                    A tabuada de 1 a 10 sem a tabuada de 5.
                */
                case '6':
                {
                    // Chamada da fun��o que realiza a cria��o e print da tabuada
                    ch6_malloctabuada(TAMANHO_MATRIZ);
                    break;
                }
                /*
                    Op��o 7
                    Esta op��o coloca o tamanho da matriz como par�metro e printa:
                    Diferen�a entre a m�dia dos elementos das colunas pares, m�dia dos elementos das linhas �mpares.
                */
                case '7':
                {
                    int Linha = 5;
                    int Coluna = 3;

                    // Ch
                    ch7_operacaomatriz(Linha, Coluna);

                    break;
                }
                /*
                    Op��o 8
                    Esta op��o n�o recebe par�metro e printa:
                    Os n�meros de 100 a 1.
                */
                case '8':
                {
                    // Chamada da fun��o que realiza a contagem
                    ch8_cem_a_um();
                    break;
                }
                /*
                    Op��o 9
                    Esta op��o recebe uma String(input) e um char como par�metro e printa:
                    O n�mero de caracteres na string e a mesma modificada.
                */
                case '9':
                {
                    char char_Contar = 'a';
                    char input_String[50];

                    // Inicializando os ponteiros apontando para o Null (olhando pra cima)
                    char *pString = NULL;

                    // Obten��o dos dados para se trabalhar
                    printf("Insira aqui uma string: ");
                    scanf("%s", &input_String);

                    // Fazendo com que o ponteiro criado aponte para o endere�o alocado para o input (olhando para x�cara)
                    pString = &input_String;

                    // Chamada da fun��o que realiza o replacement
                    ch9_countnreplace(pString, char_Contar);

                    break;
                }
                default:
                {
                    if (is_Exit == 0)
                    {
                        /*
                            Seta vari�vel do loop como False
                            Inicia a vari�vel contadora para a sa�da do c�digo
                        */
                        int count_Exit = 10;

                        while (count_Exit >= 0)
                        {
                            // Printa o valor do contador
                            printf("%d\n", count_Exit);

                            /*
                                Inicia a inst�ncia start_time a partir do clock, proveniente de time.h
                                E em seguida faz um while que vai contar n segundos
                            */
                            clock_t start_time = clock();
                            while (clock() < start_time + 1000);

                            // N�o gosto de usar o -= porque acho n�o intuitivo
                            count_Exit = count_Exit - 1;
                        }

                        printf("\nFim!\n");
                        loop_Menu = 0;
                    }
                    else
                    {
                        printf("\nOpcao invalida.\n");
                    }
                    break;
                }
            }
            clear_menu();
        }
    return 0;
}
