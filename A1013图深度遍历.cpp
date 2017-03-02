//A1013

//图的遍历，删掉一个节点之后，分成了n个小块，那就要加n - 1 条路

#include <cstdio>
#include <vector>
using namespace std;

vector <int> G[1111];
bool vis[1111];
int delNode;

void DFS(int u){
	vis[u] = true;
	for(int i = 0; i < G[u].size(); i++){
		if(G[u][i] != delNode && !vis[G[u][i]])
			DFS(G[u][i]);
	}
} 

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	 
	for(int i = 0; i < k; i++){
		scanf("%d", &delNode);
		fill(vis, vis + 1111, false);//每次都要初始化 
		int block = 0; 
		for(int i = 1; i <= n; i++){
			if(i != delNode && !vis[i]){
				DFS(i);
				block++;
			}
		}
		printf("%d\n", block - 1);
	}
	return 0;
}
