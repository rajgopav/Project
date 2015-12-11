#pragma once

#include "Graph.h"
#include <vector>
#include <map>
#include <string>

typedef std::vector<int> Path;
typedef std::vector<Path> PathSet;
typedef std::vector<Path>::const_iterator Paths;

template< class T >
class Link
{
private:
	T from;
	T to;
	double weight;

public:
	Link( const T& from, const T& to, const double &weight = 1.0 ) : 
	  from( from ), to( to ), weight( weight ) {}
	const T& From() const 
	{ return from; }

	const T& To() const
	{ return to; }

	const double& Weight() const
	{ return weight; }
};

class Network
{
private:
	 
	std::shared_ptr<DenseGRAPH<Edge>> graph;
    PathSet pathset;  
	std::map<std::string, int > label2index;
	std::map<int, std::string > index2label;

public:

	Network() {}

    Network( const std::vector<Link<std::string> >& links, 
             const bool& bi = false );
	Network( const std::vector<Link<int> >& links, 
             const bool& bi = false );
	~Network();

    void AddPath( const Path& p );
    void ShowPaths() const;	 
	int NodeIndex( const std::string& label ) const;

    std::vector<int> GetAdjNodeIDs( const int& n ) const; 

	void ShortestPaths( const int& start,
		                const int& target );

private:
	
};