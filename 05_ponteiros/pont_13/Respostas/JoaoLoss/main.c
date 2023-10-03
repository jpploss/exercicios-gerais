#include "rolagem.h"
#include <stdio.h>

int main() {
    int qtdMsg;
    scanf("%d", &qtdMsg);
    scanf("%*[^\n]");
    scanf("%*c");

    char mensagens[qtdMsg][TAM_MAX_MSG];

    for(int i = 0; i < qtdMsg; i++) {
        scanf("%[^\n]", mensagens[i]);
        scanf("%*[^\n]");
        scanf("%*c");
    }
    






    return 0;
}