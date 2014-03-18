#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
int deg(int a[11][11],int v)
{
    int x=0;
    for(int j=0;j<11;j++)
        if(a[v][j]==1)
        x+=1;
    return(x);
}

void splicing(node *&l,node *&t)
{
    node *t1=l,*t2=t;
    if(t1!=NULL)
    {
        while(t1->data!=t2->data)
            t1=t1->next;
        node *temp=t1->next;
        t1->next=t2->next;
        while(t2->next!=NULL)
            t2=t2->next;
        t2->next=temp;
    }
    else
        l=t;
}
void add(node *&l,int k)
{
    if(l==NULL)
    {
        l=new node;
        l->data=k;
        l->next=NULL;
    }
    else
    {
        node *temp=l;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new node;
        temp->next->next=NULL;
        temp->next->data=k;
    }
}
void display(node *l)
{
    if(l!=NULL)
    {
        cout<<l->data+1<<" ";
        display(l->next);
    }
}
int main()
{
    int a[11][11]={{0,1,1,0,0,0,0,0,0,0,0},
            {1,0,1,1,1,0,0,0,1,1,0},
            {1,1,0,1,1,0,1,1,0,0,0},
            {0,1,1,0,1,1,0,0,1,0,1},
            {0,1,1,1,0,1,1,1,0,0,0},
            {0,0,0,1,1,0,0,0,0,0,0},
            {0,0,1,0,1,0,0,0,0,0,0},
            {0,0,1,0,1,0,0,0,0,0,0},
            {0,1,0,1,0,0,0,0,0,0,0},
            {0,1,0,0,0,0,0,0,0,0,1},
            {0,0,0,1,0,0,0,0,0,1,0}};
    node *path=NULL,*temp=NULL;
    int i=8,x=8,j,flag=0;;
    while(1)
    {
        l1:flag=0;
        if(deg(a,i)!=0)
        {
            //cout<<i+1<<" "<<deg(a,i)<<" \n";
            if(i!=x)
            {
                if(a[i][x]==1)
                {
                    add(temp,i);
                    add(temp,x);
                    a[i][x]=2;
                    a[x][i]=2;
                    i=x;
                    continue;
                }
            }
            for(j=0;j<11;j++)
            {
                if(a[i][j]==1)
                {
                    add(temp,i);
                    a[i][j]=2;
                    a[j][i]=2;
                    //count++;
                    i=j;
                    goto l1;
                }
            }
        }
        else
        {
            for(j=0;j<11;j++)
                if(a[x][j]!=0)
                {
                    if(deg(a,j)!=0)
                    {
                        flag=1;
                        i=j;
                        break;
                    }
                }
            splicing(path,temp);
            if(flag==0)break;
            x=i;
            temp=NULL;
        }
    }
    cout<<"\n\nThe final path is :";
    display(path);
    //cout<<path->data<<" ";
}
