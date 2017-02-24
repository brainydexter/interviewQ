#ifndef LinkedList_Utility_h
#define LinkedList_Utility_h

struct Node{
    Node(){}
    
	Node(int data){
	    this->data = data;
	    next = NULL;
	}

int data;
Node* next = NULL;
};

void DisplayList(Node* head);
void Insert(Node** head, int data);
void Insert(Node** head, Node* node);
Node* ConvertArToList(int* ar, int size);
void Reverse(Node** head);

void Reverse(Node** head){
	Node* newHead = NULL;

	Node* current = *head;

	while(current){
		Node* next = current->next;

		current->next = newHead;
		newHead = current;

		current = next;
	}

	*head = newHead;
}

void DisplayList(Node* head){

	while(head != NULL){
		cout << head->data << " ";
		head = head ->next;
	}
	cout << endl;
}

void Insert(Node** head, int data){
    Node* newNode = new Node(data);
    
    newNode->next = *head;
    *head = newNode;
}

void Insert(Node** head, Node* newNode){
	if(!newNode) return;

	newNode-> next = *head;
	*head = newNode;
}

Node* ConvertArToList(int* ar, int size){
    Node dummy;

    Node* tail = &dummy;
    
    for(int i = 0; i < size; i++){
        Insert(&tail->next, ar[i]);

        tail = tail->next;
    }
    
    return dummy.next;
}

#endif // LinkedList_Utility_h