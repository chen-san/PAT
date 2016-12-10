#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
	int weight;
	vector<int> child;
}Node[110];

bool cmp(int a, int b){
	return Node[a].weight > Node[b].weight;
}

void DFS(int index, int nowNode, int nowSum){
	if (nowSum > s) return;
	if (nowSum == s){
		if (Node[index].child.size() != 0) //非叶节点
			return;
		else{
			for (int i = 0; i < nowNode; i++){
				printf("%d", Node[path[i]].weight);
				if (i < nowNode - 1)
					printf(" ");
			}
			return;
		}
	}

	for (int i = 0; i < Node[index].child.size(); i++){
		int child = Node[index].child[i];
		path[nowNode] = child;      //要好好理解这一步
		DFS(child, nowNode + 1, nowSum + Node[child].weight);
	}

}


int n, m, s;

int path[110];

int main(){
	scanf("%d%d%d", &n, &m, &s);

	for (int i = 0; i < n; i++){
		scanf("%d", &Node[i].weight);
	}

	int id,k, child;

	for (int i = 0; i < m; i++){
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++){
			scanf("%d", &child);
			Node[id].child.push_back(child);
		}

		sort(Node[id].child.begin(), Node[id].child.end(), cmp);

	}

	path[0] = 0;

	DFS(0, 1, Node[0].weight);
	return 0;
}