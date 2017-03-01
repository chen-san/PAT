//A1102

//��ת������

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110;
int n;

struct Node{
	int lchild;
	int rchild;//ȷ�е���˵û��������
}node[maxn];

bool notRoot[maxn] = { false }; //��̬�������Ҹ��Ļ�������һ����������ȥ�������κκ����ӽڵ�ľ��Ǹ��ڵ㡣

int findRoot(){
	for (int i = 0; i < maxn; i++){
		if (!notRoot[i]) return i;
	}
}

int change(char c){
	if (c == '-') return -1;
	else return c - '0';
}

void postOrder(int root){//��ת����������
	if (root == -1) return;
	postOrder(node[root].lchild);
	postOrder(node[root].rchild);
	swap(node[root].lchild, node[root].rchild);
}

int num = 0;//���������ʽ

void print(int x){
	printf("%d", x);
	num++;
	if (num == n) printf("\n");
	else printf(" ");
}

void inOrder(int root){
	if (root == -1) return;
	inOrder(node[root].lchild);
	print(root);
	inOrder(node[root].rchild);
}

void layerOrder(int root){
	queue<int> q;
	q.push(root);
	while (!q.empty()){
		int now = q.front();
		q.pop();
		print(now);
		if (node[now].lchild != -1) q.push(node[now].lchild);
		if (node[now].rchild != -1) q.push(node[now].rchild);
	}
}

int main(){
	char lc, rc;
	int l, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		getchar();//���յ�����
		scanf("%c %c", &lc, &rc);
		l = change(lc);
		r = change(rc);
		notRoot[l] = true, notRoot[r] = true;
		node[i].lchild = l, node[i].rchild = r;
	}
	int root = findRoot();
	postOrder(root);
	layerOrder(root);
	num = 0; //������
	inOrder(root);

	return 0;
}