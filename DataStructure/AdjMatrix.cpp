#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

//the size of matrix
int n;
//the number of edges
int m;
//declare the Matrix with MAXN
int Adj[ MAXN ][ MAXN ];

void inputMatrix() {
    int a, b;

    for (int i = 0; i < m; i++) {
        //input and store
        cin >> a >> b;
        Adj[ a ][ b ] = 1;
    }
}

void printMatrix() {
    printf("The adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++) {
            printf("%3d ", Adj[ i ][ j ]);
        }
        puts("|");
    }
}

int main() {
    //initialize the matrix
    memset(Adj, 0, sizeof(Adj));	//初始化
    cin >> n >> m;
    inputMatrix();
    printMatrix();
}