// A C++ program print Eulerian Trail in a given Eulerian or Semi-Eulerian Graph
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;
 
// A class that represents an undirected graph
class Graph
{
  int V;    // No. of vertices
  list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
  Graph(int V)  { this->V = V;  adj = new list<int>[V];  }
  ~Graph()      { delete [] adj;  }
 
  // functions to add and remove edge
  void addEdge(int u, int v) {  adj[u].push_back(v); adj[v].push_back(u); }
  void rmvEdge(int u, int v);
 
  // Methods to print Eulerian tour
  void printEulerTour();
  void printEulerUtil(int s);
 
  // This function returns count of vertices reachable from v. It does DFS
  int DFSCount(int v, bool visited[]);
 
  // Utility function to check if edge u-v is a valid next edge in
  // Eulerian trail or circuit
  bool isValidNextEdge(int u, int v);
};
 
/* The main function that print Eulerian Trail. It first finds an odd
   degree vertex (if there is any) and then calls printEulerUtil()
   to print the path */
void Graph::printEulerTour()
{
  // Find a vertex with odd degree
  int u = 0;
  for (int i = 0; i < V; i++)
      if (adj[i].size() & 1)
        {   u = i; break;  }
 
  // Print tour starting from oddv
  printEulerUtil(u);
  cout << endl;
}
 
// Print Euler tour starting from vertex u
void Graph::printEulerUtil(int u)
{
  // Recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i)
  {
      int v = *i;
 
      // If edge u-v is not removed and it's a a valid next edge
      if (v != -1 && isValidNextEdge(u, v))
      {
          cout << u << "-" << v << "  ";
          rmvEdge(u, v);
          printEulerUtil(v);
      }
  }
}
 
// The function to check if edge u-v can be considered as next edge in
// Euler Tout
bool Graph::isValidNextEdge(int u, int v)
{
  // The edge u-v is valid in one of the following two cases:
 
  // 1) If v is the only adjacent vertex of u
  int count = 0;  // To store count of adjacent vertices
  list<int>::iterator i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i)
     if (*i != -1)
        count++;
  if (count == 1)
    return true;
 
 
  // 2) If there are multiple adjacents, then u-v is not a bridge
  // Do following steps to check if u-v is a bridge
 
  // 2.a) count of vertices reachable from u
  bool visited[V];
  memset(visited, false, V);
  int count1 = DFSCount(u, visited);
 
  // 2.b) Remove edge (u, v) and after removing the edge, count
  // vertices reachable from u
  rmvEdge(u, v);
  memset(visited, false, V);
  int count2 = DFSCount(u, visited);
 
  // 2.c) Add the edge back to the graph
  addEdge(u, v);
 
  // 2.d) If count1 is greater, then edge (u, v) is a bridge
  return (count1 > count2)? false: true;
}
 
// This function removes edge u-v from graph.  It removes the edge by
// replacing adjcent vertex value with -1.
void Graph::rmvEdge(int u, int v)
{
  // Find v in adjacency list of u and replace it with -1
  list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
  *iv = -1;
 
  // Find u in adjacency list of v and replace it with -1
  list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
  *iu = -1;
}
 
// A DFS based function to count reachable vertices from v
int Graph::DFSCount(int v, bool visited[])
{
  // Mark the current node as visited
  visited[v] = true;
  int count = 1;
 
  // Recur for all vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (*i != -1 && !visited[*i])
          count += DFSCount(*i, visited);
 
  return count;
}
 
// Driver program to test above function
int main()
{
  // Let us first create and test graphs shown in above figure
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

    g.printEulerTour();
 
  return 0;
}





Link<int>(0, 8),

	Link<int>(0, 1),

	Link<int>(1, 9),

	Link<int>(1, 2),

	Link<int>(1, 0),

	Link<int>(2, 10),

	Link<int>(2, 3),

	Link<int>(2, 1),

	Link<int>(3, 11),

	Link<int>(3, 4),

	Link<int>(3, 2),

	/*Link<int>(4, 12),

Link<int>(4, 5),

Link<int>(4, 3),

Link<int>(5, 13),

Link<int>(5, 6),

Link<int>(5, 4),

Link<int>(6, 14),

Link<int>(6, 7),

Link<int>(6, 5),

Link<int>(7, 15),

Link<int>(7, 6),*/

	//Second row

	Link<int>(8, 16),

	Link<int>(8, 9),

	Link<int>(8, 0),

	Link<int>(9, 17),

	Link<int>(9, 10),

	Link<int>(9, 1),

	Link<int>(9, 8),

	Link<int>(10, 18),

	Link<int>(10, 11),

	Link<int>(10, 2),

	Link<int>(10, 9),

	Link<int>(11, 19),

	Link<int>(11, 12),

	Link<int>(11, 3),

	Link<int>(11, 10),

	/*Link<int>(12, 20),

Link<int>(12, 13),

Link<int>(12, 4),

Link<int>(12, 11),

Link<int>(13, 21),

Link<int>(13, 14),

Link<int>(13, 5),

Link<int>(13, 12),

Link<int>(14, 22),

Link<int>(14, 15),

Link<int>(14, 6),

Link<int>(14, 13),

Link<int>(15, 23),

Link<int>(15, 7),

Link<int>(15, 14),*/

	//Third row

	Link<int>(16, 24),

	Link<int>(16, 17),

	Link<int>(16, 8),

	Link<int>(17, 25),

	Link<int>(17, 18),

	Link<int>(17, 9),

	Link<int>(17, 16),

	Link<int>(18, 26),

	Link<int>(18, 19),

	Link<int>(18, 10),

	Link<int>(18, 17),

	Link<int>(19, 27),

	Link<int>(19, 20),

	Link<int>(19, 11),

	Link<int>(19, 18),

	/*Link<int>(20, 28),

Link<int>(20, 21),

Link<int>(20, 12),

Link<int>(20, 19),

Link<int>(21, 29),

Link<int>(21, 22),

Link<int>(21, 13),

Link<int>(21, 20),

Link<int>(22, 30),

Link<int>(22, 23),

Link<int>(22, 14),

Link<int>(22, 21),

Link<int>(23, 31),

Link<int>(23, 15),

Link<int>(23, 22),*/

	//Fourth row

	Link<int>(24, 32),

	Link<int>(24, 25),

	Link<int>(24, 16),

	Link<int>(25, 33),

	Link<int>(25, 26),

	Link<int>(25, 17),

	Link<int>(25, 24),

	Link<<
