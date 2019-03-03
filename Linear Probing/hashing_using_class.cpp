/*NAME : AVINASH AGARWAL
  ROLL NO : 17CS8065
  DATE OF ASSIGNMENT : 12/02/2019
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
			if(search(x, 1) == -1){
				head = new sllnode(x, head);
				listLength ++;
			}
			else{
				cout<<"Element already Present\n";
			}
		}
		void insertEnd(int x){
			if(search(x, 1) == -1) {
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
			else{
				cout<<"Element already Present\n";
			}
		}
		void delBegin(){
			sllnode *temp = head;
			head = head->next;
			delete [] temp;
			listLength --;
		}
		void delEnd(){
			sllnode *temp = head;
			if(temp!=NULL){
				if(temp->next==NULL)
				{
					head = NULL;
					delete[] temp;
				}
				else{
					while(temp->next->next!=NULL)
						temp=temp->next;
					sllnode *del = temp->next;
					temp->next = NULL;
					delete [] del;
				}
				listLength --;
			}
		}

		int search(int data, int option);

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

int sllist :: search(int data, int option){
	sllnode *temp = head;
	int index = 0;
	int found = 0;
	if(temp==NULL){
		if(option==0)
			cout<<"List Empty, Not Found!"<<endl;
		return -1;
	}
	else{
		while(temp!=NULL){
			if(temp->data == data){
				if(option==0)
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
			if(option==0)
				cout<<"Element not Present"<<endl;
			return -1;
		}
		else
			return 0;
	}
}

class hashTable
{
	public:
		sllist *table;
		int hashFunc;
		hashTable(int length){
			table = new sllist[length];
			hashFunc = length;
		}
		void insertIntoTable(int data){
			int index = data%hashFunc;
			table[index].insertEnd(data);
		}
		void display();
		void search(int data);
		~hashTable(){
			delete [] table;
		}
};

void hashTable :: display(){
	for(int i=0;i<hashFunc;i++){
		sllist temp = table[i];
		cout<<"At Index "<<i<<": ";
		temp.display();
		cout<<endl;
	}
}

void hashTable :: search(int data){
	int index = data%hashFunc;
	cout<<"Searching at Index "<<index<<" of the Hash Table"<<endl;
	table[index].search(data, 0);	
}

int main() {
	
	// sllist List;
	// List.insertBegin(5);
	// List.insertBegin(10);
	// List.insertBegin(15);
	// List.insertBegin(20);
	// List.display();
	// List.search(15);

	int size;
	cout<<"Enter the size of the Hash Table:\n";
	cin>>size;

	hashTable htable(size);
	int cont = 0;
	while(cont==0){
		cout<<"Enter 0 to insert element in Hash Table\n";
		cout<<"Enter 1 to display the Hash Table\n";
		cout<<"Enter 2 to search in the Hash Table\n";
		cout<<"Enter 3 to exit\n";
		int inp;
		cin>>inp;
		int data;
		switch(inp){
			case 0: cout<<"Enter the element you want to insert: "<<endl;
					cin>>data;
					htable.insertIntoTable(data);
					break; 
			case 1: htable.display();
					break;
			case 2: cout<<"Enter the element you want to search: "<<endl;
					cin>>data;
					htable.search(data);
					break;
			case 3: cont = 3;
					break;
			default: cout<<"Enter a valid option\n";
		}
	}
	return 0;
}
