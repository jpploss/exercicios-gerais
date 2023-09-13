#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano) {
    if (dia > 0 && dia < 32 && 
        mes > 0 && mes < 13 &&
        ano >= 0) {
        if (dia <= numeroDiasMes(mes, ano)) return 1;
    } 
    return 0;
}

void imprimeMesExtenso(int mes) {
    switch (mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Março");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
    return;
}

int verificaBissexto(int ano) {
    if(!(ano%100)) {
        if(!(ano%400)) {
            return 1;
        }
        return 0;
    } else if(!(ano%4)) {
        return 1;
    }
    return 0;
}

int numeroDiasMes(int mes, int ano) {
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        return 31;
    } else if(mes == 2) {
        if(verificaBissexto(ano)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 30;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if(ano1 > ano2) {
        return 1;
    } else if(ano1 < ano2) {
        return -1;
    } else {
        if(mes1 > mes2) {
            return 1;
        } else if(mes1 < mes2) {
            return -1;
        } else {
            if(dia1 > dia2) {
                return 1;
            } else if(dia1 < dia2) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

int calculaDiasAteMes(int mes, int ano) {
    int somaDias = 0, mesAtual = 1;
    while( !(mesAtual == mes) ) { // quando chegar no 1, é pq. chegou no mes
        somaDias += numeroDiasMes(mesAtual, ano);
        mesAtual++;
    }
    return somaDias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int diaM, diam, mesM, mesm, anoM, anom;
    int soma = 0;
    int comp = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
    if(comp == 0) {
        return 0;
    } else if(comp == 1) {
        diaM = dia1;
        mesM = mes1;
        anoM = ano1;
        diam = dia2;
        mesm = mes2;
        anom = ano2;
    } else {
        diaM = dia2;
        mesM = mes2;
        anoM = ano2;
        diam = dia1;
        mesm = mes1;
        anom = ano1;
    }

    if(anom < anoM) {
        soma += (calculaDiasAteMes(12, anom) + 31) - (calculaDiasAteMes(mesm, anom) + diam); // a operação resulta na quantidade de dias ateh o fim no anom
        anom++; // vai para o próximo ano
        while (anom != anoM)
        {
            soma += calculaDiasAteMes(12, anom); // soma os dias ateh dezembro
            soma += 31; // soma os 31 dias de dezembro
            anom++; // vai para o próximo ano
        }
        soma += calculaDiasAteMes(mesM, anom) + diaM; // soma os dias ateh o mes da data maior e depois soma com o dia da data maior
        return soma;
    } else { // as datas estao no mesmo ano
        soma += (calculaDiasAteMes(mesM, anoM) + diaM) - (calculaDiasAteMes(mesm, anom) + diam);
        return soma; 
    }

}
