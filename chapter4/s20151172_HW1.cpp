#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void MST_Kruskal(int N_v, int** A, int* mst);

int main(void) {
	
	int N_v;
	int** A;
	int* mst;

	// file open to read
	FILE* graph = fopen("In_Kruskal.txt","r");
	if (graph == NULL) {
		printf("error");
		return 0;
	}

	// assign the number of vertex on N_v
	fscanf(graph, "%d", &N_v);
	printf("Vertex : %d\n\n", N_v);

	// map adjacency matrix on A
	int i, j;

	A = (int**)malloc(sizeof(int*) * N_v);
	for (i = 0; i < N_v; i++) {
		A[i] = (int*)malloc(sizeof(int) * N_v);
	}

	for (i = 0; i < N_v; i++) {
		for (j = 0; j < N_v; j++) {
			fscanf(graph, "%d", &A[i][j]);			
		}
	}

	fclose(graph);

	printf("Adjacency Matrix\n\n");
	for (i = 0; i < N_v; i++) {
		for (j = 0; j < N_v; j++) {
			printf("%6d ", A[i][j]);
		}
		printf("\n");
	}

	// intialize mst
	mst = (int*)malloc(sizeof(int) * N_v);
	for (i = 0; i < N_v; i++) {
		mst[i] = 9999;
	}

	// do kruskal
	printf("\n\nStart Kruskal MST\n\n");
	MST_Kruskal(N_v, A, mst);

	// filter overlapped data and check
	for (i = 0; i < N_v; i++) {
		if (mst[mst[i]] == i) {
			mst[i] = i;
		}
	}

	printf("The Index of Vertexes in MST\n\n");
	for (i = 0; i < N_v; i++) {
		if (mst[i] != i) {
			printf("%d %d\n", i, mst[i]);
		}
	}

	// output without overlapped data
	FILE* graph2 = fopen("Out_Kruskal.txt", "wt");
	if (graph2 == NULL) {
		printf("error");
		return 0;
	}

	for (i = 0; i < N_v; i++) {
		if (mst[i] != i) {
			fprintf(graph2, "%d %d\n", i, mst[i]);
		}
	}

	fclose(graph2);

	printf("\nOut_Kruskal.txt is completely made.\n");

	for (i = 0; i < N_v; i++) {
		free(A[i]);
	}
	free(A);
	
	return 0;
}

void MST_Kruskal(int N_v, int** A, int* mst) {

	int i, j;
	int edge = 0;



	// edge count	
	for (i = 0; i < N_v; i++) {
		for (j = i; j < N_v; j++) {
			if (A[i][j] != 0 && A[i][j] != 9999) {
				edge++;
			}
		}
	}

	// make list of edges
	int** edges = (int**)malloc(sizeof(int) * edge);
	for (i = 0; i < edge; i++) {
		edges[i] = (int*)malloc(sizeof(int) * 3);
	}

	int cnt = 0;

	for (i = 0; i < N_v; i++) {
		for (j = i; j < N_v; j++) {
			if (A[i][j] != 0 && A[i][j] != 9999) {
				edges[cnt][0] = i;
				edges[cnt][1] = j;
				edges[cnt][2] = A[i][j];
				cnt++;
			}
		}
	}

	// bubble sort by cost

	int tempfrom, tempto, tempcost;

	for (i = edge-1; i >0; i--) {
		for (j = 0; j < i; j++) {
			if (edges[j][2] > edges[j + 1][2]) {
				tempfrom = edges[j][0];
				tempto = edges[j][1];
				tempcost = edges[j][2];
				edges[j][0] = edges[j + 1][0];
				edges[j][1] = edges[j + 1][1];
				edges[j][2] = edges[j + 1][2];
				edges[j + 1][0] = tempfrom;
				edges[j + 1][1] = tempto;
				edges[j + 1][2] = tempcost;
			}
		}
	}

	// make Disjointset array for checking a cycle

	int* set = (int*)malloc(sizeof(int) * N_v);
	for (i = 0; i < N_v; i++ ){
		set[i] = i;
	}

	// assign edges in mst
	
	for (i = 0; i < edge; i++) {

		// printf("now in %dth edge\n\n", i+1);

		int e1 = edges[i][0];
		int e2 = edges[i][1];
		int s1 = set[e1];
		int s2 = set[e2];

		if (set[e1] != set[e2]) { // if no cycle
			for (j = 0; j < N_v; j++) {
				if (set[j] == s2) {
					// printf("set[%d] : %d\n\n", j, s1);
					set[j] = s1; // union
				}
			}
			/*
			printf("now set : [ ");
			for (j = 0; j < N_v; j++) {
				printf("%d ", set[j]);
			}
			printf("]\n");
			*/

			if (mst[e1] != 9999) {
			//	printf("mst[%d] : %d\n\n", e2, e1);
				mst[e2] = e1;
			}
			else {
			//	printf("mst[%d] : %d\n\n", e1, e2);
			//	printf("mst[%d] : %d\n\n", e2, e1);
				mst[e1] = e2;
				mst[e2] = e1;
			}
		}
	}

	for (i = 0; i < N_v; i++) {
		free(edges[i]);
	}
	free(edges);
}
