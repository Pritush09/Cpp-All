#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int INF = 1e1;
int G[N][N],V,E;

int main()
{
	cin >> V >> E;

	for (int i=1 ; i<V+1 ; i++){
        for(int j=1 ; j<V+1 ; j++){
            if (i==j) G[i][j]=0;
            else G[i][j]=INF;
        }
        cout << "\n";
    }

    for(int i=1 ; i<= E ; i++){
        int v1 , v2 , v3;
        cin >> v1 >> v2 >> v3;
        G[v1][v2]=v3;
        // if it is an undirected graph then this also needed to be there below line
        //G[v2][v1]=1;
    }

    // printing the graph G
    for (int i=1 ; i<V+1 ; i++){
        for(int j=1 ; j<V+1 ; j++){
            cout << G[i][j];
        }
        cout << "\n";
    }

    cout << "\n\n";


    for(int k=1;k<=V;k++){
    	for(int i=1;i<=V;i++){
    		for(int j=1;j<=V;j++){
    			G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
    		}
    	}
    }

    for(int i=1;i<=V;i++){
    	for(int j=1;j<=V;j++){
    		if (G[i][j]==INF) cout << "I";
    		else cout << G[i][j];
   		}
   		cout << "\n";
    }


	return 0;
}

