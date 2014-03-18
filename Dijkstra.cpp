#include<iostream>
using namespace std;

struct node
{
    int visit[7];
    int dist[7];
    char via[7];
};

int main()
{
    int a[7][7]={{9999,2,9999,1,9999,9999,9999},
                 {9999,9999,9999,3,10,9999,9999},
                 {4,9999,9999,9999,9999,5,9999},
                 {9999,9999,2,9999,2,8,4},
                 {9999,9999,9999,9999,9999,9999,6},
                 {9999,9999,9999,9999,9999,9999,9999},
                 {9999,9999,9999,9999,9999,1,9999}};
    node x;
    int i,j,min,k;
    char ch;
    for(i=0;i<7;i++)
    {
        x.visit[i]=0;
        x.dist[i]=9999;
        x.via[i]='*';
    }
    i=1;
    while(x.visit[0]!=1)
    {
        x.visit[i]=1;
        char ch='A';
        if(x.dist[i]==9999)x.dist[i]=0;
        for(j=0;j<7;j++)
        {
            if(a[i][j]<9999)
            {
                if(x.visit[j]!=1)
                {//{9999,9999,2,9999,2,8,4}
                    min=x.dist[i]+a[i][j];
                    if(min<x.dist[j])
                    {
                        if(x.dist[j]==9999)x.dist[j]=0;
                        x.dist[j]=min;
                        x.via[j]=ch+i;
                    }
                }
            }
        }
        min=999;
        for(j=0;j<7;j++)
            if(x.visit[j]!=1&&x.dist[j]<9999)
                if(x.dist[j]<min){min=x.dist[j],k=j;}
        i=k;
    }
    for(i=0;i<7;i++)
        cout<<x.visit[i]<<" "<<x.dist[i]<<" "<<x.via[i]<<endl;
    cout<<"\nThe path is.................\n";
    i=0;ch='A'+i;
    cout<<ch;
    while(i!=1)
    {
        cout<<"-"<<x.via[i];
        i=int(x.via[i]-'A');
    }
}
