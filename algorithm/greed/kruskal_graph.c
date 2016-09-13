/*
 *     File Name: kruskal_4.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2016年09月12日 星期一 11时45分32秒
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* edge in graph*/
struct Edge{
	int src, dest, weight;
};

/* connectd undirected graph*/
struct Graph{
	int V, E;
	struct Edge* edge;
};


struct Graph* create_graph(int V, int E)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
	return graph;
}

struct subset{
	int parent;
	int rank;

};

int find(struct subset subsets[], int i)
{
	if(subsets[i].parent != i)
		return find(subsets, subsets[i].parent);


}

void Union(struct   subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank )
		subsets[yroot].parent = xroot;
	else{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int my_cmp(const void* a, const void* b)
{
	struct  Edge* a1 = (struct Edge*)a;
	struct  Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

void kruskal(struct Graph* graph)
{
	int V = graph->V;
	struct Edge result[V];
	int e = 0;
	int i = 0;
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), my_cmp);
	struct subset *subsets = (struct subset*) malloc(V * sizeof(struct subset));
	int j;
	for(j = 0; j < V; ++j){
		subsets[j].parent = j;
		subsets[j].rank =  0;
	}
	while(e < V - 1){
		struct  Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		if(x != y){
			result[e++] = next_edge;
			Union(subsets, x, y);
		}

	}
	printf("Following are the edge in the MST\n");
	for(i = 0; i < e; ++i)
		printf("%d -- %d  ==%d\n", result[i].src, result[i].dest, result[i].weight);
	return ;

}

int main()
{
	int V = 4;
	int E = 5;
	struct Graph* graph = create_graph(V, E);


	// 0-1 
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;

/*      10
*	0 ----- 1
*   | \		|
* 6 |	5\	| 15
*	|	  \	|
*	2-------3
*		4
* 这里我们以这个图作为讲解
* 
*/
	// add 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;

	// add 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;

	//add 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;

	//add 2-3 
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	kruskal(graph);
	return 0;
}