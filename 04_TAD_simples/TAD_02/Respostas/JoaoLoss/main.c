#include <stdio.h>
#include "voto.h"
#include "eleitor.h"

int main() {
    int votantes;
    scanf("%d", &votantes);

    int idAtual, presidenteAtual, pmAtual;
    int contaEleitor = 0;
    tEleitor eleitores[votantes];
    tVoto votos = inicializaVotos();

    while(1) {
        scanf("%*[^\n]");
        scanf("%*c");

        char aux;
        scanf("%c", &aux);
        if(aux == 'P') break;

        idAtual = aux - '0';
        if(contaEleitor == votantes) {
            printf("ELEICAO ANULADA");
            return 0;
        }
        scanf("%d%d", &presidenteAtual, &pmAtual);
        eleitores[contaEleitor] = criaEleitor(idAtual, presidenteAtual, pmAtual);

        // verifica se ja votou
        int i, idPassados;
        for(i = 0; i < contaEleitor; i++) {
            idPassados = obtemIdEleitor(eleitores[i]);
            if(jaVotou(eleitores[contaEleitor], idPassados)) {
                printf("ELEICAO ANULADA");
                return 0;
            }
        }

        votos = contabilizaVotoPrisidente(votos, presidenteAtual);
        votos = contabilizaVotoPMinistro(votos, pmAtual);
        contaEleitor++;
    }

    int totalVotosPresida = obtemTotalVotosPresidente(votos);
    int totalVotosPm = obtemTotalVotosPMinistro(votos);
    int vencedorPresida = vencedorPresidente(votos);
    int vencedorPm = vencedorPMinistro(votos);

    int conta;
    printaResultado(votos, totalVotosPresida, totalVotosPm, vencedorPresida, vencedorPm, conta, votantes);



    return 0;
}