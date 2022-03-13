/**
* @file Acc_Biblioteca.c
* @author Danilo Raposo Barros - culpinharbarros@gmail.com
* @date 12-01-2021 16:56:00
* @brief Printa o menu do código
*/
void show_menu()
{
    printf("\n[0] Hello world"
    "\n[1] Apresente-se!"
    "\n[2] Operacoes matematicas entre 2 numeros"
    "\n[3] Conversao de Fahrenheit para Celsius"
    "\n[4] Fatorial de um numero"
    "\n[5] Media de 10 numeros"
    "\n[6] Tabuada (menos a de 5)"
    "\n[7] Operacoes matematicas dentro de uma matriz"
    "\n[8] De 100 a 0."
    "\n[9] Contador e substituidor de As por Bs"
    "\n[10] Transformador de caracter em ASCII"
    "\n[Exit] Sair"
    "\n");
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Raposo Barros - culpinharbarros@gmail.com
* @date 12-01-2021 16:46:00
* @brief Limpa o menu e segura o prompt até que sera pressionado alguma tecla
*/
void clear_menu()
{
    system("pause");
    system("cls");
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Raposo Barros - culpinharbarros@gmail.com
* @date 14-01-2021 12:25:00
* @brief Parâmetros: String. Retorna 1 se for exit e 0 caso contrário
                             Include declarado abaixo porque sem a mesma o código estava apresentando erro.
*/
#include <stdbool.h>
bool check_exit(char input[])
{
    bool output_t = true;
    bool output_f = false;
    if (strcmp(input,"exit") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Raposo Barros - culpinharbarros@gmail.com
* @date 14-01-2021 00:22:00
* @brief Parâmetros: Nenhum. Printa: hello world.
*/
void *ch0_henlo()
{
    printf("Hello world.\n");
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Raposo Barros - culpinharbarros@gmail.com
* @date 14-01-2021 00:22:00
* @brief Parâmetros: Um ponteiro função. Printa: chama a função que printa hello world.
*/
void ch0_callhenlo(char*(*func)())
{
    (*func);
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Raposo Barros - culpinharbarros@gmail.com
* @date 12-01-2021 17:01:00
* @brief Parâmetros: Ano atual + Input interno. Printa: Nome completo, Idade e Idade + caracateres do Nome completo
*/
void ch1_apresentese(int ano_atual)
{
    char Nome[20];
    char Sobrenome[20];
    int Ano;
    int sum_Idade;
    int sum_Nome;

    // Obtenção do nome, sobrenome e soma de seus caracteres
    printf("Insira seu nome:");
    scanf("%s", &Nome);
    printf("Insira seu sobrenome:");
    scanf("%s", &Sobrenome);
    sum_Nome = strlen(strcat(strcat(Nome, " "),Sobrenome));

    // Obtenção do ano e cálculo da idade
    printf("Insira o ano que nasceu:");
    scanf("%d", &Ano);
    sum_Idade = ano_atual - Ano;

    printf("Seu nome completo e %s, voce tem %d anos, seu nome mais a sua idade tem %d caracteres.\n\n",
           Nome, sum_Idade, sum_Idade + sum_Nome - 1);
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Raposo Barros - culpinharbarros@gmail.com
* @date 12-01-2021 17:38:00
* @brief Parâmetros: Dois ponteiros de inteiros. Retorna: A)A + B, B)A * B ** 2, C)A ** 2, D)Hipotenusa, E)Sin(A-B), F)|A|.
                                                      C e F usam dois parâmetros devido a lógica no Main.
*/
double ch2_A_sum(int *Valor1, int *Valor2)
{
    double result_A = *Valor1 + *Valor2;
    printf("\nA soma dos dois numeros e: ");

    return result_A;
}
double ch2_B_multiply(int *Valor1, int *Valor2)
{
    double result_B = *Valor1 * pow(*Valor2,2);
    printf("O produto do primeiro numero pelo quadrado do segundo e: ");

    return result_B;
}
double ch2_C_pow(int *Valor1, int *Valor2)
{
    double result_C = pow(*Valor1,2);
    printf("O quadrado do primeiro numero e: ");

    return result_C;
}
double ch2_D_hypo(int *Valor1, int *Valor2)
{
    double result_D = sqrt(pow(*Valor1,2) + pow(*Valor2,2));
    printf("A raiz quadrada da soma dos quadrados e: ");

    return result_D;
}
double ch2_E_sindi(int *Valor1, int *Valor2)
{
    double result_E = sin(*Valor1)*cos(*Valor2) - sin(*Valor2)*cos(*Valor1);
    printf("O seno da diferenca do primeiro numero pelo segundo e: ");

    return result_E;
}
double ch2_F_mod(int *Valor1, int *Valor2)
{
    double result_F;
    if (*Valor1 >= 0)
    {
        result_F = *Valor1;
    }
    else
    {
        result_F = *Valor1 * -1;
    }
    printf("O modulo do primeiro numero e: ");
    return result_F;
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Rap:oso Barros - culpinharbarros@gmail.com
* @date 12-01-2021 18:56:00
* @brief Parâmetros: Uma temperatura em Fahrenheit. Retorna: O valor dessa temperatura convertida em Celcius.
         Para esta função foi utilizado a estrutura temperatura (do tipo temperatura_t).
*/
struct temperatura
{
    double Grau;
    char Unidade[20];
}
typedef temperatura_t;

void ch3_temperatura(double t_fah, temperatura_t **t_out)
{
    *t_out = (temperatura_t *)malloc(sizeof(temperatura_t));

    (*t_out)-> Grau = ((t_fah-32.0)*(5.0/9.0));
    strcpy(((*t_out)-> Unidade), "Celcius");
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Rap:oso Barros - culpinharbarros@gmail.com
* @date 12-01-2021 23:29:00
* @brief Parâmetros: Um inteiro qualquer. Retorna: O fatorial deste número.
*/
int ch4_fatorial(int input_Tofatorial)
{
    // Saber se é possível calcular o fatorial do número
    if (input_Tofatorial < 0)
    {
        printf("Nao existe fatorial de valores negativos.\n");
        return 0;
    }
    else
    {
        /*
             Incialização de variáveis para o contador
             Fatorial foi declarado como 1 devido a lógica matemática, não mudar.
        */
        int contador;
        int fatorial = 1;

        // For que vai realizar o cálculo
        for(contador=1;contador<=input_Tofatorial;contador++)
        {
            fatorial = fatorial * contador;
        }
        return fatorial;
    }
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Rap:oso Barros - culpinharbarros@gmail.com
* @date 13-01-2021 00:08:00
* @brief Parâmetros: Nenhum + Input interno. Printa: A média dos valores digitados.
*/
void ch5_media()
{
    int contador;
    double somatorio = 0;
    int tamanho_Vetor = 10;

    char aux_Vetor[tamanho_Vetor];
    char Vetor[tamanho_Vetor];

    for(contador=1;contador<=tamanho_Vetor;contador++)
    {
        printf("Insira o %d valor aqui: ", contador);
        scanf("%s", &aux_Vetor);

        // Concatenando um espaço para cada input diferente do primeiro
        if (contador > 1)
        {
            strcat(Vetor," ");
        }
        strcat(Vetor,aux_Vetor);
    }

    // Cria um ponteiro que aponta para o conjunto de dados splitado
    char *token = strtok(Vetor, " ");

    // Esse while é o que printa o vetor e calcula o somatório dos valores
    printf("O vetor digitado foi o seguinte:\n");
    while( token != '\0' )
    {
        printf( "%s ", token );
        somatorio = somatorio + atoi(token);
        token = strtok('\0', " ");
    }
    printf("\nA media do mesmo eh: %lf\n", somatorio/tamanho_Vetor);
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Rap:oso Barros - culpinharbarros@gmail.com
* @date 13-01-2021 17:47:00
* @brief Parâmetros: Quantidade de linhas e colunas. Retorna: Uma Matriz
*/
int ch6n7_criarmatriz(int Linha, int Coluna)
{
    int contador_1;
    int contador_2;

    int **matriz = malloc(sizeof(int*) * Linha);

    for(contador_1=0;contador_1<Linha;contador_1++)
    {
        matriz[contador_1] = malloc(sizeof(int*) * Coluna);
    }

    return matriz;
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Rap:oso Barros - culpinharbarros@gmail.com
* @date 13-01-2021 16:40:00
* @brief Parâmetros: Input do tamanho da matriz. Printa: A tabuada de 1 a 10 sem a tabuada de 5.
*/
void ch6_malloctabuada(int TAMANHO_MATRIZ)
{
    int contador_1;
    int contador_2;

    int **matriz = ch6n7_criarmatriz(TAMANHO_MATRIZ+1, TAMANHO_MATRIZ+1);

    for(contador_1=0;contador_1<=TAMANHO_MATRIZ;contador_1++)
    {
        // Formação da matriz (com o 5)
        for(contador_2=0;contador_2<=TAMANHO_MATRIZ;contador_2++)
        {
            matriz[contador_1][contador_2] = contador_1 * contador_2;
        }

        // Printando os elementos da matriz (sem o 5)
        if (contador_1 != 5)
        {
            printf("\n");
            for(contador_2=0;contador_2<=TAMANHO_MATRIZ;contador_2++)
            {
                printf("%d x %d = %d\n", contador_1, contador_2, matriz[contador_1][contador_2]);
            }
        }
    }

    free(matriz);
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Rap:oso Barros - culpinharbarros@gmail.com
* @date 13-01-2021 23:12:00
* @brief Parâmetros: Linha e Coluna. Printa: Diferença entre a média dos elementos das colunas pares, média dos elementos das linhas ímpares.
*/
void ch7_operacaomatriz(int Linha, int Coluna)
{
    int contador_1;
    int contador_2;
    double **Matriz = ch6n7_criarmatriz(Linha, Coluna);
    double Media_Linha[Linha];
    double Media_Coluna[Coluna];

    // Preenchendo a Matriz
    for(contador_1=0;contador_1<Linha;contador_1++)
    {
        for(contador_2=0;contador_2<Coluna;contador_2++)
        {
            printf("Insira o valor da linha %d e coluna %d: ", (contador_1+1),(contador_2+1));
            scanf("%lf", &Matriz[contador_1][contador_2]);
        }
    }

    for(contador_1=0;contador_1<Coluna;contador_1++)
    {
        printf("\n");

        // For responsável pelo cálculo das médias
        for(contador_2=0;contador_2<Linha;contador_2++)
        {
            Media_Coluna[contador_1] = Media_Coluna[contador_1] + Matriz[contador_2][contador_1];
            //printf("Coluna %d Linha %d = %lf\n", (contador_1+1),(contador_2+1),Matriz[contador_2][contador_1]); //debug
            Media_Linha[contador_1] = Media_Linha[contador_1] + Matriz[contador_1][contador_2];
            //printf("Linha %d Coluna %d = %lf\n", (contador_1+1),(contador_2+1),Matriz[contador_1][contador_2]); //debug
        }

        // Calcula o valor médio das colunas pares
        if (contador_1 % 2 != 0)
        {
            printf("O valor da media da coluna %d eh %lf\n", contador_1 + 1, Media_Coluna[contador_1]/Linha);
            for(contador_2=0;contador_2<Linha;contador_2++)
            {
                printf("A diferenca entre %lf e media da coluna %d eh %lf\n", Matriz[contador_2][contador_1], contador_1, Matriz[contador_2][contador_1] - Media_Coluna[contador_1]/Linha);
            }
        }
        // Calcula o valor médio das linhas ímpares
        else if(contador_1 % 2 == 0)
        {
            printf("O valor da media da linha %d eh %lf\n", contador_1 + 1, Media_Linha[contador_1]/Coluna);
        }
    }
    free(Matriz);
}


/**
* @file Acc_Biblioteca.c
* @author Danilo Rap:oso Barros - culpinharbarros@gmail.com
* @date 13-01-2021 16:29:00
* @brief Parâmetros: Nenhum. Printa: Printa um contador de 100 a 1.
*/
void ch8_cem_a_um()
{
    int contador_1;

    // For de trás pra frente
    for(contador_1=100;contador_1>0;contador_1--)
    {
        // Dá um espaço a cada dividor de 10
        if(contador_1 % 10 == 0)
        {
            printf("\n");
        }
        printf("%d \t", contador_1);
    }
    printf("\n");
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Rap:oso Barros - culpinharbarros@gmail.com
* @date 13-01-2021 16:18:00
* @brief Parâmetros: Uma string e um caracter. Printa: O número de caracteres na string e a mesma modificada
*/
void ch9_countnreplace(char *input_String, char char_Contar)
{
    int contador_1;
    int contador_str = 0;

    // Loop responsável por contar e substituir os caracteres
    for (contador_1 = 1; contador_1 <= strlen(input_String); contador_1++)
    {
        if (char_Contar == input_String[contador_1-1])
        {
            // Conta a quantidade de caracteres
            contador_str = contador_str + 1;

            // Substitui o caracter por 'b'
            input_String[contador_1-1] = 'b';
        }
    }

    printf("\nFoi possivel encontrar %d %c(s).\n", contador_str, char_Contar);
    printf("A palavra com 'b' no lugar do 'a' ficou: %s\n", input_String);
}

/**
* @file Acc_Biblioteca.c
* @author Danilo Raposo Barros - culpinharbarros@gmail.com
* @date 12-01-2021 17:25:00
* @brief Input: Um caractere qualquer. Printa: O caracter digitado e seu ASCII correspondente
*/
void ch10_returnascii()
{
    char input_Char;
    int char_Asc;

    // Obtendo o caractere informado pelo usuario e seu respectivo ASCII através do Type Castying
    printf("Insira aqui um caractere: ");
    scanf("\n%c", &input_Char);
    char_Asc = (int) input_Char;

    printf("O numero correspondente de %c na tabela ASC e %d\n", input_Char, char_Asc);
}
