#include <stdio.h>
 
struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};

 struct Node *makeNode(int x){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void duyet(struct Node *head){
	while(head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int Size(struct Node *head){
	int cnt = 0;
	while(head != NULL){
		++cnt;
		head = head->next;
	}
	return cnt;
}
 
void InsertFirst(struct Node **head, int x){
	struct Node *newNode = makeNode(x);
	newNode->next = (*head); // cho phan next cua Node mo tro vao Node dau hien tai
	if(*head != NULL)
		(*head)->prev = newNode;
	(*head) = newNode;
}

void InsertLast(struct Node **head, int x){
	struct Node *newNode = makeNode(x);
	if(*head == NULL){
		*head = newNode; return;
	}
	struct Node *temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}
 
void InsertMiddle(struct Node **head, int x, int k){
	int n = Size(*head);
	if(k < 0 || k > n) return;
	if(k == 0){
		InsertFirst(head, x); return;
	}
    if(k == n){
		InsertLast(head, x); return;
	}
	struct Node *temp = *head;
	for(int i = 0; i < k - 1; i++){
		temp = temp->next;
	}
	struct Node *newNode = makeNode(x);
	newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
 
void deleteFirst(struct Node **heap){
    if(*heap == NULL) return;
    *heap = (*heap)->next;
    (*heap)->prev = NULL;
}

void deleteLast(struct Node **heap){
    if(*heap == NULL) return;
    int n = Size(*heap);
    struct Node *temp = *heap;
    for(int i = 0; i < n - 1; i++)
        temp = temp->next;
    temp->prev->next = NULL;
}

void deleteMiddle(struct Node **heap, int k){
    int n = Size(*heap);
    if(k < 0 || k > n - 1) return;
    if(k == 0){
        deleteFirst(heap); return;
    }
    if(k == n - 1){
        deleteLast(heap); return;
    }
    struct Node *temp = *heap;
    for(int i = 0; i < k; i++)
        temp = temp->next;
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
}


int main(){
	struct Node *head = NULL;
	while(1){
		printf("---------------DSLK---------------\n");
		printf("1. Them Node vao dau\n");
		printf("2. Them Node vao cuoi\n");
		printf("3. Them Node vao giua\n");
        printf("4. Xoa Node o dau\n");
		printf("5. Xoa Node o cuoi\n");
		printf("6. Xoa Node o giua\n");
        printf("7. Kich thuoc\n");
		printf("8. Duyet\n");
		printf("9. Thoat !\n");
		printf("----------------------------------\n");
		printf("Nhap lua chon :"); int lc; scanf("%d", &lc);
		if(lc == 1){
			int x; printf("Nhap x : ");
			scanf("%d", &x);
			InsertFirst(&head, x);
		}
		else if(lc == 2){
			int x; printf("Nhap x : ");
			scanf("%d", &x);
			InsertLast(&head, x);
		}
		else if(lc == 3){
			int x; printf("Nhap x : ");
			scanf("%d", &x);
			int k; printf("Nhap vi tri chen :");
			scanf("%d", &k);
			InsertMiddle(&head, x, k);
		}
        else if(lc == 4){
			deleteFirst(&head);
		}
		else if(lc == 5){
			deleteLast(&head);
		}
		else if(lc == 6){
			int k; printf("Nhap vi tri xoa :");
			scanf("%d", &k);
			deleteMiddle(&head, k);
		}
        else if(lc == 7){
			printf("Kich thuoc : %d\n", Size(head));
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
