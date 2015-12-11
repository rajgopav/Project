#include<iostream.h
#include<conio.h>
#include <stdlib.h>

void main()
{
    clrscr();
    int a,b,c,d,ctr,j,Q=1,K=1 ;
    float q0=0.7, p = 0.5 ;
    int phe[8][8];
    double dist[8][8] , mem[8][8],exp[8][8],eplt[8][8], rnd;
    cout<<"enter the iterations, cities , ants ";
    cin>>a>>b>>c;
    for (int i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            dist[i][j]=(double)rand()/(double)RAND_MAX;
            if (i==j)
            dist[i][j]=0;
        }
    }
    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            cout<< dist[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<"pheromone matrix "<<endl;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            if (i==j)
                phe[i][j]=0;
            else
                phe[i][j]=1;
        }
    }

    for ( i=0;i<3;i++)
    {
        for ( j=0;j<3;j++)
        {
            cout<< phe[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<< "after iteration "<<endl;
    for (i=0;i<8;i++)
    {
        ctr=0;
        for (int k=0;k<8;k++)
        {
            // mem[i][k]=(rand()%b)+1;
            // cout<<"memory"<<mem[i][k]<<"\n";
            rnd= (double)rand()/(double)RAND_MAX;
            cout<<"hhhhhhh"<<rnd;
            if (rnd<=q0)
            {
                cout<<"Exploitation\n";
                eplt[i][ctr] =(p*phe[i][k])+(Q/K);  
            }
            else
            {
                cout<<"EXPLORATION\n";
                eplt[i][ctr]= phe[i][k]/dist[i][k];
            }
            ctr++;
        }
    }
    for (i=0;i<3;i++)
    {
        for (int k=0;k<8;k++)
        {
            cout <<eplt[i][k]<<"\t";
        }
        cout<<"\n";
    }
    getch();
}
