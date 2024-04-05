#include<stdio.h>
#include<stdlib.h>

#define Max 100

void input_matrix(float a[Max][Max], int n)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("a[%d][%d]=", i, j);
            scanf("%f", &a[i][j]);
        }
    }
}

void output_matrix(float a[Max][Max], int n)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.3f\t", a[i][j]);
        }
        printf("\n");
    }
}

void change_gauss(float a[Max][Max], int n)
{
    for(int k=0; k<n-1; k++){
        for(int i=k+1; i<n; i++){
            float x = a[i][k]/a[k][k];
            for(int j=k; j<n; j++){
                a[i][j] -= a[k][j]*x;
            }
        }
    }
}

void solution_gauss(float a[Max][Max], int n, float b[Max])
{

}

int main ()
{
    int n;
    printf("Nhập n = ");
    scanf("%d", &n);
    float a[Max][Max];
    float b[Max];
    input_matrix(a, n);
    output_matrix(a, n);
    change_gauss(a,n);
    output_matrix(a, n);

    return 0;
}
