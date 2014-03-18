#include<iostream>
using namespace std;

int main()
{
    int visit[7];
    int a[7][7]={{9999,2,4,1,9999,9999,9999},
                 {2,9999,9999,3,10,9999,9999},
                 {4,9999,9999,2,9999,5,9999},
                 {1,3,2,9999,7,8,4},
                 {9999,10,9999,7,9999,9999,6},
                 {9999,9999,5,8,9999,9999,1},
                 {9999,9999,9999,4,6,1,9999}};
    //i is the vertices traversed
    //k is the no. of vertices visited
    //node array stores the vertices visited
    //visit array also indicates the vertices visited
    int i,j,k=0,min,l;
    cout<<"\nEnter the starting index :";
    cin>>i;
    for(j=0;j<7;j++)
        visit[j]=0;
    int node[7];
    cout<<"\nThe path traced is :";
    cout<<i+1;
    while(k!=6)
    {
        visit[i]=1;
        node[k]=i;
        min=9999;
        for(l=0;l<=k;l++)
        {
            for(j=0;j<7;j++)
            {
                if(a[node[l]][j]<min&&visit[j]!=1){min=a[node[l]][j];i=j;}
            }
        }
        k++;
        cout<<i+1;
    }
}
