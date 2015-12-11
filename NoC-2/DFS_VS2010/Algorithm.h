#include "Network.h"

#ifndef ALGORITHM_H
#define	ALGORITHM_H

class Algorithm
{
public:    
    
    Algorithm() {}    
    
    Algorithm( Network* network );
    
    void GetAllPaths( Network* network, 
                      const std::string& start, 
                      const std::string& target,
                      const int& max_hops,
					  const int& min_hops );

	void GetAllPaths( Network* network, 
                      const int& start, 
                      const int& target,
                      const int& max_hops,
					  const int& min_hops );

	void Dijkstra( Network* network,
		           const int& start,
				   const int& target );
        
    
private:
    
    void DepthFirst( Network* network, 
                      Path& visited, 
                      const int& end,
                      const int& max_hops,
					  const int& min_hops );
    
    void SetNetwork( Network* network );
    bool ContainsNode( Path& nodes, const int& node );
    
    Network *nw;   
	int startNodeId;
};

#endif	/* ALGORITHM_H */

