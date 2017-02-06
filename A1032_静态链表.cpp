//A1032
/*˼·���浽һ���ṹ���鵱�У���һ����������һ�飬�ṹ�����������isVis���ڶ����������ۣ��۵�isVisΪtrue�������Ǹ�����
��һ�����⣬��Ŀ����Ĭ��ֻҪ����һ����ͬ���ʣ������ȫ��һ���ġ��š����Ͱ���˵������*/

#include <cstdio>
const int maxn = 100010;

struct Node{
	char data;
	int next;
	bool isVis = false;
};

struct Node node[maxn];

int main(){
	int s1, s2, n;
	scanf("%d %d %d", &s1, &s2, &n);
	
	int address, next;
	char data;
	for (int i = 0; i < n; i++){
		scanf("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
	}

	//�۵�һ������
	int p = s1;
	while (p != -1){
		node[p].isVis = true;
		p = node[p].next;
	}

	//�ڶ�������
	int q = s2;
	while (q != -1){
		if (node[q].isVis == true) break;
		q = node[q].next;
	}

	if (q != -1)
		printf("%05d", q);//ע���ʽ����
	else
		printf("-1");

	return 0;
}