#include<iostream>
using namespace std;

struct vertex
{
    int par;
    int num;
    int low;
    int visit;
};
int min(int a, int b)
{
    return(a<b?a:b);
}
int counter=0;
void assignNum(int a[7][7],vertex v[7],int i)
{
    v[i].num=counter++;
    v[i].visit=1;
    int j;
    for(j=0;j<7;j++)
        if(a[i][j]!=0&&v[j].visit==0)
        {
           v[j].par=i;
           assignNum(a,v,j);
        }
}
void assignLow(int a[7][7],vertex v[7],int i)
{
    v[i].low=v[i].num;
    int j;
    for(j=0;j<7;j++)
    {
        if(a[i][j]!=0)
        {
            if(v[j].num>v[i].num)
            {
                assignLow(a,v,j);
                if(v[j].low>=v[i].num)
                    cout<<v[i].num+1<<" is an articulated point\n";
                v[i].low=min(v[i].low,v[j].low);
            }
            else if(v[i].par!=j)
                v[i].low=min(v[i].low,v[j].num);
        }
    }
}
int main()
{
    int a[7][7]={{0,1,0,1,0,0,0},
            {1,0,1,0,0,0,0},
            {0,1,0,1,0,0,1},
            {1,0,1,0,1,1,0},
            {0,0,0,1,0,1,0},
            {0,0,0,1,1,0,0},
            {0,0,1,0,0,0,0}};
    vertex v[7];
    int i;
    for(i=0;i<7;i++)
        v[i].visit=0;
    i=0;
    assignNum(a,v,i);
    i=0;
    assignLow(a,v,i);
    cout<<"\n......................\n";
    for(i=0;i<7;i++)
    {
        cout<<v[i].num+1<<"|"<<v[i].low+1<<endl;
    }
}
