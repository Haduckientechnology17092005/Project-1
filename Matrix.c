#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

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
    List *PointToHeadedNode;
};
typedef struct ContansList *Matrix;

Matrix createMatrix(int max_size){
    Matrix mt = malloc(sizeof(struct ContansList));
    mt->max_size = max_size;
    mt->PointToHeadedNode = malloc((max_size + 1)*sizeof(struct Node));
    return mt;
}

List createNode(float data) {
    List lt = malloc(sizeof(struct Node));
    lt->data = data;
    lt->next = NULL;
    lt->prev = NULL;
    return lt;
}

List createList() {
    List headerNode = malloc(sizeof(struct Node));
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

List addNodetoList2(int n) {
    List headerNode = createList();
    Position p = headerNode;
    for(int i = 1; i <= n + 1; i++){
        List newNode = createNode(0);
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
        (*A)->PointToHeadedNode[i] = headedNode;
    }
}

void deleteNodeMiddle(Matrix *A, int n) {
    for(int i = 1; i <= n; i++) {
        Position p = (*A)->PointToHeadedNode[i];
        for(int j = 1; j <= (n + 1) / 2 + 1; j++){
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
}

List getNodeFromMarix(Matrix A, int x, int y) {
    Position p = A->PointToHeadedNode[x];
    for(int i = 1; i <= y; i++){
        p = p->next;
    }
    return p;
}

List getNodeFromList(List headedNode, int x) {
    for(int i = 1; i <= x; i++){
        headedNode = headedNode->next;
    }
    return headedNode;
}

void displayMatrix(Matrix A, int n) {  
    for(int i = 1; i <= n; i++) {
        Position p = A->PointToHeadedNode[i]->next;
        while(p!= NULL) {
            printf("%.3f\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void displayList(List headedNode){
    headedNode = headedNode->next;
    while(headedNode != NULL) {
        printf("%.3f\t", headedNode->data);
        headedNode = headedNode->next;
    }
}

void charge(int n, Matrix A, List HeadedNodeB, List N0, float err) {
    List N1 = addNodetoList2(n - 1);
    bool dk;
    do{
        dk = 0;
        for(int i = 1; i <= n; i++) {
            float s = 0;
            for(int j = 1; j <= n; j++)
                if(i != j) s += getNodeFromMarix(A, i, j)->data * getNodeFromList(N0,j)->data;
            getNodeFromList(N1, i)->data = (getNodeFromList(HeadedNodeB, i)->data - s) / getNodeFromMarix(A, i, i)->data;
            if(fabs(getNodeFromList(N1, i)->data - getNodeFromList(N0, i)->data) >= err) dk = 1;
        }
        for(int i = 1; i <= n; i++) getNodeFromList(N0, i)->data = getNodeFromList(N1, i)->data;
    }while (dk);
}

int main() {
    Matrix A = createMatrix(MAX_SIZE);

    int n; printf("Nhap so an:\n"); scanf("%d", &n);

    printf("Nhap Ma Tran:\n");
    addListtoMatrix(&A, n);
    displayMatrix(A, n);

    deleteNodeMiddle(&A, n);
    printf("AfterDelete!!!\n");
    displayMatrix(A, n);

    printf("Nhap List B:\n");
    List headedNodeB = addNodetoList(n - 1);

    printf("Nhap nghiem ban dau:\n");
    List N0 = addNodetoList(n - 1);

    float err; printf("Nhap sai so:\n"); scanf("%f", &err);
    charge(n, A, headedNodeB, N0, err);

    printf("Nghiem he phuong trinh:\n");
    displayList(N0);

    return 0;
}
