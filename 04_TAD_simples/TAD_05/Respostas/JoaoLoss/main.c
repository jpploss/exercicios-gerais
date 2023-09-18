#include <stdio.h>
#include "conta.h"

int main() {
    int operacao, maxContas, contaContas = 0, numConta;
    float valor;
    scanf("%d", &maxContas);
    tConta contas[maxContas];

    while(1) {
        scanf("%d", &operacao);
        if(operacao == 0) break;
        switch (operacao)
        {
        case 1:
            scanf("%d%f", &numConta, &valor);
            contas[numConta - 1] = EfetuaSaque(contas[numConta - 1], valor);
            break;
        case 2:
            scanf("%d%f", &numConta, &valor);
            contas[numConta - 1] = EfetuaDeposito(contas[numConta - 1], valor);
            break;
        case 3:
            contas[contaContas] = CadastraUsuario();
            contaContas++;
            break;
        case 4:
            ImprimeRelatorio(contas, contaContas);
            break;
        default:
            printf("Operacao inválida, digite novamente.\n");
            break;
        }
    }

    return 0;
}