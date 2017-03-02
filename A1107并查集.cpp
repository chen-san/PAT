//并查集

//用一个course[]数组做哈希表来存喜欢那门课的人
//如果喜欢的那门课已经有人了，就union

//再用一个根数组来存网络的个数
//排序输出 


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
	//初始化 
	for(int i = 1; i <= n; i++){
		father[i] = i;
	} 
	int k, h;
	for(int i = 1; i <= n; i++){
		scanf("%d:", &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &h);
			if(course[h] == 0){//还没人喜欢 
				course[h] = i;	
			}
			else{
				unionFather(i, course[h]);//把两个人连起来 
			}
		}
	}
	for(int i = 1; i <= n; i++){
		isRoot[findFather(i)]++;//一共几个网络，每个网络计数 ， 每一个根节点是每一个网络的标识 
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
