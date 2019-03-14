/*NAME : AVINASH AGARWAL
  ROLL NO : 17CS8065
  DATE OF ASSIGNMENT : 08/02/2019
  ASSIGNMENT NAME : LINKED LIST*/

#include<iostream>
using namespace std;

class sllnode {
	public:
		int data;
		sllnode *next;
		sllnode(){
			data = 0;
			next = NULL;
		}
		sllnode(int x, sllnode *p){
			data  = x;
			next = p;
		}
		~ sllnode(){};
};

class sllist{
	public:
		sllnode *head;
		int listLength;
		sllist(){
			head = NULL;
			listLength = 0;
		}
		void insertBegin(int x){
				head = new sllnode(x, head);
				listLength ++;
		}
		void insertEnd(int x){
			sllnode *temp = head;
			if(temp == NULL ){
				head = new sllnode(x, NULL);
			}
			else {
				while(temp->next!=NULL)
				temp=temp->next;
				temp->next = new sllnode(x, NULL);
			}
			listLength ++;
		}
		void delBegin(){
			sllnode *temp = head;
			if(temp!=NULL){
				head = head->next;
				delete temp;		
				listLength --;
			} else {
				cout<<"List Empty!";
			}
		}
		void delEnd(){
			sllnode *temp = head;
			if(temp!=NULL){
				if(temp->next==NULL)
				{
					head = NULL;
					delete temp;
				}
				else{
					while(temp->next->next!=NULL)
						temp=temp->next;
					sllnode *del = temp->next;
					temp->next = NULL;
					delete del;
				}
				listLength --;
			}
			else{
				cout<<"List Empty"<<endl;
			}
		}

		int search(int data);

		void display(){
			sllnode *temp=head;
			while(temp!=NULL) {
				cout<<temp->data<<" --> ";
				temp=temp->next;
			}
			cout<<"NULL"<<endl;
			cout<<"Length: "<<listLength<<endl;
		}
		~ sllist(){};
};

int sllist :: search(int data){
	sllnode *temp = head;
	int index = 0;
	int found = 0;
	if(temp==NULL){
		cout<<"List Empty, Not Found!"<<endl;
		return -1;
	}
	else{
		while(temp!=NULL){
			if(temp->data == data){
				cout<<"Element Found at index: "<<++index<<endl;
				found = 1; 
				break;
			}
			else{
				index ++;
				temp = temp->next;
			}
		}
		if(found == 0){
			cout<<"Element not Present"<<endl;
			return -1;
		}
		else
			return 0;
	}
}

int main() {
	sllist list;
	list.insertBegin(5);
	list.insertBegin(10);
	list.insertEnd(2);
	list.insertEnd(20);
	list.insertEnd(2);
	list.delBegin();
	list.delEnd();
	list.display();
	return 0;
}