#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tPosicao.h"
#include "tTunel.h"
/**
 * Cria o tunel dinamicamente
 * \param linhaAcesso1 linha da posição do acesso 1 do túnel
 * \param colunaAcesso1 coluna da posição do acesso 1 do túnel
 * \param linhaAcesso2 linha da posição do acesso 2 do túnel
 * \param colunaAcesso2 coluna da posição do acesso 2 do túnel
 */
tTunel *CriaTunel(int linhaAcesso1, int colunaAcesso1, int linhaAcesso2, int colunaAcesso2)
{
    tTunel *tunel1 = (tTunel *)malloc(sizeof(tTunel));
    tunel1->acesso1 = (tPosicao *)malloc(sizeof(tPosicao));
    tunel1->acesso2 = (tPosicao *)malloc(sizeof(tPosicao));
    tunel1->acesso1 = CriaPosicao(linhaAcesso1, colunaAcesso1);
    tunel1->acesso2 = CriaPosicao(linhaAcesso2, colunaAcesso2);
    return tunel1;
}

/**
 * Verifica se entrou no túnel pela posição
 * \param tunel tunel
 * \param posicao posição
 */
bool EntrouTunel(tTunel *tunel, tPosicao *posicao)
{
    return SaoIguaisPosicao(tunel->acesso1, posicao) || SaoIguaisPosicao(tunel->acesso2, posicao);
}

/**
 * Atualiza a posição para o final do túnel
 * \param tunel tunel
 * \param posicao posição
 */
void LevaFinalTunel(tTunel *tunel, tPosicao *posicao)
{
    if (SaoIguaisPosicao(tunel->acesso1, posicao))
    {
        AtualizaPosicao(posicao, tunel->acesso2);
    }
    else if (SaoIguaisPosicao(tunel->acesso2, posicao))
    {
        AtualizaPosicao(posicao, tunel->acesso1);
    }
}

/**
 * Libera o espaço alocado para a estrutura tTunel
 *
 * \param tunel tunel
 */
void DesalocaTunel(tTunel *tunel)
{
    free(tunel->acesso1);
    free(tunel->acesso2);
    free(tunel);
}
