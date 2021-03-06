#include<iostream>
#define MAX(a,b) (a>b)?a:b

using namespace std;

typedef struct node{
struct node *left;
struct node *right;
int data;
}Node;

Node *root;

Node *insert(Node *p,int d)
{

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

int print_sum_given_level(Node *p, int desired, int current){

if(p==NULL){
cout<<"\n Loop 1 \n";
return 0;
}
else if(desired==current){
cout<<"\n Loop 2 \t"<<p->data;
return p->data;
}
else{
cout<<"\n Loop 3 \t"<<p->data;
int sum=print_sum_given_level(p->left,desired,current+1)+print_sum_given_level(p->right,desired,current+1);
return sum;
}

}

int height_tree(Node *p){
if(p==NULL){
return 1;
}
else{
return MAX(height_tree(p->left)+1,height_tree(p->right)+1);
}
}


int main()
{
root=insert(root,12);root=insert(root,4);root=insert(root,26);root=insert(root,2);root=insert(root,10);root=insert(root,20);root=insert(root,82);root=insert(root,822);root=insert(root,8222);
print_inorder(root);
cout<<"\nParticular Level sum - \n";
int sum=print_sum_given_level(root,3,0);
cout<<"\nSum of level 3 here="<<sum<<"\n";
cout<<"height="<<height_tree(root)<<"\n";
return 0;
}

