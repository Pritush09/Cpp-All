#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int V , E;
int G[N][N];
// for visited
int visited[N];

// keeping the track of the parent node inorder to keep track of the parent node from which the dfs coming
bool DFS(int vertex , int parent){
    bool isloopexists = false; // this is to keep the track of what is node returning after checking
    int i;
    //cout << vertex << endl;
    visited[vertex] = 1;
    for(i=1 ; i<=V ; i++){
         
        if (G[vertex][i]==1 && visited[i]!=1){
            //cout << "parent " << vertex << " child " << i << endl;
            isloopexists |= DFS(i, vertex); //this is for performing the or between the returning of all the child 
        }
        else if (i==parent){
            continue;
        }
        else if (i!=parent && G[vertex][i]==1 && visited[i]==1){
            return true;
        }
        else{
            
            continue;
        }
    }
    return isloopexists;
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

    // Connected Components

    bool isloopexists=false;

    for(int i=1; i<=V ; i++){
        if (visited[i]==1){
            continue;
        }
        if (DFS(i,0)){
            isloopexists=true;
            break;
        }
    }

    cout << isloopexists << endl;
    

}
/* 8 5
   1 2
   2 3
   2 4
   3 5
   6 7
*/
