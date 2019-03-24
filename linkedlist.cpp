#include<iostream> 
using namespace std; 


class Node{
	public:
	int data;
	Node *next;
};

//to print thje whole linked lists
void printList(Node *n){
	while(n!=NULL){
		cout<<n->data<<" ";
		
		n=n->next;
	}
	cout<<endl;
}

//pushing element to the linkedlists
void push(Node **head_ref,int new_data){
	Node *new_node=new Node();
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}

//to insert an element after a node
void insertAfter(Node *prev_node,int new_data){
	Node *new_node=new Node();
	if(prev_node!=NULL){
		new_node->data=new_data;
		new_node->next=prev_node->next;
		prev_node->next=new_node;	
	}else{
		printf("The linkedlist can not be null");
	}
	
}

//to append an element to the linkedlisstss
void append(Node **head_ref,int new_data){
	Node *new_node=new Node();
	
	Node *last=*head_ref;
	
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL){
		*head_ref=new_node;
		return;
	}
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=new_node;
	
}

//to delete a node from the linkeed lists
void deleteNode(Node **head_ref,int key){
	Node *node=*head_ref,*prev;
	if(*head_ref==NULL){
		return;
	}
	if(node->data==key){
		*head_ref=node->next;
		free(node);
		return;
	}
	while(node->data!=key){
			prev=node;
			node=node->next;
	}
	prev->next=node->next;
	free(node);
	return;
}
void deletenode(Node **head_ref,int position){
	Node *temp=*head_ref,*prev;
	int count=0;
	if(temp==NULL) return;
	if(position==0){
		*head_ref=temp->next;
		free(temp);
		return;
	}
	while(count!=position){
		prev=temp;
		temp=temp->next;
		count++;
	}
	prev->next=temp->next;
	free(temp);
	
}
void deleteLinkedlists(Node **head_ref){
	Node *temp=*head_ref,*nxt;
	if(temp==NULL)return;
	while(temp!=NULL){
		*head_ref=temp->next;
		free(temp);
		temp=*head_ref;
	}
}
int main(){
	Node *head=new Node();
	Node *second=new Node();
	Node *third=new Node();
	
	head->data=56;
	head->next=second;
	
	second->data=89;
	second->next=third;
	
	third->data=45;
	third->next=NULL;
	
	//deleteLinkedlists(&head);
	
	printList(head);
	return 0;
}
