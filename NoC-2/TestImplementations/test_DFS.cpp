#include <iostream> 
#include <vector> 
#include <stack>
using namespace std; 
  
class Graph { 
public: 
    Graph(int n) : g(n) {} 
    
    void add(int from, int to) { 
        g[from].push_back(to); g[to].push_back(from); } 
    
public:
    void print_path() {  
        for(int i = 0; i < path.size(); i++) {
        	cout << path[i] << ' ';
        }
        cout << endl; 
    }
    void traverse(int source, int dest) {
		DFS(source, dest);
    }  
private:
    void DFS(int u, int dest) {
		path.push_back(u);
		
		if (u == dest) {
	    	print_path();
		}
		else {
			for (auto v : g[u]) {
				bool stop = false;
		    	
		    	for(auto s : path) {
		    		if(s == v) {
		    			stop = true;
		    		}
		    	}
		    
		    	if(!stop) {
		    		DFS(v, dest);
		    	}
	    	}
		}
    	path.pop_back();
    }
    
    vector<vector<int> > g;
    vector<int> path; 
}; 
  
int main() { 
    // your code goes here 
    
    Graph g(8); 
    
    //g.add(0, 7); 
    g.add(0, 4); 
    
    //g.add(1, 2); 
    //g.add(1, 7); 
    
    //g.add(2, 7);    
    //g.add(2, 1); 
    //g.add(2, 5); 
    
    // no node with 3 
    
    g.add(4, 0); 
    g.add(4, 5);    
    g.add(4, 6); 
    
    g.add(5, 4); 
    //g.add(5, 2); 
    g.add(5, 6);    
    
    g.add(6, 4);    
    g.add(6, 5); 
    
    //g.add(7, 2);    
    //g.add(7, 1);    
    //g.add(7, 0);        
    
    g.traverse(0, 6); 
    
    return 0; 
}
