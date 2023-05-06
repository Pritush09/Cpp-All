#include<bits/stdc++.h>
using namespace std;
const int N=1e2;
const int Max = 999;
int V , E, G[N][N];
int visited[N];


void Prims(){
	int i,j,u,v,min,mincost=0,ne=1;
	visited[1]=1;
	while(ne<V){
		for(i=1,min=999;i<=V;i++){
			for(j=1;j<=V;j++){
				if (G[i][j]<min){
					if(visited[i]==0){
						continue;
					}else{
						min=G[i][j];
						u=i;
						v=j;
					}
				}

			}
		}
		if(visited[u]==0 || visited[v]==0){
			printf("%d Edge(%d,%d)=%d \n",ne++,u,v,min);
			mincost=mincost+min;
			visited[v]=1;
		}
		G[u][v]=G[v][u]=999;

	}
	printf("The cost : %d \n",mincost);

}

int main()
{
	cin >> V >> E;

    for(int i=1 ; i<= E ; i++){
        int v1 , v2 , v3;
        cin >> v1 >> v2 >> v3;
        G[v1][v2]=v3;
        // if it is an undirected graph then this also needed to be there below line
        G[v2][v1]=v3;
    }

    // printing the graph G
    for (int i=1 ; i<V+1 ; i++){
        for(int j=1 ; j<V+1 ; j++){
            cout << G[i][j] << " ";
            if(G[i][j]==0){
            	G[i][j]=Max;
            }
        }
        cout << "\n";
    }
    Prims();
    
}