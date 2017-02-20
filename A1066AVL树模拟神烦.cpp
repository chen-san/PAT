//A1066

//avl��ģ���⣬�����������⣬̫��

/*����һ����㣺
���ĸ߶����Ե����ϸ���
����ƽ���������Ե����ϸ���
������תҲ���Ե����ϣ�
���������������ʧ�⣬ֻҪ��������������ʧ��������ˣ�

�Ǹ����ʧ��ֻ���������
ƽ������Ϊ2����������ƽ������Ϊ1��L�ͣ������ͺ����ֺ��������˻���������ֱ�Ӽ���ת�ã�������
ƽ������Ϊ2����������ƽ������Ϊ-1����������������ת��󣬾ͱ�������һ���ٱ�������
ƽ������Ϊ-2����������ƽ������Ϊ-1������
ƽ������Ϊ2����������ƽ������Ϊ1�� ��������������������*/

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


//�����µ����ڵ�
node* newNode(int x){
	node* tNode = new node;
	tNode->data = x;
	tNode->height = 1;//Ҷ�ӽ��߶�Ϊ1
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
		//����֮���ڵݹ顾���ء���;�У���������
		updateHeight(root);
		//ÿ�ε����߸��£���Ϊ�˵ݹ��ȥʱ����һ�Ρ��ļ���ƽ������׼��
		//����ƽ������
		if (getBalanceFactor(root) == 2){
			if (getBalanceFactor(root->lchild) == 1)//����
				root = R(root);//��һ�����ܹؼ���
			else if (getBalanceFactor(root->lchild) == -1){//�������������ٱ�������
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

//���½ڵ�߶�
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}


//֮���Բ�ֱ����node->height���������ߣ��Ƿ�ֹnode == NULL���
int getHeight(node* root){
	if (root == NULL) return 0;
	else return root->height;
}


node* L(node* root){//�������ظı��ĸ��ڵ�
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);//���½ڵ�߶ȣ��ⲻ����
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