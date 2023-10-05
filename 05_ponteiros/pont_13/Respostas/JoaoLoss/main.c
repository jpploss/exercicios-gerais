#include "rolagem.h"
#include <stdio.h>

void LeMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs) {
    for(int i = 0; i < *numMsgs; i++) {
        scanf("%[^\n]", msg[i]);
        scanf("%*[^\n]");
        scanf("%*c");
    }
    return;
}

int main() {
    RolaMsg(LeMensagens, 30, 100);
    return 0;
}