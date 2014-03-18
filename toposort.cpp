#include<iostream>
using namespace std;

int indeg(int a[7][7],int visit[7])
{
    int i,j,sum;
    for(i=0;i<7;i++)
    {
        sum=0;
        for(j=0;j<7;j++)
            sum+=a[j][i];
        if(sum==0&&visit[i]!=1)
            {visit[i]=1;return(i);}
    }
}
int main()
{
    int a[7][7]={{0,1,1,1,0,0,0},
                 {0,0,0,1,1,0,0},
                 {0,0,0,0,0,1,0},
                 {0,0,1,0,0,1,1},
                 {0,0,0,1,0,0,1},
                 {0,0,0,0,0,0,0},
                 {0,0,0,0,0,1,0}};
    int count;
    int v,w,i,j,visit[7];
    for(i=0;i<7;i++)visit[i]=0;
    for(count =0;count<7;count++)
    {
        v=indeg(a,visit);
        cout<<v+1<<" ";
        for(j=0;j<7;j++)
            {a[v][j]=0;}
    }
}
