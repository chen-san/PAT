//A1032

//��̬�����⣬
//�ȱ�����һ�������ڵ�Ľṹ������һ��isVisitid,��������Ϊtrue���ٱ����ڶ�����������true���ǹ�ͬ�ڵ���

#include <cstdio>

struct Node{
	char data;
	int next;
	bool isVis;
}node[100010];//��ַһ����λ

int main(){
	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);
	
	int address, next;
	char data;

	for (int i = 0; i < n; i++){
		scanf("%d %c %d", &address, &data, &next);//ע��ӿո�
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