//A1076

//BFS，同时掌握层数的用法
//同时，题目给的是关注的人，而不是粉丝，要转化一下

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int data;
	int layer;
};

vector<node> follower[1010];
int vis[1010];
int maxL;

int cnt;
int BFS(int u){
	queue<node> q;
	node s;
	s.data = u;
	s.layer = 0;
	q.push(s);
	vis[u] = true;
	while(!q.empty()){
		node now = q.front();
		q.pop();
		for(int i = 0; i < follower[now.data].size(); i++){
			node j = follower[now.data][i];
			j.layer = now.layer + 1;
			if(!vis[j.data] && j.layer <= maxL){
				q.push(j);
				vis[j.data] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	int n;
	scanf("%d%d", &n, &maxL);
	int m, id;
	node user;
	for(int i = 1; i <= n; i++){
		user.data = i;
		scanf("%d", &m);
		for(int j = 0; j < m; j++){
			scanf("%d", &id);
			follower[id].push_back(user);
		}
	}
	
	int k;
	scanf("%d", &k);
	int query;
	for(int i = 0; i < k; i++){
		scanf("%d",&query);
		fill(vis, vis + 1010, false);//每次都初始化
		cnt = 0;
		printf("%d\n",BFS(query)); 
	} 
	return 0;
}  
