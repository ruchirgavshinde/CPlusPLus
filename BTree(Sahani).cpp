#include<iostream>
#include<stack>
#include<queue>
using namespace std;
const int M=5;
 struct btnode
{
    int data[M];
    int nk;
    btnode*child[M];

}*root=NULL;
void levelorder(btnode*r)
{
    queue<btnode*> q1;
    q1.push(r);
    while(!q1.empty())
    {
     for(int i=0;i<M;i++)
     {
         if(q1.front()->child[i]==NULL)
         {
             continue;
         }
         else
         {
             q1.push(q1.front()->child[i]);
         }

     }
     for(int i=0;i<M-1;i++)
     {
         if(q1.front()->data[i]==0)
         {
             break;
        }
        else
        {
         cout<<q1.front()->data[i]<<" ";
        }
     }
     q1.pop();
    }

}
btnode*createnode(int x)
{
  btnode*newnode=new btnode;
          newnode->nk=1;

    for(int i=0;i<M;i++)
    {
        if(i<M-1)
        {
            newnode->data[i]=0;
        }
        newnode->child[i]=NULL;
    }
        newnode->data[0]=x;

  return newnode;
}
btnode*split(btnode*r,btnode*y,stack<btnode*> s1)
{
    btnode*w=y;
    while(!s1.empty())
    {
    if(w->nk>M-1)
    {
    if(w==r)
    {
    int mid=M/2;
    btnode*x=createnode(w->data[mid]);
    btnode*z=createnode(w->data[mid+1]);
    x->child[0]=w;
    x->child[1]=z;
    for(int j=mid+1;j<M;j++)
    {
     z->data[j-mid-1]=w->data[j] ;
     z->nk=z->nk+1;
     w->data[j]=0;
     }
     z->nk=z->nk-1;
    for(int j=mid+1;j<=M;j++)
    {
        z->child[j-mid-1]=w->child[j];
        w->child[j]=NULL;
    }
    r=x;
    }
    else
    {
        int mid=M/2;
        btnode*x=s1.top();
        btnode*z=createnode(w->data[mid+1]);

         int xnum=w->data[mid];
         int k=0,pos;
         while((xnum>x->data[k])&&(w->data[k]!=0))
               {
               k++;
               }
               pos=k;
        for(k=M-2;k>pos;k--)
        {
            x->data[k]=x->data[k-1];
        }
        x->data[pos]=xnum;
        x->nk=x->nk+1;
        for(k=M-1;k>pos;k--)
        {
            x->child[k]=x->child[k-1];
        }
        x->child[pos]=w;
        x->child[pos+1]=z;
     for(int j=mid+1;j<M;j++)
    {
     z->data[j-mid-1]=w->data[j] ;
     z->nk=z->nk+1;
     w->data[j]=0;
     }
     z->nk=z->nk-1;
    for(int j=mid+1;j<=M;j++)
    {
        z->child[j-mid-1]=w->child[j];
        w->child[j]=NULL;
    }
    w=s1.top();
    s1.pop();

    }

    }
    return r;
}
}
btnode*insertin(btnode*r,int x)
{
    int i=0;
     if(r==NULL)
    {

     r=createnode(x);
    }
    else
    {

        stack<btnode*> s1;
        btnode* curr=r;
        while(curr!=NULL)
        {
            if(curr->nk<M-1)
            {

                int pos;

                i=0;
                while((curr->data[i]<x)&&(curr->data[i]!=0))
                {
                    i++;
                }
                pos=i;
                for(i=M-2;i>pos;i--)
                {
                    curr->data[i]=curr->data[i-1];
                }
                curr->data[pos]=x;
                curr->nk=curr->nk+1;
                goto there;
                break;
            }
            else
            {
                s1.push(curr);
                i=0;
                while((x>curr->data[i])&&(i<M-2))
                {
                    i++;
                }
                curr=curr->child[i];
            }

        }

        s1.top()->child[i]=createnode(x);

    }
    there:;
    return r;
}
int main()
{
    root=insertin(root,3);
    root=insertin(root,5);
    root=insertin(root,2);
    root=insertin(root,1);
    root=insertin(root,10);

levelorder(root);
    return 0;

}
