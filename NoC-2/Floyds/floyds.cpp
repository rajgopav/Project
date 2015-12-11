// A C Program to demonstrate adjacency list representation of graphs
 
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent an adjacency list node
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};
 
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
 
// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 64;
    struct Graph* graph = createGraph(V);
    
  //ring 1
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 15);
    addEdge(graph, 15, 23);
    addEdge(graph, 23, 31);
    addEdge(graph, 31, 39);
    addEdge(graph, 39, 47);
    addEdge(graph, 47, 55);
    addEdge(graph, 55, 63);
    addEdge(graph, 63, 62);
    addEdge(graph, 62, 61);
    addEdge(graph, 61, 60);
    addEdge(graph, 60, 59);
    addEdge(graph, 59, 58);
    addEdge(graph, 58, 57); 
	addEdge(graph, 57, 56);
    addEdge(graph, 56, 48);
    addEdge(graph, 48, 40);
    addEdge(graph, 40, 32);
    addEdge(graph, 32, 24);
    addEdge(graph, 24, 16);
    addEdge(graph, 16, 8);
    addEdge(graph, 8, 0);
    
	//ring 2
	addEdge(graph, 6, 14);
    addEdge(graph, 14, 22);
    addEdge(graph, 22, 30);
    addEdge(graph, 30, 38);
    addEdge(graph, 38, 46);
    addEdge(graph, 46, 54);
    addEdge(graph, 54, 53);
    addEdge(graph, 53, 52);
	addEdge(graph, 52, 51);
    addEdge(graph, 51, 50);
    addEdge(graph, 50, 49);
    addEdge(graph, 49, 18);
    
    //ring 3
    addEdge(graph, 5, 13);
	addEdge(graph, 13, 21);
    addEdge(graph, 21, 29);
    addEdge(graph, 29, 37);
	addEdge(graph, 37, 45);
	addEdge(graph, 45, 44);
    addEdge(graph, 44, 43);
    addEdge(graph, 43, 42);
	addEdge(graph, 42, 41);
    addEdge(graph, 41, 40);
    
    //ring 4
    
    addEdge(graph, 4, 12);
	addEdge(graph, 12, 20);
	addEdge(graph, 20, 28);
	addEdge(graph, 28, 36);
    addEdge(graph, 36, 35);
	addEdge(graph, 35, 34);
    addEdge(graph, 34, 33);
    addEdge(graph, 33, 32);
    
    //ring 5
    
	addEdge(graph, 3, 11);
	addEdge(graph, 11, 19);
    addEdge(graph, 19, 27);
	addEdge(graph, 27, 26);
	addEdge(graph, 26, 25);
	addEdge(graph, 25, 24);
	
	//ring 6
	
	addEdge(graph, 2, 10);
	addEdge(graph, 10, 18);
	addEdge(graph, 18, 17);
	addEdge(graph, 17, 16);
	
	//ring 7
	
	addEdge(graph, 1, 9);
	addEdge(graph, 9, 8);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}
