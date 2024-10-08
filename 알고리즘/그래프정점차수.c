#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphType {
	int n;
	int degree[MAX_VERTICES];
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void init(GraphType* g) {
	g->n = 0;
	int r, c;
	for (r = 0; r < MAX_VERTICES; r++) {
		for (c = 0; c < MAX_VERTICES; c++) {
			g->adj_mat[r][c] = 0;
		}
		g->degree[r] = 0;
	}

}
void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) {
		fprintf(stderr, "洹몃옒??: ?뺤젏??媛쒖닔 珥덇낵");
		return;		
	}
	g->n++;
}
void insert_edge(GraphType* g, int start, int end) {
	if (start >= MAX_VERTICES || end >= MAX_VERTICES) {
		fprintf(stderr, "洹몃옒??: ?뺤젏 踰덊샇 ?ㅻ쪟");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
	g->degree[start]++;
	g->degree[end]++;
}
int get_degree(GraphType* g, int index) {
	return g->degree[index];
}
void print_adj_mat(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);

	for (int i = 0; i < 4; i++) {
		printf("정점 %d의 차수 : %d\n", i, g->degree[i]);
	}
	free(g);
}
