/*NAME : AVINASH AGARWAL
  ROLL NO : 17CS8065
  DATE OF ASSIGNMENT : 01/03/2019
  ASSIGNMENT NAME :  BINARY SEARCH TREE*/

#include<iostream>
#include <stdlib.h>
using namespace std;

class BSTNode{
	public:
		int data;
		BSTNode* leftTree;
		BSTNode* rightTree;
		BSTNode() {
			data=0;
			leftTree = NULL;
			rightTree = NULL;
		}
		BSTNode(int value){
			data = value;
			leftTree = NULL;
			rightTree = NULL;
		}
};

class BST {
	public:
		BSTNode *root;
		int count;

		BST(int value){
			root = new BSTNode(value);
			count = 1;
		}

		BSTNode* insert(int value, BSTNode* node){
			if(node == NULL){
				return new BSTNode(value);
			}

			else if(value < node->data){
				node->leftTree = insert(value, node->leftTree);
			}

			else if(value > node->data){	
				node->rightTree = insert(value, node->rightTree);
			}
			return node;
		}

		int search(int query, BSTNode* temp){ 
			
			if(temp!=NULL){
				if(temp->data==query)
					return count;
				else if((temp->data)> query){
					count++;
					search(query,temp->leftTree);
				}
				else if((temp->data)<query){
					count++;
					search(query,temp->rightTree);
				}
			}
			return count;
		}

		void preorder(BSTNode* temp){
			if(temp!=NULL){
				cout<<temp->data<<" ";
				preorder(temp->leftTree);
				preorder(temp->rightTree);
			}
		}

		void postorder(BSTNode* temp){
			if(temp!=NULL){
				postorder(temp->leftTree);
				postorder(temp->rightTree);
				cout<<temp->data<<" ";
			}
		}

		void inorder(BSTNode* temp){
			if(temp!=NULL){
				inorder(temp->leftTree);
				cout<<temp->data<<" ";
				inorder(temp->rightTree);
				
			}
		}
};

int main(){

	int arr[20];
	srand(time(NULL));
	for (int i=0;i<20;i++){
		arr[i]=rand()%50+1;
	}
	cout<<"Seeding Elements:"<<endl;
	for (int i=0;i<20;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	BST bst(arr[0]);
	for (int i=1;i<20;i++){
		bst.insert(arr[i], bst.root);
	}

	cout<<endl<<"Preorder Traversal:"<<endl;
	bst.preorder(bst.root);

	cout<<endl<<endl<<"Postorder Traversal:"<<endl;
	bst.postorder(bst.root);

	cout<<endl<<endl<<"Inorder Traversal:"<<endl;
	bst.inorder(bst.root);

	int comparison = 0;
	for(int i=0;i<20;i++) {
		comparison += bst.search(arr[i],bst.root);
		bst.count=1;
	}
 
	cout<<endl<<endl<<"Total comparisons = "<<comparison<<endl;
	cout<<"Average comparisons = "<<comparison/20.0<<endl;
}