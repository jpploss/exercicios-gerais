#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int qtdTarefas;
    printf("Digite o numero de tarefas: ");
    scanf("%d", &qtdTarefas);

    tAgendaTarefas* agenda = CriaAgendaDeTarefas(qtdTarefas);

    char prefixo;
    int prioridade;
    char msg[101];
    float n1, n2;
    for(int i = 0; i < qtdTarefas; i++) {

        while(1) {
            scanf("%d %c ", &prioridade, &prefixo);
            if(prefixo == 'S' || prefixo == 'I' || prefixo == 'M') break;
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            scanf("%*[^\n]");
            scanf("%*c");
        }
        

        if(prefixo == 'I') {
            scanf("%[^\n]", msg);
            tImpr* imp = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(agenda, prioridade, imp, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        } else if(prefixo == 'S') {
            scanf("%f%f", &n1, &n2);
            tSoma* sum = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, sum, ExecutaTarefaSoma, DestroiTarefaSoma);
        } else if(prefixo == 'M') {
            scanf("%f%f", &n1, &n2);
            tMult* mult = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, mult, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        } 
    }

    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

}