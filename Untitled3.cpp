#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void multiply(int **A, int **B, int **C, int n1, int m1, int n2, int m2) {
    if (m1 != n2) {
        cout << "Matrices cannot be multiplied!";
        return;
    }
    if (n1 == 1 && m2 == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int **C11 = new int *[n1/2], **C12 = new int *[n1/2];
    int **C21 = new int *[n1/2], **C22 = new int *[n1/2];
    int **A11 = new int *[n1/2], **A12 = new int *[n1/2];
    int **A21 = new int *[n1/2], **A22 = new int *[n1/2];
    int **B11 = new int *[n2/2], **B12 = new int *[n2/2];
    int **B21 = new int *[n2/2], **B22 = new int *[n2/2];
    int **M4 = new int *[n1/2];
    for (int i = 0; i < n1/2; i++) {
        C11[i] = new int[m2/2], C12[i] = new int[m2/2];
        C21[i] = new int[m2/2], C22[i] = new int[m2/2];
        A11[i] = new int[m1/2], A12[i] = new int[m1/2];
        A21[i] = new int[m1/2], A22[i] = new int[m1/2];
        B11[i] = new int[m2/2], B12[i] = new int[m2/2];
        B21[i] = new int[m2/2], B22[i] = new int[m2/2];
        M4[i] = new int[m2/2];
    }
    for (int i = 0; i < n1/2; i++) {
        for (int j = 0; j < m1/2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+m1/2];
            A21[i][j] = A[i+n1/2][j];
            A22[i][j] = A[i+n1/2][j+m1/2];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+m2/2];
            B21[i][j] = B[i+n2/2][j];
            B22[i][j] = B[i+n2/2][j+m2/2];
        }
    }
    int **temp1 = new int *[n1/2];
    for (int i = 0; i < n1/2; i++) {
        temp1[i] = new int[m1/2];
    }
    for (int i = 0; i < n1/2; i++) {
        for (int j = 0; j < m1/2; j++) {
            temp1[i][j] = 0;
            for (int k = 0; k < m2/2; k++) {
                temp1[i][j] += (A21[i][k] - A11[i][k]) * (B12[k][j] + B22[k][j]);
            }
        }
    }
    multiply(temp1, B11, C11, n1/2, m1/2, n2/2, m2/2);
    multiply(A11, B12, C12, n1/2, m1/2, n2/2, m2/2);
    multiply(A12, B22, C22, n1/2, m1/2, n2/2, m2/2);
    multiply(A22, B21, C21, n1/2, m1/2, n2/2, m2/2);
    for (int i = 0; i < n1/2; i++) {
        for (int j = 0; j < m2/2; j++) {
            C[i][j] = C11[i][j] + C12[i][j];
            C[i][j+m2/2] = C21[i][j] + C22[i][j];
            C[i+n1/2][j] = C11[i][j] + C21[i][j];
            C[i+n1/2][j+m2/2] = C12[i][j] + C22[i][j];
        }
    }
}


void printMatrix(int **arr,int n)
{
    cout<<"Product:"<<endl;

     for(int i=0;i<n;++i){
         for(int j=0;j<n;++j){
             cout<<arr[i][j]<<" ";
         }
         cout<<endl;
     }
}

int main(){

    int n1, m1, n2, m2;
    cout << "Enter the number of rows and columns of matrix A: ";
    cin >> n1 >> m1;
    cout << "Enter the number of rows and columns of matrix B: ";
    cin >> n2 >> m2;

    if (m1 != n2)
    {
        cout << "Matrices cannot be multiplied!";
        return 0;
    }

    int **A = new int *[n1];
    int **B = new int *[n2];
    int **C = new int *[n1];

    for (int i = 0; i < n1; i++)
        A[i] = new int[m1];

    for (int i = 0; i < n2; i++)
        B[i] = new int[m2];

    for (int i = 0; i < n1; i++)
        C[i] = new int[m2];

    cout << "Enter the elements of matrix A:" << endl;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            cin >> A[i][j];

    cout << "Enter the elements of matrix B:" << endl;
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < m2; j++)
            cin >> B[i][j];

    multiply(A, B, C, n1, m1, n2, m2);
    printMatrix(C,n1);

    return 0;
}
