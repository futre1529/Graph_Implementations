//depth first traversal in a graph
#include<iostream>
using namespace std;

void dfs(int a[7][7],int v[],int i)
{
    v[i]=1;
    cout<<i+1<<" ";
    int j;
    for(j=0;j<7;j++)
        if(a[i][j]!=0)
            if(v[j]==0)
                dfs(a,v,j);
}

int main()
{
    int a[7][7]={{0,2,0,1,0,0,0},
                 {0,0,0,3,10,0,0},
                 {4,0,0,0,0,5,0},
                 {0,0,2,0,2,8,4},
                 {0,0,0,0,0,0,6},
                 {0,0,0,0,0,0,0},
                 {0,0,0,0,0,1,0}};
    int i=3,visit[7],j;
    for(j=0;j<7;j++)visit[j]=0;
    cout<<"Starting vertex :"<<i+1<<endl;
    dfs(a,visit,i);
}
