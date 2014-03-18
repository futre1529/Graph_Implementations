#include<iostream>
using namespace std;

class stack
{
      public:
             int size;
             int *elements;
             int top;
             void push(int);
             int pop();
             stack()
             {
                 top=-1;
                size=20;
                elements=new int[size];
             }
}s;
int stack::pop()
{
   if(top!=-1)
              return(elements[top--]);
   else
       return(-1);
}
void stack::push(int x)
{
     if(top!=size-1)
                    elements[++top]=x;
     else cout<<"\n Stack full ";
}
//.................................................
void dfs(int a[10][10],int v[10],int i,int &count)
{
    v[i]=1;count+=1;
    s.push(i);
    char ch='A';
    ch=ch+i;
    cout<<ch<<" ";
    int j;
    for(j=0;j<10;j++)
        if(a[i][j]!=0)
            if(v[j]==0)
                dfs(a,v,j,count);
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
    int v[10],temp1=0,temp2;
    int i=0,visit[10],j,count=0;
    for(j=0;j<10;j++)visit[j]=0;
    for(i=0;i<10;i++)
    {
        if(visit[i]==0)
        {
            dfs(a,visit,i,temp1);
            while(s.top!=-1)
            {
                temp2=s.pop();
                v[temp2]=count+1;
                count++;
            }
            cout<<endl;
        }
    }
    cout<<"\n.......................\n";
    for(i=0;i<10;i++)
        cout<<v[i]<<" ";
    int b[10][10]={0};
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        {
            if(a[i][j]==1)
            {
                b[i][j]=0;
                b[j][i]=1;
            }
            else if(b[i][j]!=1)
                b[i][j]=0;
        }
    count=0;
    for(i=0;i<10;i++)visit[i]=0;
    cout<<endl;
    cout<<"\n\nThe strongly connected components are :\n";
    while(count!=10)
    {
        temp1=-1;
        for(i=0;i<10;i++)
            if(visit[i]==0)
                if(v[i]>temp1)
                    {temp1=v[i];temp2=i;}
        dfs(b,visit,temp2,count);
        cout<<endl;
    }
}
