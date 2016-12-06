#include<cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
struct NODE{
	int address; 
	int data;
	int next;
	bool flag;
}node[maxn];

bool cmp(NODE n1, NODE n2){
	if (n1.flag == false || n2.flag == false)
		return n1.flag > n2.flag;
	else
		return n1.data < n2.data;
}
int main(){

	for (int i = 0; i < maxn; i++){
		node[i].flag = false;
	}
	int n, begin;
	scanf("%d%d", &n, &begin);

	int address;
	for (int i = 0; i < n; i++){
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}

	int cnt = 0;
	for (int i = begin; i != -1; i = node[i].next){
		node[i].flag = true;
		cnt++;
	}

	if (cnt == 0)
		printf("0 -1\n");

	else{
		sort(node, node + maxn, cmp);

		printf("%d %05d\n", cnt, node[0].address);

		for (int i = 0; i < cnt; i++){
			if (i != cnt - 1)
				printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
			else
				printf("%05d %d -1\n", node[i].address, node[i].data);
		}
	}

	return 0;
}