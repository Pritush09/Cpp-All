#include<bits/stdc++.h>
using namespace std;

// 2 ways to represent the graph 1. Adjacency matrix  2. adjacency list
//const  int nn= 1e3;
//int g[nn][nn];
//above 2 lines is for the cp purpose where we will be given the max in put for the shape of graph will be max 10^3 and as the global variable
// is always initialised with 0 we dont have to re intialised the values with 0

int main(){
    // Ajacency Matrix format 
    // disadvantage space complexity O(n^2) & we cannot make a graph grater than (10^4x10^4)
    int V , E;
    cin >> V >> E;
    // we do +1 here bcz the input are according with the name of the vertex like 1,4 have edge so to represent it we will have to store it in 
    // 0th row 3rd column 
    int G[V+1][V+1];

    //initializing with 0
    for(int i=1; i<=V ; i++){
        for(int j=1 ; j<=V ; j++){
            G[i][j]=0;
        }
    }

    // Inputing the graph
    for (int i=1 ; i<=E ; i++ ){
        int v1,v2;
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
}