#include<iostream>
using namespace std;

struct node
{
    int index;
    int rval;
};
node x[10];
int count;
void dfs(int a[10][10],int v[10],int i)
{
    v[i]=1;
    x[i].index=count;
    x[i].rval=count;
    int j,k;
    count++;
    for(j=0;j<10;j++)
    {
        if(a[i][j]!=0)
        {
            if(v[j]==0)
                dfs(a,v,j);
            else if(x[j].rval<x[i].rval)
            {
                int temp=x[j].rval;
                for(k=0;k<10;k++)
                    if(a[k][i]==1)
                        x[k].rval=temp;
                x[i].rval=temp;
            }
        }
    }
}
int main()
{
    int a[10][10]={{0,1,0,1,0,0,0,0,0},
                {0,0,1,0,0,1,0,0,0,0},
                {1,0,0,1,1,0,0,0,0,0},
                {0,0,0,0,1,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,0,0,0},
                {0,0,0,0,0,1,0,1,0,0},
                {0,0,0,0,0,1,0,0,1,0},
                {0,0,0,0,0,0,0,0,0,1},
                {0,0,0,0,0,0,0,1,0,0}};
    int visit[10],i;
    for(i=0;i<10;i++)visit[i]=0;
    i=0;count=0;
    for(i=0;i<10;i++)
    {
        dfs(a,visit,i);
        i=count-1;
        for(int k=0;k<10;k++)
            a[k][i]=0;
    }
    for(i=0;i<10;i++)
        cout<<x[i].index+1<<"  "<<x[i].rval+1<<endl;
    int flag,j;
    cout<<"\n\n\n.........................................\n";
    for(i=0;i<10;i++)
    {
        j=0,flag=0;
        while(j<10)
        {
            if(x[j].rval==i)
            {
                flag=1;
                cout<<x[j].index+1<<",";
            }
            j++;
        }
        if(flag==1)
            {cout<<"\b"<<" ";cout<<"\n";}
    }
}
