#include <iostream>
#include <sstream>
#include <iterator>
#include "Algorithm.h"


Algorithm::Algorithm( Network* network )
{
    SetNetwork( network );
}

void Algorithm::SetNetwork( Network* network )
{    
    nw = network;
}

// Algorithm to recursively search for all paths between
// chosen source - destination nodes
void Algorithm::DepthFirst( Network* network, 
                             Path& visited, 
                             const int& end,
                             const int& max_hops,
							 const int& min_hops)
{
    const int back = visited.back();

    std::vector< int > adjNode = network->GetAdjNodeIDs( back );

    // Examine adjacent nodes
    for ( std::vector<int>::const_iterator node_it = adjNode.begin();
          node_it != adjNode.end();
          node_it++ )
    {	
        const int node = (*node_it);

		bool startEqualTarget = ContainsNode( visited, node ) &&
			startNodeId == end &&
			node == startNodeId;

        if ( ContainsNode( visited, node ) && !startEqualTarget ) continue;

        if ( node == end )
        {
            visited.push_back( *node_it );

            // Get hop count for this path
            const int size = (int) visited.size();
			const int hops = size - 1;
              
            if ( (  max_hops < 1 || hops <= max_hops ) && hops >= min_hops )
            {   
                Path path( visited.begin(), visited.begin() + size );
                network->AddPath( path );
            }           
           		            
            visited.erase( visited.begin() + hops );

            break;
        }			
    }


    // in breadth-first, recursion needs to come after visiting adjacent nodes
    for ( std::vector<int>::const_iterator node_it = adjNode.begin();
          node_it != adjNode.end();
          node_it++ )
    { 
        int node = (*node_it);

        if ( ContainsNode( visited, node ) || node == end )		
            continue;

        visited.push_back( node );

        DepthFirst( network, visited, end, max_hops, min_hops );        

        int n = (int) visited.size() - 1;				
        visited.erase( visited.begin() + n );
    }         
}
    


bool Algorithm::ContainsNode( Path& nodes, const int& node )
{
    for ( std::vector<int>::const_iterator nodes_it = nodes.begin();
          nodes_it != nodes.end();
          nodes_it++ )
    {
        if ( (*nodes_it) == node ) return true;
    }

    return false;        
}


void Algorithm::GetAllPaths( Network* network, 
                              const std::string& start, 
                              const std::string& target,
                              const int& max_hops,
							  const int& min_hops )
{
	int s = network->NodeIndex( start );
	int d = network->NodeIndex( target );
	startNodeId = s;

    Path visited;	
    visited.push_back( s );
    
    DepthFirst( network, visited, d, max_hops, min_hops );        
}

void Algorithm::GetAllPaths( Network* network, 
                              const int& start, 
                              const int& target,
                              const int& max_hops,
							  const int& min_hops )
{
	std::string strFirst = static_cast<std::ostringstream*>( &(std::ostringstream() << start ) )->str();
	std::string strSecond = static_cast<std::ostringstream*>( &(std::ostringstream() << target ) )->str();

	int s = network->NodeIndex( strFirst );
	int d = network->NodeIndex( strSecond );
	startNodeId = s;

    Path visited;	
    visited.push_back( s );
    
    DepthFirst( network, visited, d, max_hops, min_hops );        
}


// Dijkstra's shortest path algorithm
void Algorithm::Dijkstra( Network* network,
						  const int& start,
						  const int& target )
{
	network->ShortestPaths( start, target );
}