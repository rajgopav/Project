// C++ program to print DFS traversal from a given vertex in a  given graph
#include<iostream>
#include <list>
 
using namespace std;
 
// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
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
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}
 
int main()
{
    // Create a graph given in the above diagram
        Graph g(64);
 
   //line 1  
    g.addEdge(0, 1);
    g.addEdge(0, 8);
    g.addEdge(1, 0);
	g.addEdge(1, 2);
    g.addEdge(1, 9);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 10);
    g.addEdge(3, 4);
    g.addEdge(3, 11);
    g.addEdge(3, 2); 
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(4, 12);
    //g.addEdge(12, 4);
    g.addEdge(5, 4);
    g.addEdge(5, 13);
    g.addEdge(5, 6); 
	g.addEdge(6, 14);
    g.addEdge(6, 7);
    g.addEdge(6, 5);
    g.addEdge(7, 6);
    //Line 2
    g.addEdge(7, 15);
    g.addEdge(8, 9);
    g.addEdge(8, 0);
    g.addEdge(8, 16);
	g.addEdge(9, 8);
    g.addEdge(9, 1);
    g.addEdge(9, 10);
    g.addEdge(9, 17);
    g.addEdge(10, 9);
    g.addEdge(10, 2); 
	g.addEdge(10, 11);
    g.addEdge(10, 18);
    g.addEdge(11, 12);
	g.addEdge(11, 3);
	g.addEdge(11, 19);
    g.addEdge(11, 10);
    g.addEdge(12, 4); 
	g.addEdge(12, 13);
    g.addEdge(12, 20);
    g.addEdge(12, 11);
	g.addEdge(13, 5);
 g.addEdge(13, 14);
    g.addEdge(13, 12);
    g.addEdge(13, 21); 
	g.addEdge(14, 13);
    g.addEdge(14, 6);
    g.addEdge(14, 15);
	g.addEdge(14, 22);
 g.addEdge(15, 7);
    g.addEdge(15, 23); 
	g.addEdge(15, 14);
    //line 3
    g.addEdge(16, 8); 
	g.addEdge(16, 17);
    g.addEdge(16,24);
    g.addEdge(17, 16);
	g.addEdge(17, 9);
 g.addEdge(17, 18);
    g.addEdge(17, 25);
    g.addEdge(18, 17); 
	g.addEdge(18, 10);
    g.addEdge(18, 19);
    g.addEdge(18, 26);
	g.addEdge(19, 18);
  g.addEdge(19, 20);
    g.addEdge(19, 11); 
	g.addEdge(19, 27);
    g.addEdge(20, 12);
    g.addEdge(20, 19);
	g.addEdge(20, 21);
  g.addEdge(20, 28);
    g.addEdge(21, 22); 
	g.addEdge(21, 13);
    g.addEdge(21, 20);
    g.addEdge(21, 29);
	g.addEdge(22, 30);
    g.addEdge(22, 14);
    g.addEdge(22, 21); 
	g.addEdge(22, 23);
    g.addEdge(23, 15);
    g.addEdge(23, 22);
	g.addEdge(23, 31);
	//line 4
    g.addEdge(24, 16);
    g.addEdge(24, 25); 
	g.addEdge(24, 32);
    g.addEdge(25, 24);
    g.addEdge(25, 17);
	g.addEdge(25, 33);
    g.addEdge(25, 26);
    g.addEdge(26, 27); 
	g.addEdge(26, 25);
    g.addEdge(26, 18);
    g.addEdge(26, 34);
	g.addEdge(27, 28);
	g.addEdge(27, 26); 
	g.addEdge(27, 19);
    g.addEdge(27, 35);
    g.addEdge(28, 27);
	g.addEdge(28, 20);
	g.addEdge(28, 29); 
	g.addEdge(28, 36);
    g.addEdge(29, 28);
    g.addEdge(29, 21);
	g.addEdge(29, 30);
	g.addEdge(29, 37); 
	g.addEdge(30, 29);
    g.addEdge(30, 31);
    g.addEdge(30, 22);
	g.addEdge(30, 38);
	g.addEdge(31, 30); 
	g.addEdge(31, 23);
    g.addEdge(31, 39);
    //line 5
    g.addEdge(32, 33);
	g.addEdge(32, 24);
	g.addEdge(32, 40); 
	g.addEdge(33, 34);
    g.addEdge(33, 25);
    g.addEdge(33, 41);
	g.addEdge(33, 32);
	g.addEdge(34, 33); 
	g.addEdge(34, 35);
    g.addEdge(34, 26);
    g.addEdge(34, 42);
	g.addEdge(35, 34);
    g.addEdge(35, 36);
    g.addEdge(35, 27);
	g.addEdge(35, 43);
	g.addEdge(36, 35); 
	g.addEdge(36, 37);
    g.addEdge(36, 28);
    g.addEdge(36, 44);
	g.addEdge(37, 36);
	g.addEdge(37, 38);
    g.addEdge(37, 29);
	g.addEdge(37, 45);
	g.addEdge(38, 39); 
	g.addEdge(38, 37);
    g.addEdge(38, 30);
    g.addEdge(38, 46);
	g.addEdge(39, 31);
	g.addEdge(39, 38);
    g.addEdge(39, 47);
    //line 6
	g.addEdge(40, 32);
	g.addEdge(40, 41); 
	g.addEdge(40, 48);
    g.addEdge(41, 40);
    g.addEdge(41, 33);
	g.addEdge(41, 49);
	g.addEdge(41, 42);
    g.addEdge(42, 41);
	g.addEdge(42, 34);
	g.addEdge(42, 43); 
	g.addEdge(42, 50);
    g.addEdge(43, 44);
    g.addEdge(43, 35);
	g.addEdge(43, 51);
	g.addEdge(43, 42);
    g.addEdge(44, 45);
	g.addEdge(44, 43);
	g.addEdge(44, 36); 
	g.addEdge(44, 52);
    g.addEdge(45, 46);
    g.addEdge(45, 44);
	g.addEdge(45, 37);
	g.addEdge(45, 53);
    g.addEdge(46, 47);
	g.addEdge(46, 45);
	g.addEdge(46, 38); 
	g.addEdge(46, 54);
    g.addEdge(47, 39);
    g.addEdge(47, 46);
	g.addEdge(47, 55);
	//line 7
	g.addEdge(48, 40);
    g.addEdge(48, 56);
	g.addEdge(48, 49);
	g.addEdge(49, 50); 
	g.addEdge(49, 48);
    g.addEdge(49, 41);
    g.addEdge(49, 57);
	g.addEdge(50, 51);
	g.addEdge(50, 42);
    g.addEdge(50, 58);
	g.addEdge(50, 49);
	g.addEdge(51, 50); 
	g.addEdge(51, 43);
    g.addEdge(51, 52);
    g.addEdge(51, 59);
	g.addEdge(52, 53);
	g.addEdge(52, 44);
	g.addEdge(52, 51);
    g.addEdge(52, 60);
	g.addEdge(53, 45);
	g.addEdge(53, 61); 
	g.addEdge(53, 52);
    g.addEdge(53, 54);
    g.addEdge(54, 53);
	g.addEdge(54, 46);
	g.addEdge(54, 62);
    g.addEdge(54, 55);
	g.addEdge(55, 54);
	g.addEdge(55, 47); 
	g.addEdge(55, 63);
	//line 8
    g.addEdge(56, 48);
    g.addEdge(56, 57);
	g.addEdge(57, 56);
	g.addEdge(57, 49); 
	g.addEdge(57, 58);
    g.addEdge(58, 57);
	g.addEdge(58, 50);
	g.addEdge(58, 59); 
	g.addEdge(59, 58);
    g.addEdge(59, 60);
    g.addEdge(59, 51);
	g.addEdge(60, 59);
    g.addEdge(60, 52); 
	g.addEdge(60, 61);
    g.addEdge(61, 60);
    g.addEdge(61, 62); 
    g.addEdge(61, 53);
	g.addEdge(62, 54);
	g.addEdge(62, 61);
    g.addEdge(62, 63);
    g.addEdge(63, 62);
	g.addEdge(63, 55);
	
    cout << "Following is Depth First Traversal (starting from vertex 6) \n";
    g.DFS(0);
 
    return 0;
}
