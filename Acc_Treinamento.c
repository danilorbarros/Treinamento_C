/**
* @file Accenture_Exercício_3.c
* @author Danilo Raposo Barros - culpinharbarros@gmail.com
* @date 11-01-2021 23:34:00
* @brief Esse código é um menu que agrega diversas funções que realizam diversos outros processos.
*/

// Inicialização do arquivo de funções predefinido
#include"Acc_Biblioteca.h"

// Definição de constantes para apresentação
#define CODE "Main Menu"
#define AUTOR "Danilo Raposo Barros"
#define EMAIL "culpinharbarros@gmail.com"

// Definição de constantes para o funcionamento do código
#define INPUT_LENGHT 4
#define ANO 2022
#define TAMANHO_MATRIZ 10

// Início do código
int main(int argcg, char * argv[])
{
        /*
            Inicialização de variáveis para o menu do código
            input_Menu armazena o tamanho da string (4 porque a gente tá trabalhando de 1 a 10 com a possibidade de um exit)
            loop_Menu armazena se vai entrar no loop do menu ou não
        */
        char input_Menu[INPUT_LENGHT];
        int loop_Menu = 1;
        time_t t;

        // Inicicializando a data atual e fazendo a apresentação do código
        time(&t);
        printf("\n[%s]"
               "\nDesenvolvido por: %s. <11-01-2021 23:37:20>\n"
               "Email: %s. %s \n", CODE, AUTOR, EMAIL,ctime(&t));

        // Chamada da função que limpa a tela
        clear_menu();

        while (loop_Menu == 1)
        {
            // Opções do Menu
            show_menu();
            scanf("%s", input_Menu);
            printf("\n");

            /*
                is_Exit é o que armazena se o input do usuário é realmente exit
                len_Input é uma variável que armazena o tamanho, para evitar que qualquer palavra com 4 caracteres valide o if
            */

            bool is_Exit = !check_exit(input_Menu);
            int len_Input = strlen(input_Menu);

            // Inicia as condições para cada uma das opções do menu
            switch(input_Menu[0])
            {
                /*
                    Opção 0
                    Esta opção printa helloworld
                */
                case '0':
                {
                    // Chamada da função que chama o hello world
                    ch0_callhenlo(ch0_henlo());
                    break;
                }
                /*
                    Opção 1 e 10
                */
                case '1':
                {
                    /*
                        Opção 1)
                        Esta opção recebe como parâmetro e a partir de inputs do usuário printa:
                        Nome completo, Idade e Idade + caracateres do Nome completo.
                    */
                    if (input_Menu[1] != '0' && len_Input < 2)
                    {
                        // Chamada da função de apresentação
                        ch1_apresentese(ANO);
                    }
                    /*
                        Opção 10)
                        Esta opção recebe como input um caractere do usuário e printa:
                        O caracter digitado e seu ASCII correspondente.
                    */
                    else if (input_Menu[1] == '0')
                    {
                        // Chamada da função returnaacii
                        ch10_returnascii();
                    }
                    else
                    {
                        printf("\nOpcao invalida.\n");
                    }
                    break;
                }
                /*
                    Opção 2
                    Esta opção recebe dois números como parâmetro e printa:
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
                        Aqui tá sendo criado um ponteiro para cada uma das funções criadas, sendo elas as questões de A a F.
                        Estas foram definidas na Acc_Biblioteca junto com as outras funções.
                    */
                    double (*ch2_func[])(int, int) = {ch2_A_sum, ch2_B_multiply, ch2_C_pow, ch2_D_hypo, ch2_E_sindi, ch2_F_mod};

                    printf("Insira um valor:");
                    scanf("%d", &input_FValue);
                    printf("Insira outro valor:");
                    scanf("%d", &input_SValue);

                    // Fazendo com que os ponteiros criados apontem para o endereço alocado para os inputs (olhando para xícara)
                    pFValue = &input_FValue;
                    pSValue = &input_SValue;

                    for(contador_1 = 0; contador_1< operacoes; contador_1++)
                    {
                        // Chamada da função a depender do contador
                        result = (*ch2_func[contador_1])(pFValue, pSValue);
                        printf("%lf.\n\n", result);
                    }

                    break;
                }
                /*
                    Opção 3
                    Esta opção recebe um número double como parâmetro e printa:
                    A temperatura em Fahrenheit convertida em Celcius
                */
                case '3':
                {
                    double input_Temperature;

                    // Inicializando o ponteiro apontando para o Null (olhando pra cima)
                    temperatura_t *t_Celcius = NULL;

                    // Obtenção da temperatura informada
                    printf("Insira aqui uma temperatura em Fahrenheit: ");
                    scanf("%lf", &input_Temperature);

                    // Chamada da função de conversão
                    ch3_temperatura(input_Temperature, &t_Celcius);

                    printf("A temperatura informada convertida para %s e: %lf\n", t_Celcius->Unidade,t_Celcius->Grau);

                    // Liberando o Malloc
                    free(t_Celcius);

                    break;
                }
                /*
                    Opção 4
                    Esta opção recebe um número inteiro como parâmetro e printa:
                    O fatorial deste número.
                */
                case '4':
                {
                    int input_Tofatorial;
                    int result;

                    // Obtenção do valor informado
                    printf("Calcular o fatorial de: ");
                    scanf("%d", &input_Tofatorial);

                    // Chamada da função que calcula o fatorial
                    result = ch4_fatorial(input_Tofatorial);

                    if (result != 0)
                    {
                        printf("O fatorial de %d e %d.\n", input_Tofatorial, result);
                    }

                    break;
                }
                /*
                    Opção 5
                    Esta opção recebe dez strings numéricas como parâmetro e printa:
                    O vetor e a média correndente ao mesmo.
                */
                case '5':
                {
                    // Chamada da função que solicita input e calcula sua média
                    ch5_media();
                    break;
                }
                /*
                    Opção 6
                    Esta opção coloca o tamanho da matriz como parâmetro e printa:
                    A tabuada de 1 a 10 sem a tabuada de 5.
                */
                case '6':
                {
                    // Chamada da função que realiza a criação e print da tabuada
                    ch6_malloctabuada(TAMANHO_MATRIZ);
                    break;
                }
                /*
                    Opção 7
                    Esta opção coloca o tamanho da matriz como parâmetro e printa:
                    Diferença entre a média dos elementos das colunas pares, média dos elementos das linhas ímpares.
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
                    Opção 8
                    Esta opção não recebe parâmetro e printa:
                    Os números de 100 a 1.
                */
                case '8':
                {
                    // Chamada da função que realiza a contagem
                    ch8_cem_a_um();
                    break;
                }
                /*
                    Opção 9
                    Esta opção recebe uma String(input) e um char como parâmetro e printa:
                    O número de caracteres na string e a mesma modificada.
                */
                case '9':
                {
                    char char_Contar = 'a';
                    char input_String[50];

                    // Inicializando os ponteiros apontando para o Null (olhando pra cima)
                    char *pString = NULL;

                    // Obtenção dos dados para se trabalhar
                    printf("Insira aqui uma string: ");
                    scanf("%s", &input_String);

                    // Fazendo com que o ponteiro criado aponte para o endereço alocado para o input (olhando para xícara)
                    pString = &input_String;

                    // Chamada da função que realiza o replacement
                    ch9_countnreplace(pString, char_Contar);

                    break;
                }
                default:
                {
                    if (is_Exit == 0)
                    {
                        /*
                            Seta variável do loop como False
                            Inicia a variável contadora para a saída do código
                        */
                        int count_Exit = 10;

                        while (count_Exit >= 0)
                        {
                            // Printa o valor do contador
                            printf("%d\n", count_Exit);

                            /*
                                Inicia a instância start_time a partir do clock, proveniente de time.h
                                E em seguida faz um while que vai contar n segundos
                            */
                            clock_t start_time = clock();
                            while (clock() < start_time + 1000);

                            // Não gosto de usar o -= porque acho não intuitivo
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
