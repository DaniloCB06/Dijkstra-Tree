#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5 

typedef struct _viz Viz;

struct _viz {
    int noj;       // Nó de destino
    float peso;    // Peso da aresta
    Viz* prox;     // Próximo nó na lista de adjacência
};

typedef struct _grafo {
    int nv;        // Número de nós ou vértices
    int na;        // Número de arestas
    Viz** viz;     // Array de listas de adjacências
} Grafo;

// Função para criar um novo nó na lista de adjacência
Viz* novoViz(int noj, float peso) {
    Viz* novo = (Viz*) malloc(sizeof(Viz));
    novo->noj = noj;
    novo->peso = peso;
    novo->prox = NULL;
    return novo;
}

int procuraMenor(int* vetor, int size, int* visitados) {
    int menor = 1000000;
    int indMenor = -1;
    for (int i = 0; i < size; i++) {
        if (vetor[i] < menor && visitados[i] != 1) {
            menor = vetor[i];
            indMenor = i;
        }
    }
    return indMenor;
}

int verificaVetor(int* vetor, int size) {
    for (int i = 0; i < size; i++) {
        if (vetor[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void exibeVetor(int* vetor, int size) {
    for (int i = 0; i < size; i++) {
        if (vetor[i] == 1000000) {
            printf("No %d: infinito\n", i);
        }
        else {
            printf("No %d: %d\n", i, vetor[i]);
        }
    }

    return;
}

void visitaGrafo(Grafo* grafo, int* vetor, int ind, int* visitados) {
    Viz* no = grafo->viz[ind];
    int somaDistancia;
    while (no != NULL) {
        somaDistancia = vetor[ind] + no->peso;
        if (visitados[no->noj] != 1 && vetor[no->noj] > somaDistancia) {  // Verifica se o nó não foi visitado e se a nova distância é menor
            vetor[no->noj] = somaDistancia;
        }
        no = no->prox;
    }
    return;
}

void dijkstra(Grafo* grafo) {
    int* vetor = (int*)malloc(sizeof(int) * (grafo->nv));
    int* visitados = (int*)malloc(sizeof(int) * (grafo->nv));
    Viz* aux;
    int indMenor;

    if (visitados == NULL) {
        printf("Erro alocando vetor de visitados na funcao de dijkstra\n");
        exit(1);
    }

    if (vetor == NULL) {
        printf("Erro alocando vetor na funcao de dijkstra\n");
        exit(1);
    }

    for (int i = 0; i < grafo->nv; i++) {
        vetor[i] = 1000000; // Numero grande para representar infinito
        visitados[i] = 0;
    }

    vetor[0] = 0;
    
    int passos = 1;
    
    while (1==1) {
        printf("\n------ Passo %d ------\n", passos);
        exibeVetor(vetor, grafo->nv);
        passos++;
        indMenor = procuraMenor(vetor, grafo->nv, visitados);
        if (indMenor == -1) {
            break; // Fim do processo de geração de Dijkstra
        }
        visitados[indMenor] = 1; // Indica que o nó foi visitado
        visitaGrafo(grafo, vetor, indMenor, visitados);
    }
    
    
    return;
}

void liberaMemoria(Grafo* grafo){
    for (int i = 0; i < MAX_VERTICES; ++i) {
        Viz* p = grafo->viz[i];
        while (p != NULL) {
            Viz* temp = p;
            p = p->prox;
            free(temp);
        }
    }

    free(grafo->viz);
    free(grafo);
    printf("\nMemoria liberada com sucesso!");
    return;
}

int main() {
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    if (grafo == NULL){
        printf("Erro em alocar memoria\n");
        exit(1);
    }
    
    grafo->nv = MAX_VERTICES;
    grafo->na = 0;

    // Aloca memória para o array de listas de adjacências
    grafo->viz = (Viz**) malloc(MAX_VERTICES * sizeof(Viz*));

    // Inicializa cada lista de adjacência como vazia
    for (int i = 0; i < MAX_VERTICES; ++i) {
        grafo->viz[i] = NULL;
    }

    // Adiciona arestas "na mão" conforme o grafo fornecido
    Viz* novo;

    // Aresta de 0 para 1
    novo = novoViz(1, 2);
    novo->prox = grafo->viz[0];
    grafo->viz[0] = novo;

    // Aresta de 0 para 4
    novo = novoViz(4, 1);
    novo->prox = grafo->viz[0];
    grafo->viz[0] = novo;

    // Aresta de 1 para 2
    novo = novoViz(2, 3);
    novo->prox = grafo->viz[1];
    grafo->viz[1] = novo;

    // Aresta de 1 para 4
    novo = novoViz(4, 7);
    novo->prox = grafo->viz[1];
    grafo->viz[1] = novo;

    // Aresta de 2 para 3
    novo = novoViz(3, 4);
    novo->prox = grafo->viz[2];
    grafo->viz[2] = novo;

    // Aresta de 3 para 4
    novo = novoViz(4, 5);
    novo->prox = grafo->viz[3];
    grafo->viz[3] = novo;

    // Aresta de 4 para 2
    novo = novoViz(2, 6);
    novo->prox = grafo->viz[4];
    grafo->viz[4] = novo;

    dijkstra(grafo);

    liberaMemoria(grafo);

    return 0;
}
