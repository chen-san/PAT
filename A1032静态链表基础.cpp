//A1032

//静态链表题，
//先遍历第一个链表，节点的结构里面设一个isVisitid,遍历过设为true，再遍历第二个链表，遇到true就是共同节点了

#include <cstdio>

struct Node{
	char data;
	int next;
	bool isVis;
}node[100010];//地址一共五位

int main(){
	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);
	
	int address, next;
	char data;

	for (int i = 0; i < n; i++){
		scanf("%d %c %d", &address, &data, &next);//注意加空格
		node[address].data = data;
		node[address].next = next;
		node[address].isVis = false;
	}

	int p = s1;
	while (p != -1){
		node[p].isVis = true;
		p = node[p].next;
	}

	p = s2;
	while (p != -1){
		if (node[p].isVis == true) break;
		p = node[p].next;
	}

	if (p == -1)
		printf("-1");
	else
		printf("%05d", p);

	return 0;
}