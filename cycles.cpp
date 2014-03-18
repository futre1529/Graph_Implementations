#include<iostream>
using namespace std;

void loops(int a[7][7],int v[],int i)
{
    v[i]=1;
    int j;
    for(j=0;j<7;j++)
    {
        if(a[i][j]!=0)
        {
            if(v[j]==0)
                {loops(a,v,j);v[j]=0;}
            else
            {
                cout<<"loop detected->";
                cout<<"From "<<i+1<<" and distance "<<a[i][j]<<"\n";
                return;
            }
        }
    }
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
    int i,visit[7],j;
    cout<<".........loops in the graph...........\n";
    for(i=0;i<7;i++)
    {
        for(j=0;j<7;j++)visit[j]=0;
        cout<<"vertex :"<<i+1<<endl;
        loops(a,visit,i);
        cout<<"---------------------------\n";
    }
}
