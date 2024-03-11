#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
	node *pre;
};
struct douList{
	node *head;
	node *tail;
};
douList *createList(int x){
	douList *l = new douList;
	l->head = new node;
	l->head->data = x;
	l->head->pre = NULL;
	l->head->next = NULL;
	l->tail = l->head;
	return l;
}
douList *addHead(douList *l, int x){
	node *temp = new node;
	temp->data = x;
	temp->pre = NULL;
	temp->next = l->head;
	l->head->pre = temp;
	l->head = temp;
	return l;
}
douList *addTail(douList *l, int x){
	node *temp = new node;
	temp->data = x;
	temp->next = NULL;
	temp->pre = l->tail;
	l->tail->next = temp;
	l->tail = temp;
	return l;
}
douList *addAt(douList *l, int k, int x){
	node *p = l->head;
	for (int i = 0; i < k-1; i++){
		p = p->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->pre = p;
	temp->next = p->next;
	p->next->pre = temp;
	p->next = temp;
	return l;
}
void printList(douList *l){
	node *p = l->head;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

int main(){
	int n, x, k;
	cin >> n;
	cin >> x;
	douList *l = createList(x);
	for (int i = 1; i < n; i++){
		cin >> x;
		l = addTail(l, x);
	}
	cin >> k >> x;
	if (k == 0){
		l = addHead(l, x);
	} else if (k == n){
		l = addTail(l, x);
	} else{
		l = addAt(l, k, x);
	}
	printList(l);
	return 0;
}
