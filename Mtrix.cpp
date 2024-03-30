#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct Node {
    float data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node *List;
typedef struct Node *Position;

struct ContansList {
    int max_size;
    List *Hnode;
};
typedef struct ContansList *Matrix;

Matrix createMatrix(int max_size){
    Matrix mt = (Matrix)malloc(sizeof(struct ContansList));
    mt->max_size = max_size;
    mt->Hnode = (List*)malloc((max_size + 1)*sizeof(struct Node));
    return mt;
}

List createNode(float data) {
    List lt = (List)malloc(sizeof(struct Node));
    lt->data = data;
    lt->next = NULL;
    lt->prev = NULL;
    return lt;
}

List createList() {
    List headerNode = (List)malloc(sizeof(struct Node));
    headerNode->next = NULL;
    headerNode->prev = NULL;
    return headerNode;
}

List addNodetoList(int n) {
    List headerNode = createList();
    Position p = headerNode;
    for(int i = 1; i <= n + 1; i++){
        float x; scanf("%f", &x);
        List newNode = createNode(x);
        newNode->next = p->next;
        newNode->prev = p;
        p->next = newNode;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;
        }
        p = p->next;
    }
    return headerNode;
}

void addListtoMatrix(Matrix *A, int n) {
    for(int i = 1; i <= n; i++) {
        List headedNode = createList();
        headedNode = addNodetoList(n);
        (*A)->Hnode[i] = headedNode;
    }
}

void delete_Matrix(Matrix *A, int n)
{
	for(int i=1;i<=n;i++)
	{
		Position p = (*A)->Hnode[i];
		for(int j = 1; j<=(n+1)/2 +1; j++)
		{
			p=p->next;
		}
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
}

List get_Node (Matrix A, int x, int y)
{
	Position p = A->Hnode[x];
	for(int i=1;i<=y;y++)
	{
		p = p->next;
	}
	return p;
}

void displayMatrix(Matrix A, int n) {  
    for(int i = 1; i <= n; i++) {
        Position p = A->Hnode[i]->next;
        while(p!= NULL) {
            printf("%.3f\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main() {
    Matrix A = createMatrix(MAX_SIZE);
    int n; scanf("%d", &n);
    addListtoMatrix(&A, n);
    displayMatrix(A, n);
    printf("\n----------After deleting !----------\n");
    delete_Matrix(&A, n);
    displayMatrix(A,n);
    float k = get_Node(A, 1, 2);
    printf("%f", k);
    return 0;
}
