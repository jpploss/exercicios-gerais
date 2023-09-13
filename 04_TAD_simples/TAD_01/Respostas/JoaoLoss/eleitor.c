#include "eleitor.h"

/**
 * @brief Cria um eleitor.
 * @param id Identificador do eleitor.
 * @param votoP Voto para Presidente.
 * @param votoM Voto para Primeiro Ministro.
 * @return Retorna um eleitor.
 */
tEleitor criaEleitor(int id, int votoP, int votoM) {
    tEleitor eleitor;
    eleitor.id = id;
    eleitor.votoM = votoM;
    eleitor.votoP = votoP;
    return eleitor;
}

/**
 * @brief Verifica se o eleitor já votou.
 * @param eleitor Eleitor a ser verificado.
 * @param idAnterior Identificador do eleitor anterior.
 * @return Retorna 1 se o eleitor já votou e 0 caso contrário.
 */
int jaVotou(tEleitor eleitor, int idAnterior) {
    if(eleitor.id == idAnterior) return 1;
    return 0;
}

/**
* @brief Obtém o identificador do eleitor.
* @param eleitor Eleitor a ser verificado.
* @return Retorna o identificador do eleitor.
*/
int obtemIdEleitor(tEleitor eleitor) {
    return eleitor.id;
}

/**
 * @brief Obtém o voto para Presidente.
 * @param eleitor Eleitor a ser verificado.
 * @return Retorna o voto para Presidente.
 */
int obtemVotoPresidente(tEleitor eleitor) {
    return eleitor.votoP;
}

/**
 * @brief Obtém o voto para Primeiro Ministro.
 * @param eleitor Eleitor a ser verificado.
 * @return Retorna o voto para Primeiro Ministro.
 */
int obtemVotoPMinistro(tEleitor eleitor) {
    return eleitor.votoM;
}