//A1043

//把先序遍历的顺序，作为插入顺序建树
//在输出真正的先序遍历顺序，与插入顺序比较

#include<cstdio>
#include<vector>
using namespace std;

vector <int> pre, preM, post, postM, given;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* newNode(int x){
	node* tNode = new node;
	tNode->lchild = NULL;
	tNode->rchild = NULL;
	tNode->data = x;
	return tNode;
}

void insert(node* &root, int x){
	if(root == NULL){
		root = newNode(x);
		return;//一定要返回，不然会出错 
	}
	if(x < root->data) insert(root->lchild, x);
	else insert(root->rchild, x);
}

void preOrder(node* root){
	if(root == NULL) return;
	pre.push_back(root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void preOrderM(node* root){
	if(root == NULL) return;
	preM.push_back(root->data);
	preOrderM(root->rchild);//先遍历右子树 
	preOrderM(root->lchild);
}

void postOrder(node* root){
	if(root == NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	post.push_back(root->data);
}

void postOrderM(node* root){
	if(root == NULL) return;
	postOrderM(root->rchild);
	postOrderM(root->lchild);
	postM.push_back(root->data);
}

int main(){
	int n;
	scanf("%d", &n);
	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		given.push_back(x);
	}
	node* root = NULL;
	for(int i = 0; i < n; i++){
		insert(root, given[i]);
	}

	preOrder(root);
	preOrderM(root);
	if(pre == given){
		printf("YES\n");
		postOrder(root);
		for(int i = 0; i< post.size(); i++){
			printf("%d", post[i]);
			if(i != post.size() - 1)
				printf(" ");
		}
	}
	else if(preM == given){
		printf("YES\n");
		postOrderM(root);
		for(int i = 0; i< postM.size(); i++){
			printf("%d", postM[i]);
			if(i != postM.size() - 1)
				printf(" ");
		}
	}
	else {
		printf("NO");
	}
	return 0;
} 
