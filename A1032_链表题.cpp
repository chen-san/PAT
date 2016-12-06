#include<cstdio>

const int maxn = 100010;

struct NODE{
	char data;
	int next;
	bool flag;
}node[maxn];

int main(){
	int a1, a2, n;
	scanf("%d%d%d", &a1, &a2, &n);

	int address, data, next;
	for (int i = 0; i < n; i++){
		scanf("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
		node[address].flag = false;
	}

	for (int i = a1; i != -1; i = node[i].next){
		node[i].flag = true;
	}

	int i;
	for (i = a2; i != -1; i = node[i].next){
		if (node[i].flag == true){
			break;
		}
	}

	if (i != -1)
		printf("%05d\n", i);
	else
		printf("-1\n");
	


	return 0;
}