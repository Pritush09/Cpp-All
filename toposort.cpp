#include<bits/stdc++.h>
using namespace std;

const int N=1e1;
int V,E;
int visited[N];
int G[N][N];
int stck[N];
int q=-1;

void push(int n){
	if (q==N){
		cout << "overflow";
	}
	else{
		q++;
		stck[q]=n;
	}
}

int pop(){
	int re;
	if(q==-1){
		cout << "Underflow";
		return -1;
	}else{
		re=stck[q];
		q--;
		return re;
	}
}


void DFS(int vertex){
	int i;
	visited[vertex]=1;
	for(i=1;i<=V;i++){
		if(G[vertex][i]==1 && visited[i]!=1){

			DFS(i);
		}
	}

	push(vertex);
	return;
}


int main()
{
	cin >> V >> E;
	for (int i = 1; i <= E; i++)
	{
		int v1,v2;
		cin >> v1 >> v2;
		G[v1][v2]=1;
		G[v2][v1]=1;
	}

	for(int i = 1;i<=V;i++){
		for (int j = 1; i<=V ; i++){
			cout << G[i][j];
		}
		cout << "\n";
	}

	return 0;
}
