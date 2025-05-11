#include <stdio.h>
#include <stdlib.h>

struct no{
	int dado;
	struct no *anterior;
    struct no *proximo;
};

struct no* inserirNo(struct no *inicio, int valor, int pos) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    novo->dado = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;

    if (inicio == NULL) {
        return novo;
    }

    if (pos == 0) {
        novo->proximo = inicio;
        inicio->anterior = novo;
        return novo;
    }

    struct no *aux = inicio;
    int i = 0;
    while (aux->proximo != NULL && i < pos - 1) {
        aux = aux->proximo;
        i++;
    }

    novo->proximo = aux->proximo;
    if (aux->proximo != NULL) {
        aux->proximo->anterior = novo;
    }
    aux->proximo = novo;
    novo->anterior = aux;

    return inicio;
}

struct no* removerNo(struct no *inicio, int pos) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    struct no *aux = inicio;
    int i = 0;

    while (aux != NULL && i < pos) {
        aux = aux->proximo;
        i++;
    }

    if (aux == NULL) {
        printf("Posição inválida.\n");
        return inicio;
    }

    if (aux->anterior != NULL) {
        aux->anterior->proximo = aux->proximo;
    } else {
        inicio = aux->proximo;
    }

    if (aux->proximo != NULL) {
        aux->proximo->anterior = aux->anterior;
    }

    free(aux);
    return inicio;
}

void mostraLista(struct no *inicio) {
    struct no *aux = inicio;
    if (aux == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    printf("Lista: ");
    while (aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->proximo;
    }
    printf("\n");
}

int main()
{
    struct no *inicio = NULL;

    int escolha, valor, pos, qtd;

    printf("O QUE DESEJA FAZER?\n");
        printf("1 - Inserir nós\n");
        printf("2 - Remover nó\n");
        printf("3 - Imprimir lista\n");
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
                    mostraLista(inicio);
                    break;
                default:
                    printf("Opção inválida.\n");
            }
            printf("Escolha: ");
            scanf("%d", &escolha);
        }
    return 0;
}