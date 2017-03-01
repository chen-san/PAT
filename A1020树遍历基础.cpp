//A1020
//���ı������ؽ���������

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
	if (postL > postR) return NULL;//�������г���С��0���ͷ���

	node* root = new node;
	root->data = post[postR];//������������
	int k;
	for (k = inL; k <= inR; k++){
		if (in[k] == post[postR]) break;
	}
	int numL = k - inL;
	root->lchild = creat(postL, postL + numL - 1, inL, k - 1);
	root->rchild = creat(postL + numL, postR - 1, k + 1, inR);
	return root;//�����٣�����λ��������
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
		if (num < n) printf(" ");//���Ƹ�ʽ
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