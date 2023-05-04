#include<bits/stdc++.h>
using namespace std;
const int N=1e2;
int V,E;
int G[N][N];
int Q[N];
int f=-1,r=-1;
int visited[N];

void push(int value){
    if (r==-1 && f==-1){
        r=0;
        f=0;
        Q[r]=value;
    }
    else if(r==N){
        cout  << "Overflow";
    }

    else{
        r++;
        Q[r]=value;
    }
}


int pop(){
    int re;
    if (r==f==-1){
        cout << "Underflow";
        return -1;
    }
    else if (f>r){
        return -1;
    }
    else{
        re=Q[f];
        f++;
        return re;
    }
}

bool presentinqueue(int val){
    int i;
    for(i=0;i<N;i++){
        if (Q[i]==val){
            return false;
            break;
        }
    }
    return true;
}


void BFS(int vertex){
    int i,j;
    //marking the node as visited
    visited[vertex] = 1;
    cout << vertex << " ";
    // loading the childs into the queue
    for(i=1;i<=V;i++){
        if(G[vertex][i]==1 && visited[i]!=1 && presentinqueue(i)){
            push(i);
            //visited[i]=1;
        }
    }
    j=pop();
    if (j>0){
        BFS(j);
    }
    else{
        return;
    }
}



int main(){
    cin >> V >> E;

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

    BFS(1);



}