#include<bits/stdc++.h>
using namespace std;
#define MAX 900;
const int N = 1e2;
int V,E;
int G[N][N];
int visited[N];
int Q[N];
int Dist[N];

void DIJ(int n,int v){
	int w,i,c,min,u;
	for(i=1;i<=n;i++){
		visited[i] = 0;
		Dist[i] = G[v][i];
	}
	Dist[v] = 0;// khudka khudke sangh distance 0 kiye 
	visited[v] = 1;
	for(c=2;c<=n;c++){
		min = MAX;
		for(w=1;w<=n;w++){
			if(Dist[w] < min && visited[w] != 1){
				min = Dist[w];
				u = w;
			}
		}
	
		visited[u] = 1;
		for(w=1;w<=n;w++){
			if(Dist[u] + G[u][w] < Dist[w] && visited[w] != 1){
				Dist[w] = Dist[u] + G[u][w];
			}
		}
	}
}




main(){
    cin >> V >> E;

    for(int i=1; i<=V ; i++){
        for(int j=1; j<=V ; j++){
            G[i][j]=0;
        }
    }

    for(int i=1 ; i<= E ; i++){
        int v1 , v2 , v3;
        cin >> v1 >> v2 >> v3;
        G[v1][v2]=v3;
        //below not needed as the directed graph
        // if it is an undirected graph then this also needed to be there below line
        //G[v2][v1]=v3;
    }

    // printing the graph G
    for (int i=1 ; i<V+1 ; i++){
        for(int j=1 ; j<V+1 ; j++){
            cout << G[i][j];
            if(G[i][j] == 0)
				G[i][j] = MAX;

        }
        cout << "\n";
    }


    cout << "\n\n";

    DIJ(V,1);

    cout << "The shortest path: \n";
	for(int i=1;i<=V;i++){
		if(i != 1)
			printf("%d -> %d cost=%d ",1,i,Dist[i]);
	}


}