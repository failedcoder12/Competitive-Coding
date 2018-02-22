
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
	struct Node *child;
};

Node* newNode(int data){
	Node *newNode = new Node;
	newNode->next = newNode->child = NULL;
	newNode->data = data;
	return newNode;
}

Node *addsibling(Node *n,int data){
	if(n==NULL)
		return NULL;
	while(n->next)
		n=n->next;
	return (n->next = newNode(data));
}

Node *addchild(Node *n,int data){
	if(n==NULL)
		return NULL;
	if(n->child)
		return addsibling(n->child,data);
	return (n->child = newNode(data));
}

void transverseTree(Node *root){
	if(root == NULL)
		return;
	while(root){
		cout<<" "<<root->data;
		if(root->child)
			transverseTree(root->child);
		root = root->next;
	}
}

int main(){
	Node *root = newNode(10);
	Node *n1 = addchild(root,2);
	Node *n2 = addchild(root,3);
	Node *n3 = addchild(root,4);
	Node *n4 = addchild(root,5);
	Node *n5 = addchild(n3,6);
	Node *n6 = addchild(n4,7);
	Node *n7 = addchild(n4,8);
	Node *n8 = addchild(n4,9);	
	transverseTree(root);
	return 0;
}