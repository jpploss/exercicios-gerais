#ifndef _CONTA_H
#define _CONTA_H

#include "usuario.h"

typedef struct {
    tUsuario usuario;
    int numConta;
    float saldo;
} tConta;
    
tConta EfetuaSaque(tConta conta, float valor);

tConta EfetuaDeposito(tConta conta, float valor);

tConta CadastraUsuario();

void ImprimeRelatorio(tConta* contas, int qtd);

#endif