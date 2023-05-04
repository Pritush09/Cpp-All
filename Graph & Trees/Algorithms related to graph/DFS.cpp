#include<bits/stdc++.h>
using namespace std;
//it uses stack
const int N = 1e3;
int V , E;
int G[N][N];
// for visited
int visited[N];


void DFS(int vertex){
    /*Take action on the node after entering the node*/
    int i;
    cout << vertex << endl;
    visited[vertex] = 1;
    for(i=1 ; i<=V ; i++){
         
        if (G[vertex][i]==1 && visited[i]!=1){
            /*take action on the child before entering the child*/
            cout << "parent " << vertex << " child " << i << endl;
            DFS(i);
            /*Take action on the child after entering the child node*/
        }
        else if (G[vertex][i]==1 && visited[i]==1){
            cout << "parent " << vertex << " child " << i << endl;
            continue;
        }
        else{
            
            continue;
        }
    }
    /*Take action on node after exiting the node*/
}



int main(){
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


    DFS(1);
}
/*
6 9
1 3
1 5
3 5
3 6
3 4
3 2
2 6
4 6
5 6
*/
