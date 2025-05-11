#include <stdio.h>
#include <stdlib.h>

struct no{
	int dado;
	struct no *ptr_no;
};

struct Descritor
{
    int nos;
    int inseridos;
    int removidos;
} descritor = {0, 0, 0};

struct no* inserirNo(struct no *inicio, int valor, int pos) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    novo->dado = valor;
    novo->ptr_no = NULL;

    if (pos == 0 || inicio == NULL) {
        novo->ptr_no = inicio;
        descritor.inseridos++;
        descritor.nos++;
        return novo;
    }

    struct no *aux = inicio;
    int i = 0;
    while (aux != NULL && i < pos - 1) {
        aux = aux->ptr_no;
        i++;
    }

    if (aux == NULL) {
        printf("Posição inválida. Inserindo no final.\n");
        aux = inicio;
        while (aux->ptr_no != NULL) aux = aux->ptr_no;
        aux->ptr_no = novo;
    } else {
        novo->ptr_no = aux->ptr_no;
        aux->ptr_no = novo;
    }
    descritor.inseridos++;
    descritor.nos++;
    return inicio;
}

struct no* removerNo(struct no *inicio, int pos) {
    if (inicio == NULL) return NULL;

    struct no *temp;
    if (pos == 0) {
        temp = inicio;
        inicio = inicio->ptr_no;
        free(temp);
       descritor.removidos++;
    descritor.nos--;
    return inicio;
    }

    struct no *aux = inicio;
    int i = 0;
    while (aux->ptr_no != NULL && i < pos - 1) {
        aux = aux->ptr_no;
        i++;
    }

    if (aux->ptr_no == NULL) {
        printf("Posição inválida para remoção.\n");
        return inicio;
    }

    temp = aux->ptr_no;
    aux->ptr_no = temp->ptr_no;
    free(temp);

    descritor.removidos++;
    descritor.nos--;
    return inicio;
}

void MostraLista(struct no *inicio) {
    struct no *aux = inicio;
    while (aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->ptr_no;
    }
    printf("\n");
}

void mostraDescritor() {
    printf("Número de nós: %d\n", descritor.nos);
    printf("Nós inseridos: %d\n", descritor.inseridos);
    printf("Nós removidos: %d\n", descritor.removidos);
}

int main()
{
    struct no *inicio = NULL;

    int escolha, valor, pos, qtd;

    printf("O QUE DESEJA FAZER?\n");
        printf("1 - Inserir nós\n");
        printf("2 - Remover nó\n");
        printf("3 - Imprimir lista e Descritor\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        while (escolha != 0) {
            switch (escolha) {
                case 1:
                    printf("Quantos nós deseja inserir? ");
                    scanf("%d", &qtd);
                    if (qtd> 10) {
                        printf("Número máximo de nós é 10.\n");
                        qtd = 10;
                    }
                    for (int i = 0; i < qtd; i++) {
                        printf("Valor do nó %d: ", i + 1);
                        scanf("%d", &valor);
                        printf("Posição do nó %d: ", i + 1);
                        scanf("%d", &pos);
                        inicio = inserirNo(inicio, valor, pos);
                    }
                    break;
                case 2:
                    printf("Posição do nó a remover: ");
                    scanf("%d", &pos);
                    inicio = removerNo(inicio, pos);
                    break;
                case 3:
                    MostraLista(inicio);
                    mostraDescritor();
                    break;
                default:
                    printf("Opção inválida.\n");
            }
            printf("Escolha: ");
            scanf("%d", &escolha);
        }
    return 0;
}