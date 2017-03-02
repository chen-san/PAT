//���鼯

//��һ��course[]��������ϣ������ϲ�����ſε���
//���ϲ�������ſ��Ѿ������ˣ���union

//����һ����������������ĸ���
//������� 


#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1010;
int father[maxn];
int course[maxn] = {0};
int isRoot[maxn] = {0};

int findFather(int x){
	if(x == father[x]) return x;
	else findFather(father[x]);
} 

void unionFather(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB)
		father[faA] = faB;
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n;
	scanf("%d", &n);
	//��ʼ�� 
	for(int i = 1; i <= n; i++){
		father[i] = i;
	} 
	int k, h;
	for(int i = 1; i <= n; i++){
		scanf("%d:", &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &h);
			if(course[h] == 0){//��û��ϲ�� 
				course[h] = i;	
			}
			else{
				unionFather(i, course[h]);//�������������� 
			}
		}
	}
	for(int i = 1; i <= n; i++){
		isRoot[findFather(i)]++;//һ���������磬ÿ��������� �� ÿһ�����ڵ���ÿһ������ı�ʶ 
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(isRoot[i]) cnt++;
	}
	
	sort(isRoot + 1, isRoot + n, cmp);
	
	printf("%d\n", cnt);
	for(int i = 1; i < cnt + 1; i++){
		printf("%d", isRoot[i]);
		if(i != cnt)
			printf(" ");
	}
	
	return 0;	
}
