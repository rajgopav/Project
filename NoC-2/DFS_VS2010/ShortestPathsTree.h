#include "Graph.h"

template <class DenseGRAPH, class Edge> 
class ShortestPathsTree
{ 
private:

	const DenseGRAPH &G;
	std::vector<double> wt;
	std::vector<EdgePtr> spt;

public:

	ShortestPathsTree(const DenseGRAPH &G, int s) : 
					  G(G), 
					  spt(G.V()), 
					  wt(G.V(), 
					  G.V())
	{ 
		PriorityQueue<double> pQ(G.V(), wt);
	
		for ( int v = 0; v < G.V(); v++ ) pQ.insert(v);
	
		wt[s] = 0.0; 
		pQ.lower(s);  

		while ( !pQ.empty() ) 
		{ 
			int v = pQ.getmin(); 
			
			if ( v != s && spt[v] == 0 ) 
			{
				return;  
			}

			typename DenseGRAPH::adjIterator A(G, v); 
      
			for ( EdgePtr e = A.beg(); !A.end(); e = A.nxt() ) 
			{ 
				int w = e->w; 
				double P = wt[v] + e->wt;
				
				if (P < wt[w]) 
				{ 
					wt[w] = P; 
					pQ.lower(w); 
					spt[w] = e; 
				}
			}
		}
	}
	
	EdgePtr pathR(int v) const { return spt[v]; }
	double dist(int v) const { return wt[v]; }
};