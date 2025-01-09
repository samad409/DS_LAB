#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 10
struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int reverseAdjMatrix[MAX_VERTICES][MAX_VERTICES]; // Reversed adjacency matrix
};
void initGraph(struct Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
            graph->reverseAdjMatrix[i][j] = 0;
        }
    }
}
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;  
    graph->reverseAdjMatrix[dest][src] = 1;
}
void DFS(struct Graph* graph, int vertex, bool visited[], int stack[], int* stackIndex, int adjMatrix[MAX_VERTICES][MAX_VERTICES]) {
    visited[vertex] = true;
    for (int i = 0; i < graph->numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited, stack, stackIndex, adjMatrix);
        }
    }
    stack[*stackIndex] = vertex;
    (*stackIndex)++;
}
void DFSReverse(struct Graph* graph, int vertex, bool visited[], int* component, int reverseAdjMatrix[MAX_VERTICES][MAX_VERTICES]) {
    visited[vertex] = true;
    component[vertex] = 1;  // Mark the vertex as part of the current SCC
    for (int i = 0; i < graph->numVertices; i++) {
        if (reverseAdjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSReverse(graph, i, visited, component, reverseAdjMatrix);
        }
    }
}
void kosarajuSCC(struct Graph* graph) {
    bool visited[MAX_VERTICES] = { false };
    int stack[MAX_VERTICES];
    int stackIndex = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack, &stackIndex, graph->adjMatrix);
        }
    }
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;  // Reset visited array
    }
    printf("Strongly Connected Components (SCCs):\n");
    while (stackIndex > 0) {
        int vertex = stack[--stackIndex];
        if (!visited[vertex]) {
            int component[MAX_VERTICES] = { 0 }; // To track the SCC
            DFSReverse(graph, vertex, visited, component, graph->reverseAdjMatrix);
            printf("{ ");
            for (int i = 0; i < graph->numVertices; i++) {
                if (component[i]) {
                    printf("%d ", i);
                }
            }
            printf("}\n");
        }
    }
}
void displayGraph(struct Graph* graph) {
    printf("\nGraph Representation (Adjacency Matrix):\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    struct Graph graph;
    int vertices, edges, src, dest, choice;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&graph, vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            addEdge(&graph, src, dest);
        } else {
            printf("Invalid edge! Please enter vertices within the range of 0 to %d.\n", vertices - 1);
            i--;  // Decrement i to allow user to input the edge again
        }
    }
    do {
        printf("\nMenu:\n");
        printf("1. Display Graph\n");
        printf("2. Find Strongly Connected Components (SCCs)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayGraph(&graph);
                break;
            case 2:
                kosarajuSCC(&graph);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}
