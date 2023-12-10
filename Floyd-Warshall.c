#include<stdio.h>
#include<stdlib.h>

#define INF 9999
#define MAX_SIZE 100

void floydWarshall(int graph[MAX_SIZE][MAX_SIZE], int size) {
    int dist[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("(%d):", i);
        for (int j = 0; j < size; j++) {
            printf(" %d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter the size of matrix >> ");
    scanf("%d", &size);

    int graph[MAX_SIZE][MAX_SIZE];

    printf("Enter %d integers >> ", size * size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, size);

    return 0;
}
