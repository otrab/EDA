#include <stdio.h>
#include <stdlib.h>

#define V 3      // Número de vértices
#define MAX_EDGES 10 // Máximo de aristas por vértice

// Estructura para representar una arista con peso
typedef struct {
    int vertex;
    int weight;
} Edge;

// Lista de adyacencia
typedef struct {
    Edge edges[MAX_EDGES];
    int edge_count;
} AdjList;

void addEdge(AdjList adj[], int u, int v, int w) {
    adj[u].edges[adj[u].edge_count].vertex = v;
    adj[u].edges[adj[u].edge_count].weight = w;
    adj[u].edge_count++;

    adj[v].edges[adj[v].edge_count].vertex = u;
    adj[v].edges[adj[v].edge_count].weight = w;
    adj[v].edge_count++;
}

void displayAdjList(AdjList adj[]) {
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < adj[i].edge_count; j++) {
            printf("{%d, %d} ", adj[i].edges[j].vertex, adj[i].edges[j].weight);
        }
        printf("\n");
    }
}

int main() {
    AdjList adj[V] = {0};

    addEdge(adj, 1, 0, 4);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 0, 1);

    printf("Adjacency List Representation:\n");
    displayAdjList(adj);

    return 0;
}