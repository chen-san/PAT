//A1032
/*思路：存到一个结构数组当中，第一个单词先捋一遍，结构体中设个变量isVis，第二个单词再捋，捋到isVis为true，就是那个单词
有一个问题，题目好像默认只要出现一个共同单词，后面就全是一样的。嗯……就按它说的来吧*/

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

	//捋第一个单词
	int p = s1;
	while (p != -1){
		node[p].isVis = true;
		p = node[p].next;
	}

	//第二个单词
	int q = s2;
	while (q != -1){
		if (node[q].isVis == true) break;
		q = node[q].next;
	}

	if (q != -1)
		printf("%05d", q);//注意格式！！
	else
		printf("-1");

	return 0;
}