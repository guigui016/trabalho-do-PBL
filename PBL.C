#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int dia, mes, ano;
    float peso;
    char sexo;
    int microcefalia;
    int problema_cardiaco;
    int diabetes;
    int plano_saude;
} Crianca;

void cadastrarCrianca(Crianca *c) {
    printf("Nome: ");
    getchar(); // Para consumir o newline anterior
    scanf("%[^\n]", c->nome);
    printf("Data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &c->dia, &c->mes, &c->ano);
    printf("Peso: ");
    scanf("%f", &c->peso);
    printf("Sexo (M/F): ");
    scanf(" %c", &c->sexo);
    printf("Possui microcefalia (1-sim, 0-nao): ");
    scanf("%d", &c->microcefalia);
    printf("Possui problema cardiaco (1-sim, 0-nao): ");
    scanf("%d", &c->problema_cardiaco);
    printf("Possui diabetes (1-sim, 0-nao): ");
    scanf("%d", &c->diabetes);
    printf("Possui plano de saude (1-sim, 0-nao): ");
    scanf("%d", &c->plano_saude);
}

void gerarRelatorio(Crianca criancas[], int total) {
    int i, nascidosAnoCorrente = 0, microcefalia = 0, problemaCardiaco = 0;
    int semPlanoSaude = 0, meninas = 0, meninos = 0;
    int anoCorrente = 2024;
    
    for (i = 0; i < total; i++) {
        if (criancas[i].ano == anoCorrente) nascidosAnoCorrente++;
        if (criancas[i].microcefalia) microcefalia++;
        if (criancas[i].problema_cardiaco) problemaCardiaco++;
        if (!criancas[i].plano_saude) semPlanoSaude++;
        if (criancas[i].sexo == 'F' || criancas[i].sexo == 'f') meninas++;
        if (criancas[i].sexo == 'M' || criancas[i].sexo == 'm') meninos++;
    }
    
    printf("\nRelatorio:\n");
    printf("1- Quantas criancas foram cadastradas: %d\n", total);
    printf("2- Quantas criancas nasceram no ano corrente: %d\n", nascidosAnoCorrente);
    printf("3- Percentual de criancas com microcefalia: %.2f%%\n", (microcefalia / (float)total) * 100);
    printf("4- Percentual de criancas com problema cardiaco: %.2f%%\n", (problemaCardiaco / (float)total) * 100);
    printf("5- Percentual de criancas sem plano de saude: %.2f%%\n", (semPlanoSaude / (float)total) * 100);
    printf("6- Percentual de meninas: %.2f%%\n", (meninas / (float)total) * 100);
    printf("7- Percentual de meninos: %.2f%%\n", (meninos / (float)total) * 100);
}

int main() {
    Crianca criancas[1000];
    int total = 0, opcao;
    
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar crianca\n");
        printf("2. Gerar relatorio\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                if (total < 1000) {
                    cadastrarCrianca(&criancas[total]);
                    total++;
                } else {
                    printf("Limite de 1000 criancas atingido.\n");
                }
                break;
            case 2:
                gerarRelatorio(criancas, total);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 3);
    
    return 0;
}