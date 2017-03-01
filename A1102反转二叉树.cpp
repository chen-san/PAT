//A1102

//反转二叉树

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110;
int n;

struct Node{
	int lchild;
	int rchild;//确切的来说没有数据域，
}node[maxn];

bool notRoot[maxn] = { false }; //静态二叉树找根的话，就是一个个遍历过去，不是任何孩子子节点的就是根节点。

int findRoot(){
	for (int i = 0; i < maxn; i++){
		if (!notRoot[i]) return i;
	}
}

int change(char c){
	if (c == '-') return -1;
	else return c - '0';
}

void postOrder(int root){//反转二叉树代码
	if (root == -1) return;
	postOrder(node[root].lchild);
	postOrder(node[root].rchild);
	swap(node[root].lchild, node[root].rchild);
}

int num = 0;//控制输出格式

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
		getchar();//吸收掉换行
		scanf("%c %c", &lc, &rc);
		l = change(lc);
		r = change(rc);
		notRoot[l] = true, notRoot[r] = true;
		node[i].lchild = l, node[i].rchild = r;
	}
	int root = findRoot();
	postOrder(root);
	layerOrder(root);
	num = 0; //不能忘
	inOrder(root);

	return 0;
}