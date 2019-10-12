#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
struct btnode
 {
    int data;
    btnode*left;
    btnode*right;
} *root=NULL,*root1=NULL;

queue<btnode*> q;
queue<btnode*> level;
btnode* insertin(btnode* r,int x)
{
    btnode*newnode=new btnode;
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    if(q.empty())
    {
        r=newnode;
        q.push(r);
    }
    else
    {
        btnode*temp=q.front();
        if(temp->left==NULL)
        {
            temp->left=newnode;
            q.push(newnode);
        }
        else
        {
            temp->right=newnode;
            q.push(newnode);
            q.pop();
        }

    }
    return r;
}
btnode* inserts(btnode*r,char*s,int x)
{
    btnode*p,*curr=r;
    btnode*newnode=new btnode;
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    if(r==NULL)
        r=newnode;
    else
    {


    for(int i=0;s[i]!='\0';i++)
    {

        p=curr;
        if(p==NULL)
           break;
        if(s[i]=='L')
            curr=curr->left;
        else
            curr=curr->right;
    }
    if(p!=NULL)
    {

     if(curr==NULL)
    {
    int n=strlen(s);
    if(s[n-1]=='L')
    {
        p->left=newnode;
    }
    else
    {
       p->right=newnode;
    }
    }
    else
    {
        cout<<"Element already exists there"<<endl;
        cout<<"Do you want to still add element";
        int ch;
        cin>>ch;
        if(ch)
            curr->data=x;
        else
        cout<<"Not Changed";
    }
    }
    else
    {
        cout<<"OOPS!Cannot be added"<<"  Enter correct string"<<endl;

    }
    }
    return r;
}
void inorder(btnode*r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        cout<<r->data<<"->";
        inorder(r->right);
    }
}

void levelorder(btnode*r)
{
  level.push(r);

  while(!level.empty())
  {
      btnode*temp=level.front();


      cout<<temp->data<<"->";
      if(temp->left!=NULL)
      {
      level.push(temp->left);
      }
      if(temp->right!=NULL)
        level.push(temp->right);
      level.pop();
  }
}
int main()
{
    root=insertin(root,1);
    root=insertin(root,2);
    root=insertin(root,3);
    root=insertin(root,4);
    root=insertin(root,5);
    root=insertin(root,6);
    root=insertin(root,7);
    root=insertin(root,8);
    root=insertin(root,9);
    root=insertin(root,10);
    root=insertin(root,11);
    root=insertin(root,12);
    root=insertin(root,13);
    root=insertin(root,14);
    root=insertin(root,15);

    inorder(root);
    cout<<endl;
    levelorder(root);
    char t[1]={'L'};
    root1=inserts(root1,t,1);
    int choice=1;
    while(choice)
    {
        cout<<endl;

        char s[100];
        cout<<"Enter the string"<<endl;
        cin>>s;
        int x;
        cout<<"Enter the element"<<endl;
        cin>>x;
        root1=inserts(root1,s,x);
        cout<<"Enter the choice"<<endl;
        cin>>choice;
    }
    inorder(root1);


    return 0;
}
