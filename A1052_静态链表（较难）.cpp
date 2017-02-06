//A1052

/*��Ŀ���������Ȱ�������ȡ�������ٰ�������data����С��������
������������һ��sort�������һ�����������Ƿ��б�������һ�£�����data��С����һ��*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

struct Node{
	int address;//ԭ��ַ
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
		printf("0 -1");//���Ǽ�������
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
