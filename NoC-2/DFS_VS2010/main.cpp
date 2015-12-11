    #include "Algorithm.h"    
    #include <iostream>    
    #include <vector>  
      
    const Link<int> linkset[] =   
	{ 
	// First row
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

	Link<int>(26, 34),
	Link<int>(26, 27),
	Link<int>(26, 18),
	Link<int>(26, 25),

	Link<int>(27, 35),
	Link<int>(27, 28),
	Link<int>(27, 19),
	Link<int>(27, 26)

	/*Link<int>(28, 36),
	Link<int>(28, 29),
	Link<int>(28, 20),
	Link<int>(28, 27),

	Link<int>(29, 37),
	Link<int>(29, 30),
	Link<int>(29, 21),
	Link<int>(29, 28),

	Link<int>(30, 38),
	Link<int>(30, 31),
	Link<int>(30, 22),
	Link<int>(30, 29),

	Link<int>(31, 39),
	Link<int>(31, 23),
	Link<int>(31, 30),
	
	//Fifth row
	Link<int>(32, 40),
	Link<int>(32, 33),
	Link<int>(32, 24),
	Link<int>(33, 41),
	Link<int>(33, 34),
	Link<int>(33, 25),
	Link<int>(33, 32),
	Link<int>(34, 42),
	Link<int>(34, 35),
	Link<int>(34, 26),
	Link<int>(34, 33),
	Link<int>(35, 43),
	Link<int>(35, 36),
	Link<int>(35, 27),
	Link<int>(35, 34),
	Link<int>(36, 44),
	Link<int>(36, 37),
	Link<int>(36, 28),
	Link<int>(36, 35),
	Link<int>(37, 45),
	Link<int>(37, 38),
	Link<int>(37, 29),
	Link<int>(37, 36),
	Link<int>(38, 46),
	Link<int>(38, 39),
	Link<int>(38, 30),
	Link<int>(38, 37),
	Link<int>(39, 47),
	Link<int>(39, 31),
	Link<int>(39, 38),
	
	//Sixth row
	Link<int>(40, 48),
	Link<int>(40, 41),
	Link<int>(40, 32),
	Link<int>(41, 49),
	Link<int>(41, 42),
	Link<int>(41, 33),
	Link<int>(41, 40),
	Link<int>(42, 50),
	Link<int>(42, 43),
	Link<int>(42, 43),
	Link<int>(42, 41),
	Link<int>(43, 51),
	Link<int>(43, 44),
	Link<int>(43, 35),
	Link<int>(43, 42),
	Link<int>(44, 52),
	Link<int>(44, 45),
	Link<int>(44, 36),
	Link<int>(44, 43),
	Link<int>(45, 53),
	Link<int>(45, 46),
	Link<int>(45, 37),
	Link<int>(45, 44),
	Link<int>(46, 54),
	Link<int>(46, 47),
	Link<int>(46, 38),
	Link<int>(46, 45),
	Link<int>(47, 55),
	Link<int>(47, 39),
	Link<int>(47, 46),

	//Seventh row
	Link<int>(48, 56),
	Link<int>(48, 49),
	Link<int>(48, 40),
	Link<int>(49, 57),
	Link<int>(49, 50),
	Link<int>(49, 41),
	Link<int>(49, 48),
	Link<int>(50, 58),
	Link<int>(50, 51),
	Link<int>(50, 42),
	Link<int>(50, 49),
	Link<int>(51, 59),
	Link<int>(51, 52),
	Link<int>(51, 43),
	Link<int>(51, 50),
	Link<int>(52, 60),
	Link<int>(52, 53),
	Link<int>(52, 44),
	Link<int>(52, 51),
	Link<int>(53, 61),
	Link<int>(53, 54),
	Link<int>(53, 45),
	Link<int>(53, 52),
	Link<int>(54, 62),
	Link<int>(54, 55),
	Link<int>(54, 46),
	Link<int>(54, 53),
	Link<int>(55, 63),
	Link<int>(55, 47),
	Link<int>(55, 54),

	//Eigth row
	Link<int>(56, 57),
	Link<int>(56, 48),
	Link<int>(57, 58),
	Link<int>(57, 49),
	Link<int>(57, 56),
	Link<int>(58, 59),
	Link<int>(58, 50),
	Link<int>(58, 57),
	Link<int>(59, 60),
	Link<int>(59, 51),
	Link<int>(59, 58),
	Link<int>(60, 61),
	Link<int>(60, 52),
	Link<int>(60, 59),
	Link<int>(61, 62),
	Link<int>(61, 53),
	Link<int>(61, 60),
	Link<int>(62, 63),
	Link<int>(62, 54),
	Link<int>(62, 61),
	Link<int>(63, 55),
	Link<int>(63, 62)*/
	};
        
    const size_t size = sizeof( linkset ) / sizeof( linkset[ 0 ] ) ;    
    const std::vector<Link<int>> links (linkset, linkset + size );     
        
    int main()    
    {    
        // Create network from interconnections given        
        Network nw( links, false );    
            
        // Create the algorithm object    
        Algorithm algorithm( &nw );    
                 
        // Get shortest path    
        //algorithm.Dijkstra( &nw, 2, 7 );   
		algorithm.GetAllPaths(&nw, 0, 0, 8, 4);
        // Output the set of paths found    
        nw.ShowPaths();            
        
        return 0;    
    }   