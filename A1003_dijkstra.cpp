#include <iostream>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

int d[maxn], w[maxn], num[maxn];
int vis[maxn] = { false };
int G[maxn][maxn];
int weight[maxn];

int n, m, st, ed;

void dijkstra(int x){
	fill(d, d + maxn, INF);
	d[x] = 0;
	w[x] = weight[x];
	num[x] = 1;

	for (int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++){
			if (vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}

		if (u == -1) return;

		vis[u] = true;
		for (int v = 0; v < n; v++){
			if (vis[v] == false && G[u][v] != INF){
				if (d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if (d[u] + G[u][v] == d[v]){
					if (w[u] + weight[v] > w[v])
						w[v] = w[u] + weight[v];
					num[v] += num[u];
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m >> st >> ed;
	for (int i = 0; i < n; i++){
		cin >> weight[i];
	}

	fill(G[0], G[0] + maxn * maxn, INF);
	int x, y, z;
	for (int i = 0; i < m; i++){
		cin >> x >> y >> z;
		G[x][y] = G[y][x] = z;
	}

	dijkstra(st);
	cout << num[ed] << " " << w[ed];

	return 0;
}