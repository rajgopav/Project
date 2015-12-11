// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include<iostream>
#include <list>
 
using namespace std;
 
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
      Graph g(64);
    //ring 1
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
	g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 15);
    g.addEdge(15, 23);
    g.addEdge(23, 31);
    g.addEdge(31, 39);
    g.addEdge(39, 47);
    g.addEdge(47, 55);
    g.addEdge(55, 63);
    g.addEdge(63, 62);
    g.addEdge(62, 61);
    g.addEdge(61, 60);
    g.addEdge(60, 59);
    g.addEdge(59, 58);
    g.addEdge(58, 57); 
	g.addEdge(57, 56);
    g.addEdge(56, 48);
    g.addEdge(48, 40);
    g.addEdge(40, 32);
    g.addEdge(32, 24);
    g.addEdge(24, 16);
    g.addEdge(16, 8);
    g.addEdge(8, 0);
    
	//ring 2
	g.addEdge(6, 14);
    g.addEdge(14, 22);
    g.addEdge(22, 30);
    g.addEdge(30, 38);
    g.addEdge(38, 46);
    g.addEdge(46, 54);
    g.addEdge(54, 53);
    g.addEdge(53, 52);
	g.addEdge(52, 51);
    g.addEdge(51, 50);
    g.addEdge(50, 49);
    g.addEdge(49, 18);
    
    //ring 3
    g.addEdge(5, 13);
	g.addEdge(13, 21);
    g.addEdge(21, 29);
    g.addEdge(29, 37);
	g.addEdge(37, 45);
	g.addEdge(45, 44);
    g.addEdge(44, 43);
    g.addEdge(43, 42);
	g.addEdge(42, 41);
    g.addEdge(41, 40);
    
    //ring 4
    
    g.addEdge(4, 12);
	g.addEdge(12, 20);
	g.addEdge(20, 28);
	g.addEdge(28, 36);
    g.addEdge(36, 35);
	g.addEdge(35, 34);
    g.addEdge(34, 33);
    g.addEdge(33, 32);
    
    //ring 5
    
	g.addEdge(3, 11);
	g.addEdge(11, 19);
    g.addEdge(19, 27);
	g.addEdge(27, 26);
	g.addEdge(26, 25);
	g.addEdge(25, 24);
	
	//ring 6
	
	g.addEdge(2, 10);
	g.addEdge(10, 18);
	g.addEdge(18, 17);
	g.addEdge(17, 16);
	
	//ring 7
	
	g.addEdge(1, 9);
	g.addEdge(9, 8);
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
