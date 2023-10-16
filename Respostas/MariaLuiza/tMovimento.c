#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tMovimento.h"
/*

typedef struct tMovimento
{
    int numeroDoMovimento;
    COMANDO comando;
    char acao[50];
} tMovimento;
*/
/**
 * Cria o movimento dinamicamente
 * \param numeroDoMovimento número do movimento
 * \param comando comando que foi dado para o movimento
 * \param acao a ação gerada pelo movimento
 */
tMovimento *CriaMovimento(int numeroDoMovimento, COMANDO comando, const char *acao)
{
    tMovimento *movimentos = (tMovimento *)malloc(sizeof(tMovimento));
    movimentos->comando = comando;
    movimentos->numeroDoMovimento = numeroDoMovimento;
    strcpy(movimentos->acao, acao);
    return movimentos;
}

/**
 * Retorna o número do movimento
 * \param movimento movimento
 */
int ObtemNumeroMovimento(tMovimento *movimento)
{
    return movimento->numeroDoMovimento;
}

/**
 * Retorna o comando do movimento
 * \param movimento movimento
 */
COMANDO ObtemComandoMovimento(tMovimento *movimento)
{
    return movimento->comando;
}

/**
 * Retorna a ação do movimento
 * \param movimento movimento
 */
char *ObtemAcaoMovimento(tMovimento *movimento)
{
    return movimento->acao;
}

/**
 * Libera o espaço alocado para a estrutura tMovimento
 *
 * \param movimento movimento
 */
void DesalocaMovimento(tMovimento *movimento)
{
    // free(movimento->acao);
    free(movimento);
}
