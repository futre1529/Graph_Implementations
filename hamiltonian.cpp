#include<iostream>
#include<cstdlib>
using namespace std;

int path[10],flag=0;
void dfs(int a[10][10],int v[],int i,int &count)
{
    v[i]=1;
    path[count]=i;
    count++;
    int j;
    if(count <9)
    {
        for(j=0;j<10;j++)
        {
            if(a[i][j]!=0)
                if(v[j]==0&&flag==0)
                    dfs(a,v,j,count);
                else if(flag==1)
                {
                    for(int k=j+1;k<10;k++)
                    if(a[i][k]!=0&&v[k]==0){flag=0;break;}
                    if(flag==0)continue;
                    else goto l1;
                }
        }
        l1:cout<<i<<"("<<count<<")"<<" ";
        //cin>>i;
        flag=1;
        v[i]=0;
        count--;
    }
    else
    {
        cout<<endl;
        /*for(j=0;j<10;j++)
        {
            if(v[4]==0)
            {
                int l;
                cout<<"\nUnvisited\n";
                //cin>>l;
                for(l=1;l<10;l++)v[l]=0;
                v[1]=0;
                count=1;
                flag=0;
                dfs(a,v,path[1],count);
            }
        }*/
        cout<<"\n"<<count<<" ";
        cout<<"Displaying the path --> ";
        for(j=0;j<10;j++)cout<<path[j]+1<<" ";
        exit(0);
    }
}

int main()
{
    int a[10][10]={{0,1,1,1,0,0,0,0,0},
                {1,0,1,0,0,1,0,0,0,0},
                {1,1,0,1,1,1,0,0,0,0},
                {1,0,1,0,1,0,0,0,0,0},
                {0,0,1,1,0,0,0,0,0,0},
                {0,1,1,0,0,0,1,1,0,0},
                {0,0,0,0,0,1,0,1,0,0},
                {0,0,0,0,0,1,1,0,1,1},
                {0,0,0,0,0,0,0,1,0,1},
                {0,0,0,0,0,0,0,1,1,0}};
    int i=0,visit[10],j,count=0;
    for(j=0;j<10;j++)visit[j]=0;
    cout<<"Starting vertex :"<<i+1<<endl;
    dfs(a,visit,i,count);
}
