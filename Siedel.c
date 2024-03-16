#include<stdio.h>
#include <math.h>
#include <stdbool.h>

#define maxn 100 

void inMatrix(int n, float a[][100]){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n + 1; j++) scanf("%f", &a[i][j]);
    }
}

void inExp(int n, float x[]){
    for(int i = 1; i <= n; i++) scanf("%f", &x[i]);
}

void charge(int n, float a[][100], float x[], float err){
    float b[maxn][maxn];
    float y[maxn];
    bool dk;
    do{
        dk = 0;
        for(int i = 1; i <= n; i++){
            float s = 0;
            for(int j = 1; j <= n; j++)
                if(i != j) s += a[i][j] * x[j];
            y[i] = (a[i][n + 1] - s) / a[i][i];
            if(fabs(y[i] - x[i]) >= err) dk = 1;
        }
        for(int i = 1; i <= n; i++) x[i] = y[i];
    }while (dk);
}

void outExp(int n, float x[]){
    for(int i = 1; i <= n; i++) printf("%.3f\t", x[i]);
}

int main(){
    float a[maxn][maxn];
    int n; printf("Nhap n:\n"); scanf("%d", &n);
    printf("Nhap ma tran:\n");
    inMatrix(n, a);
    float x[maxn];
    printf("Nhap nghiem gan dung cua he phuong trinh:\n");
    inExp(n, x);
    float err; printf("Nhap sai so:\n"); scanf("%f", &err);
    charge(n, a, x, err);
    printf("Nghiem cua he phuong trinh:\n");
    outExp(n, x);
}