#include "Network.h"
#include "ShortestPathsTree.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <set>
#include <stack>


Network::~Network()
{
	//if ( graph != NULL )
	//{
	//	delete graph;
	//	graph = NULL;
	//}
}

Network::Network( const std::vector<Link<std::string>>& links, 
                  const bool& bi_connected ) 
{
	typedef std::vector<Link<std::string>>::const_iterator v_iter;

	label2index.clear();
	index2label.clear();
	std::set<std::string> unique_id_str;

	for ( v_iter it = links.begin(); it != links.end(); ++it )
	{
		const Link<std::string> l = (*it);
		std::string first = l.From();
		std::string second = l.To();

		unique_id_str.insert( first );
		unique_id_str.insert( second );
	}

	int i = 0;
	for ( std::set<std::string>::const_iterator it = unique_id_str.begin();
		 it != unique_id_str.end();
		 ++it )
	{
		std::string label = (*it);
		index2label[ i ] = label;
		label2index[ label ] = i;
		i++;
	}
	 
	std::set<int> unique_ids;

	const int nodes = unique_id_str.size();

	std::shared_ptr<DenseGRAPH<Edge>> g( new DenseGRAPH<Edge>( nodes + 1, !bi_connected ) );
	graph = std::shared_ptr<DenseGRAPH<Edge>>( g );
    
    for ( v_iter it = links.begin(); it != links.end(); ++it )
    {
        const Link<std::string> l = (*it);
		std::string first = l.From();
		std::string second = l.To();

		int s = label2index.find( first )->second;
		int d = label2index.find( second )->second;
		double weight = l.Weight();

		EdgePtr e( new Edge( s, d, weight ) );
		graph->insert( e );
    }   	
}

Network::Network( const std::vector<Link<int>>& links, 
                  const bool& bi_connected ) 
{
	typedef std::vector<Link<int>>::const_iterator v_iter;

	label2index.clear();
	index2label.clear();
	std::set<std::string> unique_id_str;

	for ( v_iter it = links.begin(); it != links.end(); ++it )
	{
		const Link<int> l = (*it);
		int first = l.From();
		int second = l.To();

		std::string strFirst = static_cast<std::ostringstream*>( &(std::ostringstream() << first ) )->str();
		std::string strSecond = static_cast<std::ostringstream*>( &(std::ostringstream() << second ) )->str();
		
		unique_id_str.insert( strFirst );
		unique_id_str.insert( strSecond );
	}

	int i = 0;
	for ( std::set<std::string>::const_iterator it = unique_id_str.begin();
		 it != unique_id_str.end();
		 ++it )
	{
		std::string label = (*it);
		index2label[ i ] = label;
		label2index[ label ] = i;
		i++;
	}
	 
	std::set<int> unique_ids;

	const int nodes = unique_id_str.size();

	std::shared_ptr<DenseGRAPH<Edge>> g( new DenseGRAPH<Edge>( nodes + 1, !bi_connected ) );
	graph = std::shared_ptr<DenseGRAPH<Edge>>( g );
    
    for ( v_iter it = links.begin(); it != links.end(); ++it )
    {
        const Link<int> l = (*it);
		int first = l.From();
		int second = l.To();

		std::string strFirst = static_cast<std::ostringstream*>( &(std::ostringstream() << first ) )->str();
		std::string strSecond = static_cast<std::ostringstream*>( &(std::ostringstream() << second ) )->str();

		int s = label2index.find( strFirst )->second;
		int d = label2index.find( strSecond )->second;
		double weight = l.Weight();

		EdgePtr e( new Edge( s, d, weight ) );
		graph->insert( e );
    } 	
}

void Network::AddPath( const Path& p )
{
    pathset.push_back( p );        
}


// Get the set of nodes adjacent to this node
std::vector< int > Network::GetAdjNodeIDs( const int& n ) const
{
    std::vector< int > adj;

	DenseGRAPH<Edge>::adjIterator A(*graph, n ); 
      
	for ( EdgePtr e = A.beg(); !A.end(); e = A.nxt() ) 
	{ 				
        const int  s = e->v;
        const int  d = e->w;	

		if ( !graph->directed() && ( s == n || d == n ) )
        {
            adj.push_back( s == n ? d : s );
        }
        else if ( s == n )
        {
            adj.push_back( d );
        }       	
	}

    return adj;
}


// Output the set of paths found
void Network::ShowPaths() const
{
    for ( Paths paths = pathset.begin(); paths != pathset.end(); ++paths )
    {
        Path path = *paths;

		for ( std::vector<int>::const_iterator it = path.begin();
			  it != path.end();
			  ++it )
		{
			int n = (*it);
			std::string node_str = index2label.find( n )->second;
			std::cout << node_str << " ";
		}

		std::cout  << std::endl;       
    }            
}


int Network::NodeIndex( const std::string& label ) const
{
	int n = label2index.find( label )->second;
	return n;
}

void Network::ShortestPaths( const int& s,
		                     const int& d )
{
	pathset.clear();
	typedef DenseGRAPH<Edge> dGraph;
	std::stack<int> path;
	std::vector<int> visited;

	std::string strSource = static_cast<std::ostringstream*>( &(std::ostringstream() << s ) )->str();
	int source = label2index.find( strSource )->second;

	ShortestPathsTree<dGraph, Edge> sp( *graph, source );

	std::string strDest = static_cast<std::ostringstream*>( &(std::ostringstream() << d ) )->str();
	int destination = label2index.find( strDest )->second;

	while ( true )
	{
		EdgePtr e = sp.pathR( destination );	
		path.push( destination );
		if ( destination == source ) break;
		destination = e->v;
	}

	// Print the path nodes
	while ( !path.empty() )
	{
		visited.push_back( path.top() );
		path.pop();
	}

	const int size = (int) visited.size();
    AddPath( Path( visited.begin(), visited.begin() + size ) );
}
