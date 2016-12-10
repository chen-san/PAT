#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1010;

int n, l;

struct node{
	int id;
	int layer;
};

vector<node> followed[maxn];
bool isVis[maxn] = { false };

int BFS(int x){
	int sum = 0;
	queue<node> que;
	node tmp;
	tmp.id = x;
	tmp.layer = 0;
	isVis[x] = true; //²»ÒªÍüÁË
	que.push(tmp);

	while (!que.empty()){
		node front = que.front();
		que.pop();

		for (int i = 0; i < followed[front.id].size(); i++){
			node next = followed[front.id][i];
			next.layer = front.layer + 1;
			if (isVis[next.id] == false && next.layer <= l){
				que.push(next);
				isVis[next.id] = true;
				sum++;
			}

		}
	}
	return sum;
}

int main(){
	cin >> n >> l;

	node tmp;
	for (int i = 1; i <= n; i++){
		int m;
		cin >> m;
		for (int j = 0; j < m; j++){
			int x;
			cin >> x;
			tmp.id = i;
			followed[x].push_back(tmp);
		}
	}

	int x;
	cin >> x;
	for (int i = 0; i < x; i++){
		int y;
		cin >> y;
		for (int j = 1; j <= n; j++){
			isVis[j] = false;
		}

		cout << BFS(y) << endl;
	}
	


	return 0;
}