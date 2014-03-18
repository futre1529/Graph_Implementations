#include<iostream>
using namespace std;

int findroot(int s[7],int x)
{
    if(s[x]==-1)
        return(x);
    else
        return(findroot(s,s[x]));
}
int findmin(int a[7][7],int &cx,int &cy,int index)
{
    int min=100;
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
            if(a[i][j]<min)
            {
                min=a[i][j];
                cx=i;
                cy=j;
            }
    a[cx][cy]=100;
    a[cy][cx]=100;
    return(min);
}
int main()
{
    int a[7][7]={{100,2,4,1,100,100,100},
                 {2,100,100,3,10,100,100},
                 {4,100,100,2,100,5,100},
                 {1,3,2,100,7,8,4},
                 {100,10,100,7,100,100,6},
                 {100,100,5,8,100,100,1},
                 {100,100,100,4,6,1,100}};
    int count=0,i,cx,cy,r1,r2,dist=0,s[7],x;
    for(i=0;i<7;i++)s[i]=-1;
    while(count!=6)
    {
        cx=cy=r1=r2=0;
        x=findmin(a,cx,cy,count);
        r1=findroot(s,cx);
        r2=findroot(s,cy);
        cout<<x<<" "<<r1<<" "<<r2<<"\t";
        //cin>>x;
        if(r1!=r2)
        {
            if(s[cy]==-1)
                s[cy]=cx;
            else
                s[cx]=cy;
            for(i=0;i<7;i++)cout<<s[i]<<" ";
            dist+=x;
            cout<<"\t";
            cout<<cx+1<<"--"<<x<<"--"<<cy+1;
            count++;
        }
        cout<<"......................\n";
    }
    cout<<"\nThe minimum span of the tree is(krushgal's algorithm) :"<<dist;
}
