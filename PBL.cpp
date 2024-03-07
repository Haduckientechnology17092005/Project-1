#include <iostream>
 
using namespace std;
 
struct Node{
	int data;
	Node *next;
	Node *prev;
};

Node *makeNode(int x){
	Node *newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void duyet(Node *head){
	while(head != NULL){
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

int Size(Node *head){
	int cnt = 0;
	while(head != NULL){
		++cnt;
		head = head->next;
	}
	return cnt;
}
 
void InsertFirst(Node **head, int x){
	Node *newNode = makeNode(x);
	newNode->next = (*head); // cho phan next cua Node mo tro vao Node dau hien tai
	if(*head != NULL)
		(*head)->prev = newNode;
	(*head) = newNode;
}

void InsertLast(Node **head, int x){
	Node *newNode = makeNode(x);
	if(*head == NULL){
		*head = newNode; return;
	}
	Node *temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}
 
void InsertMiddle(Node **head, int x, int k){
	int n = Size(*head);
	if(k < 0 || k > n) return;
	if(k == 0){
		InsertFirst(head, x); return;
	}
    if(k == n){
		InsertLast(head, x); return;
	}
	Node *temp = *head;
	for(int i = 0; i < k - 1; i++){
		temp = temp->next;
	}
	Node *newNode = makeNode(x);
	newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
 
void deleteFirst(Node **heap){
    if(*heap == NULL) return;
    *heap = (*heap)->next;
    (*heap)->prev = NULL;
}

void deleteLast(Node **heap){
    if(*heap == NULL) return;
    int n = Size(*heap);
    Node *temp = *heap;
    for(int i = 0; i < n - 1; i++)
        temp = temp->next;
    temp->prev->next = NULL;
}

void deleteMIddle(Node **heap, int k){
    int n = Size(*heap);
    if(k < 0 || k > n - 1) return;
    if(k == 0){
        deleteFirst(heap); return;
    }
    if(k == n - 1){
        deleteLast(heap); return;
    }
    Node *temp = *heap;
    for(int i = 0; i < k; i++)
        temp = temp->next;
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
}


int main(){
	Node *head = NULL;
	while(1){
		cout << "---------------DSLK---------------\n";
		cout << "1. Them Node vao dau\n";
		cout << "2. Them Node vao cuoi\n";
		cout << "3. Them Node vao giua\n";
        cout << "4. Xoa Node o dau\n";
		cout << "5. Xoa Node o cuoi\n";
		cout << "6. Xoa Node o giua\n";
        cout << "7. Kich thuoc\n";
		cout << "8. Duyet\n";
		cout << "9. Thoat !\n";
		cout << "----------------------------------\n";
		cout << "Nhap lua chon :"; int lc; cin >> lc;
		if(lc == 1){
			int x; cout << "Nhap x : ";
			cin >> x;
			InsertFirst(&head, x);
		}
		else if(lc == 2){
			int x; cout << "Nhap x : ";
			cin >> x;
			InsertLast(&head, x);
		}
		else if(lc == 3){
			int x; cout << "Nhap x : ";
			cin >> x;
			int k; cout << "Nhap vi tri chen :";
			cin >> k;
			InsertMiddle(&head, x, k);
		}
        else if(lc == 4){
			deleteFirst(&head);
		}
		else if(lc == 5){
			deleteLast(&head);
		}
		else if(lc == 6){
			int k; cout << "Nhap vi tri xoa :";
			cin >> k;
			deleteMIddle(&head, k);
		}
        else if(lc == 7){
			cout << "Kich thuoc :" << Size(head);
		}
		else if(lc == 8){
			duyet(head);
		}
		else{
			break;
		}

	}
	return 0;
}
