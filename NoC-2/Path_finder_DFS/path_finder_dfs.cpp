// C++ program to print all paths from a source to destination.
#include<iostream>
#include <list>
using namespace std;
 
// A directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists
 
    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &);
 
public:
    Graph(int V);   // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}
 
// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
 
    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty
 
    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}
 
// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, int s, bool visited[],
                              int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    // If current vertex is same as destination, then print
    // current path[]
    if (u == s)
    {
        for (int i = 1; i<path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else if (u == d) // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }
    else
    {
    	for (int i = 1; i<path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    	
	}
 
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}
 
// Driver program
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
 
    int s = 1, d = 5;
    cout << "Following are all different paths from " << s
         << " to " << d << endl;
    g.printAllPaths(s, d);
 
    return 0;
}
