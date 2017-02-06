//A1052

/*题目分两步，先把链表提取出来，再把链表中data按从小到大排列
这两步可以用一个sort解决，用一个两级排序，是否有遍历排序一下，再用data大小排序一下*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

struct Node{
	int address;//原地址
	int data;
	int next;
	bool isVis = false;
}node[maxn];

bool cmp(Node a, Node b){
	if (a.isVis == false || b.isVis == false)
		return a.isVis > b.isVis;
	else
		return a.data < b.data;
}

int main(){
	int s, n;
	scanf("%d%d", &n, &s);
	
	int address, data, next;
	for (int i = 0; i < n; i++){
		scanf("%d%d%d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}

	int cnt = 0;
	int p = s;
	while (p != -1){
		cnt++;
		node[p].isVis = true;
		p = node[p].next;
	}

	if (cnt == 0)
		printf("0 -1");//考虑极端条件
	else{
		sort(node, node + maxn, cmp);
		printf("%d %05d\n", cnt, node[0].address);
		for (int i = 0; i < cnt; i++){
			if (i != cnt - 1){
				printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
			}
			else
				printf("%05d %d -1", node[i].address, node[i].data);
		}
	}

	return 0;
}
