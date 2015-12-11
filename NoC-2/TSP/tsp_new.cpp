#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, src;
vector< vector< int > > graph, dp;
// initial status
void init() {
	for ( int i = 0; i < n; ++i ) 
		dp[ 1 << i ][ i ] = graph[ src ][ i ];
}
// TSP recursive
int TSP( int status, int x ) {

	if ( dp[ status ][ x ] != -1 )
		return dp[ status ][ x ];

	int mask = 1 << x;
	dp[ status ][ x ] = 1e9;
	for ( int i = 0; i < n; ++i )
		if ( i != x && ( status & ( 1 << i ) ) )
			dp[ status ][ x ] = min( dp[ status ][ x ], TSP( status - mask, i ) + graph[ i ][ x ] );
	return dp[ status ][ x ];
}

int main() {
	scanf( "%d %d", &n, &src );
	graph = vector< vector< int > >( n, vector< int >( n ) );
	dp = vector< vector< int > >( 1 << n, vector< int >( n, -1 ) );
	for ( int i = 0; i < n; ++i )
		for ( int j = 0; j < n; ++j ) {
			int x;
			scanf( "%d", &x );
			graph[ i ][ j ] = x;
		}

	init();
	printf( "%d\n", TSP( ( 1 << n ) - 1, src ) );
	return 0;
}
