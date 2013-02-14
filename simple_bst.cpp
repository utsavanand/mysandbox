#include<iostream>

using namespace std;

typedef struct node{
struct node *left;
struct node *right;
int data;
}Node;

Node *root;

Node *insert(Node *p,int d)
{
cout<<"Hey\n";
Node *temp;
temp=new Node;
temp->data=d;
temp->left=NULL;
temp->right=NULL;
if(p==NULL)
	{
	p=temp;
	}
	else 
	{
	if(d < p->data)
		{
		p->left=insert(p->left,d);
		}
	else
		{
		p->right=insert(p->right,d);
		}
	}
return p;
}

void print_inorder(Node *p)
{
if(p!=NULL)
	{
	
		print_inorder(p->left);
		cout<<"\t"<<p->data<<"\n";
		print_inorder(p->right);

	}
}

void print_level(Node *p, int n,int count)
{

cout<<"We are at data "<<p->data<<"and at level "<<count<<"\n";

if(p==NULL){
return;
}
else if(n==count)
	{
	cout<<"Caught\n";
	cout<<"\t"<<p->data<<"\n";
	return;
	}

else{
	//cout<<p->data<<" right "<<"Count="<<count<<"\n";
	print_level(p->right,n,count+1);

	//cout<<p->data<<" Left "<<"Count="<<count<<"\n";
	print_level(p->left,n,count+1);
}
}

int main()
{
root=insert(root,12);root=insert(root,4);root=insert(root,26);root=insert(root,2);root=insert(root,10);root=insert(root,20);root=insert(root,82);
print_inorder(root);
cout<<"\nParticular Level\n";
print_level(root,2,0);

return 0;
}

