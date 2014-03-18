#include<iostream>
using namespace std;

struct node
{
    int data;
    int noe;
    node *next;
    node **edge;
};

void add(node *&x,int k)
{
    if(x==NULL)
    {
        x=new node;
        x->data=k;
        x->next=NULL;
    }
    else
    {
        node *temp=x;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new node;
        temp->next->data=k;
        temp->next->next=NULL;
    }
}
int links(int a[7][7],int i)
{
    int j,count=0;
    for(j=0;j<7;j++)
        if(a[i][j]!=0)count++;
    return(count);
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
    int i,j,n,k,l;
    node *x=NULL;
    for(i=0;i<7;i++)
        add(x,i+1);
    node *t=x;
    for(i=0;i<7;i++)
    {
        k=0;
        n=links(a,i);
        if(n!=0)
        {
            t->noe=n;
            t->edge=new node*[n];
        }
        for(j=0;j<7;j++)
        {
            if(a[i][j]!=0)
            {
                node *temp=x;
                for(l=0;l<j;l++)temp=temp->next;
                t->edge[k]=temp;
                k++;
            }
        }
        cout<<endl;
        t=t->next;
    }
}
