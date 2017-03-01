//A1020
//树的遍历和重建，基础题

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 40;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

int post[maxn];
int in[maxn];
int n;

node* creat(int postL, int postR, int inL, int inR){
	if (postL > postR) return NULL;//后序序列长度小于0，就返回

	node* root = new node;
	root->data = post[postR];//别忘了数据域
	int k;
	for (k = inL; k <= inR; k++){
		if (in[k] == post[postR]) break;
	}
	int numL = k - inL;
	root->lchild = creat(postL, postL + numL - 1, inL, k - 1);
	root->rchild = creat(postL + numL, postR - 1, k + 1, inR);
	return root;//不能少，而且位置在这里
}

int num = 0;
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while (!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if (num < n) printf(" ");//控制格式
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL) q.push(now->rchild);
	}

}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", post + i);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", in + i);
	}
	node* root = creat(0, n - 1, 0, n - 1);
	BFS(root);

	return 0;
}