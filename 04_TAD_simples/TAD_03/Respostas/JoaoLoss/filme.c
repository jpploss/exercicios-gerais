typedef struct {
    int codigo;
    int preco;
    char nome[20];
    int qtdFitas;
    int fitasDisponiveis;
} tFilme;

tFilme LeFilme() {
    tFilme filme;
    scanf("%d,%[^,],%d,%d", &filme.codigo, filme.nome, &filme.preco, &filme.qtdFitas);
    filme.fitasDisponiveis = filme.qtdFitas;
    return filme;
}

int EhMesmoCodigo(tFilme filme1, tFilme filme2) {
    if(filme1.codigo == filme2.codigo) return 1;
    return 0;
}

int TemFitas(tFilme filme) {
    if(filme.fitasDisponiveis >= 1) return 1;
    return 0;
}

int TemMaximoDeFitas(tFilme filme) {
    if(filme.qtdFitas == filme.fitasDisponiveis) return 1;
    return 0;
}

int NomeMaiorNoAlfabeto(tFilme filme1, tFilme filme2) {
    int i = 0;
    int tam1 = 0, tam2 = 0;
    while(filme1.nome[tam1] != 0) {
        tam1++;
    }
    tam1++;
    while(filme2.nome[tam2] != 0) {
        tam2++;
    }
    tam2++;

    while(i < tam1 - 1) {
        if(filme1.nome[i] > filme2.nome[i]) return 0;
        else if(i == tam2 - 2) return 0;
        i++;
    }
    return 1;
}