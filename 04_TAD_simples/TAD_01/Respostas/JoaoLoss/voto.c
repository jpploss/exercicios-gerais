#include <stdio.h>
#include "voto.h"

/**
 * @brief Inicializa a estrutura de votos com valores zerados.
 * @return Retorna uma estrutura tVoto com todos os campos zerados.
 */
tVoto inicializaVotos() {
    tVoto votoZerado;
    votoZerado.brancosM = 0;
    votoZerado.brancosP = 0;
    votoZerado.nulosM = 0;
    votoZerado.nulosP = 0;
    votoZerado.dij = 0;
    votoZerado.ber = 0;
    votoZerado.lin = 0;
    votoZerado.lov = 0;
    votoZerado.sha = 0;
    votoZerado.tur = 0;
    return votoZerado;
}

/**
 * @brief Calcula a porcentagem de um valor em relação a um total.
 * @param valor Valor a ser calculado a porcentagem.
 * @param total Total em relação ao qual será calculada a porcentagem.
 * @return Retorna o valor da porcentagem.
 */
float porcentagem(int valor, int total) {
    return ((float)valor/total)*100.00;
}

/**
 * @brief Contabiliza um voto para Presidente.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @param votoP Identificador do candidato a Presidente.
 * @return Retorna a estrutura tVoto com o voto contabilizado.
 */
tVoto contabilizaVotoPrisidente(tVoto votos, int votoP) {
    switch (votoP)
    {
    case DIJKSTRA:
        votos.dij++;
        break;
    case TURING:
        votos.tur++;
        break;
    case SHAW:
        votos.sha++;
        break;
    case BRANCO:
        votos.brancosP++;
        break;   
    default:
        votos.nulosP++;
        break;
    }
    return votos;
}

/**
 * @brief Contabiliza um voto para Primeiro Ministro.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @param votoM Identificador do candidato a Primeiro Ministro.
 * @return Retorna a estrutura tVoto com o voto contabilizado.
 */
tVoto contabilizaVotoPMinistro(tVoto votos, int votoM) {
    switch (votoM)
    {
    case BERNERS:
        votos.ber++;
        break;
    case LINUS:
        votos.lin++;
        break;
    case LOVELACE:
        votos.lov++;
        break;
    case 0:
        votos.brancosM++;
        break;   
    default:
        votos.nulosM++;
        break;
    }
    return votos;
}

/**
 * @brief Verifica o vencedor da eleição para presidente.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o identificador do candidato vencedor, ou SEM DECISAO ou EMPATE em caso de empate.
 */
int vencedorPresidente(tVoto votos) {
    int votosValidos = votos.dij + votos.tur + votos.sha;
    int votosBrancoENulo = votos.brancosP + votos.nulosP;
    if(votosValidos < votosBrancoENulo) {
        return SEM_DECISAO;
    }
    if(votos.dij > votos.tur) {
        if(votos.dij > votos.sha) return DIJKSTRA;
        else if(votos.dij < votos.sha) return SHAW;
        else return EMPATE;
    } else if(votos.dij < votos.tur) {
        if(votos.tur > votos.sha) return TURING;
        else if(votos.tur < votos.sha) return SHAW;
        else return EMPATE;
    } else if(votos.dij < votos.sha) return SHAW;
    else return EMPATE;
}

/**
 * @brief Verifica o vencedor da eleição para Primeiro Ministro.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o identificador do candidato vencedor, ou SEM DECISAO ou EMPATE em caso de empate.
 */
int vencedorPMinistro(tVoto votos) {
    int votosValidos = votos.ber + votos.lin + votos.lov;
    int votosBrancoENulo = votos.brancosM + votos.nulosM;
    if(votosValidos < votosBrancoENulo) {
        return SEM_DECISAO;
    }
    if(votos.ber > votos.lin) {
        if(votos.ber > votos.lov) return BERNERS;
        else if(votos.ber < votos.lov) return LOVELACE;
        else return EMPATE;
    } else if(votos.ber < votos.lin) {
        if(votos.lin > votos.lov) return LINUS;
        else if(votos.lin < votos.lov) return LOVELACE;
        else return EMPATE;
    } else if(votos.ber < votos.lov) return LOVELACE;
    else return EMPATE;
}

/**
 * @brief Obtém o total de votos para a presidência.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o total de votos para a presidência.
 */
int obtemTotalVotosPresidente(tVoto votos) {
    return votos.dij + votos.tur + votos.sha;
}

/**
 * @brief Obtém o total de votos para Primeiro Ministro.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o total de votos para Primeiro Ministro.
 */
int obtemTotalVotosPMinistro(tVoto votos) {
    return votos.ber + votos.lin + votos.lov;
}

/**
 * @brief Imprime o resultado da eleição.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @param totalP Total de votos para a presidência.
 * @param totalM Total de votos para Primeiro Ministro.
 * @param vencedorP Identificador do candidato vencedor para a presidência.
 * @param vencedorM Identificador do candidato vencedor para Primeiro Ministro.
 * @param counterQtd Contador de votos válidos.
 * @param qtd Quantidade de eleitores.
 */
void printaResultado(tVoto votos, int totalP, int totalM, int vencedorP, int vencedorM, int counterQtd, int qtd) {
    counterQtd = obtemTotalVotosPresidente(votos);
    int totalVotos = votos.brancosP + votos.nulosP + counterQtd;
    
    printf("FIM DA ELEICAO\n- PRESIDENTE ELEITO: ");
    if(vencedorP == EMPATE) printf("EMPATE\n");
    else if(vencedorP == SEM_DECISAO) printf("SEM DECISAO\n");
    else {
        if(vencedorP == DIJKSTRA) printf("Edsger Dijkstra (Partido do Melhor Caminho (PMC)), ");
        else if(vencedorP == TURING) printf("Alan Turing (Partido dos Avanço Intelectual (PAI)), ");
        else if(vencedorP == SHAW) printf("Carol Shaw, (Mulheres Programadoras Unidas (MPU)), ");
        printf("%d, %.02f%%\n", totalP, porcentagem(counterQtd, totalVotos));
    }
    

    counterQtd = obtemTotalVotosPMinistro(votos);
    printf("- PRIMEIRO MINISTRO ELEITO: ");
    if(vencedorM == EMPATE) printf("EMPATE\n");
    else if(vencedorM == SEM_DECISAO) printf("SEM DECISAO\n"); 
    else {
        if(vencedorM == BERNERS) printf("Tim Berners-Lee (World Wide Web (WWW)), ");
        else if(vencedorM == LINUS) printf("Linus Torvalds (Linux (Linux)), ");
        else if(vencedorM == LOVELACE) printf("Ada Lovelace (Gamers Unidos (GU)), ");
        printf("%d, %.02f%%\n", totalM, porcentagem(counterQtd, totalVotos));
    }
    
    printf("- COMPARECIMENTO: %.02f%%\n", porcentagem(totalVotos, qtd));
    printf("- NULOS E BRANCOS: %d, %d", votos.nulosP+votos.brancosP, votos.nulosM+votos.brancosM);

    return;
}
