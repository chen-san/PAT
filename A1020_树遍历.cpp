#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 50;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

int post[maxn], in[maxn];

node* create(int postL, int postR, int inL, int inR){
	if (postL > postR)
		return NULL;

	node* root = new node;
	root->data = post[postR];

	int k;
	for (k = inL; k <= inR; k++){
		if (in[k] == post[postR])
			break;
	}

	int numL = k - inL;
	root->lchild = create(postL , postL + numL - 1, inL, k - 1);
	root->rchild = create(postL + numL, postR - 1, k + 1, inR);

	return root;

}


int num = 0, n;
void BFS(node* root){
	queue<node*> que;
	que.push(root);

	while (!que.empty()){
		node* tmp = que.front();
		que.pop();
		printf("%d", tmp->data);
		num++;
		if (num < n) printf(" ");
		if (tmp->lchild != NULL) que.push(tmp->lchild);
		if (tmp->rchild != NULL) que.push(tmp->rchild);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);

	node* root = create(0, n - 1, 0, n - 1);

	BFS(root);

	return 0;
}