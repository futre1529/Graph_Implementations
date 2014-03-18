#include<iostream>
using namespace std;

struct node
{
    int tag;
    int key[4];
    node *child[5];
}*root;

void sort(int ar[5],int size)
{
    int i,j,temp;
    for(i=0;i<size;i++)
        for(j=0;j<size-1;j++)
            if(ar[j]>ar[j+1])
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
}
void split(node *l,int k,int x)
{
    int i,ar[5];
    node *temp=new node,*t,*n,*t1,*t2;
    switch(x)
    {
        case 0:
        n=l;
        for(i=0;i<4;i++)
        ar[i]=l->key[i];
        ar[4]=k;
        sort(ar,5);
        temp->key[0]=ar[2];
        for(i=1;i<4;i++)
        {
            temp->key[i]=-1;
            temp->child[i]=NULL;
        }
        temp->child[4]=NULL;
        temp->child[0]=l;
        temp->child[1]=new node;
        t=temp->child[1];
        l->key[0]=ar[0];l->key[1]=ar[1];l->key[2]=-1;l->key[3]=-1;
        t->key[0]=ar[3];t->key[1]=ar[4];t->key[2]=-1;t->key[3]=-1;
        t->child[0]=n->child[3];t->child[1]=n->child[4];t->child[2]=NULL;
        for(i=3;i<5;i++){t->child[i]=NULL;l->child[i]=NULL;}
        t->tag=1;
        temp->child[0]->tag=1;
        temp->tag=0;
        root=temp;
        break;
        case 1:
        int j,b,tm,tm1,flag=0;
        cout<<"\nSplitting node of type 2 ";
        for(i=0;l->key[i]!=-1&&i!=4;i++)
            if(k<l->key[i])break;
        for(j=0;j<4;j++)
            ar[j]=l->child[i]->key[j];
        ar[4]=k;
        sort(ar,5);
        if(i!=0)
        {t=l->child[i-1];
        for(b=0;b<4;b++)
        {
            if(t->key[b]==-1)
            {flag=1;
             break;}
        }}

        if(flag==0)
        {
            for(i=0;l->key[i]!=-1&&i!=4;i++)
            if(k<l->key[i])break;
            //if(i==0)cout<<k<<"@";
            tm=l->key[i];t1=l->child[i+1];
            for(j=i;l->key[j]!=-1&&j<3;j++)
            {
                tm1=l->key[j+1];
                l->key[j+1]=tm;
                tm=tm1;
                t2=l->child[j+2];
                l->child[j+2]=t1;
                t1=t2;
            }
            l->key[i]=ar[2];
            //cout<<l->key[i];
            l->child[i]->key[0]=ar[0];l->child[i]->key[1]=ar[1];l->child[i]->key[2]=-1;l->child[i]->key[3]=-1;
            l->child[i+1]=new node;
            l->child[i+1]->key[0]=ar[3];l->child[i+1]->key[1]=ar[4];l->child[i+1]->key[2]=-1;l->child[i+1]->key[3]=-1;
            for(j=0;j<5;j++)l->child[i+1]->child[j]=NULL;
            l->child[i+1]->tag=1;
        }
        else
        {
           cout<<"\nKey Redistribution ";
           t->key[b]=l->key[i-1];
           l->key[i-1]=ar[0];
           for(b=1;b<5;b++)
                l->child[i]->key[b-1]=ar[b];
        }
        break;
    }
}
void splitpar(node *l,int k,int x)
{
    cout<<"hello";
    node *temp=new node,*t,*n;
    int mid;
    int i,j,ar[5],arr[5];
    for(i=0;i!=4;i++)
        if(k<l->key[i])break;
    node *t1=l->child[0];
    for(j=0;j<4;j++)ar[j]=t1->key[j];
    arr[4]=k;
    sort(arr,5);
    mid =arr[2];
    cout<<"hello";
    for(j=0;j<4;j++)ar[j]=l->key[j];
    ar[4]=mid;
    sort(ar,5);
    temp->key[0]=ar[2];
    cout<<"hello";
    for(i=1;i<4;i++)
    {
        temp->key[i]=-1;
        temp->child[i]=NULL;
    }
    temp->child[4]=NULL;
    temp->child[0]=l;
    temp->child[1]=new node;
    t=temp->child[1];
    l->key[0]=ar[0];l->key[1]=ar[1];l->key[2]=-1;l->key[3]=-1;
    t->key[0]=ar[3];t->key[1]=ar[4];t->key[2]=-1;t->key[3]=-1;
    cout<<"hello";
    if(i<2)
    {
        for(j=0;j<=i;j++);
        t->child[0]=l->child[2];t->child[1]=l->child[3];t->child[2]=l->child[4];t->child[3]=0;t->child[4]=0;
        l->child[0]->key[0]=arr[0];l->child[0]->key[1]=arr[1];l->child[0]->key[2]=-1;l->child[0]->key[3]=-1;
        l->child[1]=new node;
        l->child[3]=NULL;l->child[4]=NULL;
        n=l->child[1];
        n->key[0]=arr[3];n->key[1]=arr[4];n->key[2]=-1;n->key[3]=-1;
        for(j=0;j<5;j++)n->child[j]=NULL;
    }
    root=temp;
    cout<<"hello";
}
void add(node *l,int data,int &flag)
{
    int i,j;
    for(i=0;l->key[i]!=-1&&i!=4;i++)
        if(data<l->key[i])break;
    if(l->child[0]!=NULL)
    {
        add(l->child[i],data,flag);
        if(flag==1)
        {
            for(j=0;l->key[j]!=-1&&j!=4;j++);
            if(j==4)
            {
                cout<<"\nSplitting the parent node";
                if(l->tag==1){flag=1;return;}
                else
                splitpar(l,data,0);
            }
            else
            {
                split(l,data,1);
                flag=0;
            }
        }
    }
    else
    {
        for(j=0;l->key[j]!=-1&&j!=4;j++);
        if(j==4)
        {
            cout<<"\nSplitting the node";
            if(l->tag==1){flag=1;return;}
            else
            split(l,data,0);
        }
        else
        {
            int arr[4];
            for(j=0;l->key[j]!=-1;j++)
                arr[j]=l->key[j];
            arr[j]=data;
            sort(arr,j+1);
            for(int m=0;m<=j;m++)
                {l->key[m]=arr[m];}
        }
    }
}
void display(node *l)
{
     int i,j;
     if(l!=NULL)
     {
                   for(i=0;l->key[i]!=-1&&i!=4;i++)
                   {
                       display(l->child[i]);
                       cout<<l->key[i]<<" ";
                   }
                   cout<<endl;
                   display(l->child[i]);cout<<endl;
     }
}

int main()
{
    root=new node;
    int num,i,flag=0;
    cout<<"Enter the value to be inserted(0 to exit) ";
    cin>>num;
    root->key[0]=num;
    for(i=1;i<4;i++)
    {
        root->key[i]=-1;
        root->child[i]=NULL;
    }
    root->child[0]=root->child[4]=NULL;
    root->tag=0;
    while(1)
    {
        flag=0;
        cin>>num;
        if(num==0)break;
        add(root,num,flag);
    }
    cout<<"\n--------------------------\n";
    //cout<<root->child[1]->key[0];
    //cout<<root->child[1]->key[1];
    //cout<<root->key[1];
    //cout<<root->child[2]->key[0];
    //cout<<root->child[2]->key[3];
    //cout<<"\nDisplaying the root->";
    display(root);
}
