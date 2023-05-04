#include<bits/stdc++.h>
using namespace std;
const int N = 1e2;
int V,E;
int G[N][N];


main(){
    cin >> V >> E;

    for(int i=1; i<=V ; i++){
        for(int j=1; j<=V ; j++){
            G[i][j]=0;
        }
    }

    for(int i=1 ; i<= E ; i++){
        int v1 , v2;
        cin >> v1 >> v2;
        G[v1][v2]=1;
        // if it is an undirected graph then this also needed to be there below line
        G[v2][v1]=1;
    }

    // printing the graph G
    for (int i=1 ; i<V+1 ; i++){
        for(int j=1 ; j<V+1 ; j++){
            cout << G[i][j];
        }
        cout << "\n";
    }

    cout << "\n\n";
}