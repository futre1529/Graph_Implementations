#include<iostream>
using namespace std;

int flag;
void dfs(int a[7][7],int v[],int i)
{
    v[i]=1;
    cout<<i+1<<" ";
    int j;
    for(j=0;j<7;j++)
        if(v[j]==1&&a[i][j]==1&&flag==0)
            {cout<<"\nBack edge :"<<i+1<<" to "<<j+1<<"\t";a[i][j]=2;}
    for(j=0;j<7;j++)
        if(a[i][j]!=0)
            if(v[j]==0)
                {cout<<"\nTree edge :"<<i+1<<" to "<<j+1<<"\t";dfs(a,v,j);a[i][j]=2;}
            else if(v[j]==1&& flag>0)
                cout<<"\nCross edge :"<<i+1<<" to "<<j+1<<"\t";
    for(j=0;j<7;j++)
        if(v[j]==1&&a[i][j]==1)
            cout<<"\nForward edge :"<<i+1<<" to "<<j+1<<"\t";
}

int main()
{
    int a[7][7]={{0,1,0,1,0,0,0},
                {0,0,1,0,0,0,0},
                {1,0,0,1,0,0,0},
                {0,0,0,0,1,0,0},
                {0,1,1,0,0,0,0},
                {1,0,0,0,0,0,1},
                {0,0,0,0,0,0,0}};
    int i,visit[7];
    for(i=0;i<7;i++)visit[i]=0;
    flag=0;
    for(i=0;i<7;i++)
    {
        if(visit[i]==0)
            dfs(a,visit,i);
        flag+=1;
    }
}
