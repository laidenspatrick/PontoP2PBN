#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no{
	int dado;
	struct no *anterior;
    struct no *proximo;
};

struct no* inserirNo(struct no *inicio, int valor) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    novo->dado = valor;

    if (inicio == NULL) {
        novo->proximo = novo;
        novo->anterior = novo;
        return novo;
    }

    struct no *ultimo = inicio->anterior;

    novo->proximo = inicio;
    novo->anterior = ultimo;
    ultimo->proximo = novo;
    inicio->anterior = novo;

    return novo;
}

void mostraLista(struct no *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    struct no *aux = inicio;
    printf("Lista: ");
    do {
        printf("%d ", aux->dado);
        aux = aux->proximo;
    } while (aux != inicio);
    printf("\n");
}


void mostraListaInversa(struct no *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    struct no *aux = inicio->anterior; 
    printf("Lista reversa: ");
    do {
        printf("%d ", aux->dado);
        aux = aux->anterior;
    } while (aux != inicio->anterior);
    printf("\n");
}

int main()
{
    srand(time(NULL));
    struct no *inicio = NULL;

    int escolha, valor, pos, qtd;

                    for (int i = 0; i < 50; i++) {
                        valor = rand() % 100;
                        inicio = inserirNo(inicio, valor);
                    }
                    mostraLista(inicio);
                    mostraListaInversa(inicio);
    return 0;
}