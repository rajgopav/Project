#include<iostream>
#include<conio.h>

main()
{

int matrix [8] [8];
for (int i=0 ; i<8 ; i++)
{
for (int j=0 ; j<8 ; j++)
{
matrix [i] [j] = 7 ;
}
}
return 0;
}

int lastLoopRight = 0;
			int lastLoopDown = 0;

			int row = 0;
			int column = 0;
			int val = 0;
			int start = 0;
			int right = 1;
			int down = 2;
			int left = 3;
			int up = 4;
