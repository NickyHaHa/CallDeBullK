#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

//the size of matrix
int n;
//the number of edges
int m;
//declare the List with MAXN
vector<pair<int, int>> Adj[ MAXN ];

void inputList() {
    //weight
    int a, b, w;
    
    for (int i = 0; i < m; i++) {
        //input and store
        cin >> a >> b >> w;
        Adj[ a ].push_back(make_pair(w, b));        //雙向圖
        Adj[ b ].push_back(make_pair(w, a));

    }
}

void printList() {
    printf("The adjacency list:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] --> ", i);
        for (auto p : Adj[ i ]) {
            printf("(%d, %d)  ---> ", p.first, p.second);
        }
        puts("NULL");
    }
}

int main() {
    cin >> n >> m;
    inputList();
    printList();
}