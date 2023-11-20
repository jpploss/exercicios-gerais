#include "estabelecimento.h"

int main() {
    tEstabelecimento* estabelecimento = CriaEstabelecimento();
    LeEstabelecimento(estabelecimento);
    printf("Produtos em falta:\nCodigo;Nome;Preco\n");
    ImprimeProdutosEmFaltaEstabelecimento(estabelecimento);
    DestroiEstabelecimento(estabelecimento);


    return 0;
}