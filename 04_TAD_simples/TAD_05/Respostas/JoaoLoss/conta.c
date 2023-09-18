#include "conta.h"
#include <stdio.h>
 
tConta EfetuaSaque(tConta conta, float valor) {
    conta.saldo -= valor;
    return conta;
}

tConta EfetuaDeposito(tConta conta, float valor) {
    conta.saldo += valor;
    return conta;
}

tConta CadastraUsuario() {
    tConta conta;
    conta.saldo = 0.00;
    conta.usuario = LeUsuario();
    scanf("%d", &conta.numConta);
    return conta;
}

void ImprimeRelatorio(tConta* contas, int qtd) {
    printf("===| Imprimindo Relatorio |===\n");
    for(int i = 0; i < qtd; i++) {
        printf("Conta: %d\n", contas[i].numConta);
        printf("Saldo: R$ %.02f\n", contas[i].saldo);
        printf("Nome: ");
        PrintaNome(contas[i].usuario);
        printf("CPF: %d\n\n", RetornaCpf(contas[i].usuario));
    }
}