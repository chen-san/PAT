//A1066

//avl树模拟题，最讨厌这种题，太烦

/*插入一个结点：
树的高度是自底向上更新
树的平衡因子是自底向上更新
树的旋转也是自底向上，
而且如果插入引起失衡，只要调整最靠近插入结点的失衡结点就行了，

那个结点失衡只有四种情况
平衡因子为2，且左子树平衡因子为1，L型（这种型号区分很容易让人混淆，还是直接记旋转好），右旋
平衡因子为2，且左子树平衡因子为-1，左子树左旋，旋转完后，就变成了情况一，再本身右旋
平衡因子为-2，且左子树平衡因子为-1，右旋
平衡因子为2，且左子树平衡因子为1， 右子树右旋，本身左旋*/

#include <cstdio>
#include <algorithm>
using namespace std;


struct node{
	int data;
	int height;
	node *lchild, *rchild;
};

int getHeight(node* root);
void updateHeight(node* root);
int getBalanceFactor(node* root);
node* L(node* root);
node* R(node* root);
void insert(node* &root, int x);


//生成新的树节点
node* newNode(int x){
	node* tNode = new node;
	tNode->data = x;
	tNode->height = 1;//叶子结点高度为1
	tNode->lchild = NULL;
	tNode->rchild = NULL;
	return tNode;
}

void insert(node* &root, int x){
	if (root == NULL){
		root = newNode(x);
		return;
	}
	if (x < root->data){
		insert(root->lchild, x);
		//插入之后，在递归【返回】的途中，更新树高
		updateHeight(root);
		//每次的树高更新，是为了递归回去时【下一次】的计算平衡因子准备
		//计算平衡因子
		if (getBalanceFactor(root) == 2){
			if (getBalanceFactor(root->lchild) == 1)//右旋
				root = R(root);//这一步理解很关键！
			else if (getBalanceFactor(root->lchild) == -1){//左子树左旋，再本身右旋
				root->lchild = L(root->lchild);
				root = R(root);
			}
		}
	}
	else{
		insert(root->rchild, x);
		updateHeight(root);
		if (getBalanceFactor(root) == -2){
			if (getBalanceFactor(root->rchild) == -1)
				root = L(root);
			else if (getBalanceFactor(root->rchild) == 1){
				root->rchild = R(root->rchild);
				root = L(root);
			}
		}
	}

}

int getBalanceFactor(node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}

//更新节点高度
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}


//之所以不直接用node->height来访问树高，是防止node == NULL情况
int getHeight(node* root){
	if (root == NULL) return 0;
	else return root->height;
}


node* L(node* root){//左旋返回改变后的根节点
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);//更新节点高度，这不能忘
	return temp;
}

node* R(node* root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	return temp;
}

int main(){
	int n, x;
	scanf("%d", &n);
	node* root = NULL;
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		insert(root, x);
	}

	printf("%d", root->data);
	return 0;
}