//B1032

//用一个数组school[maxn]存每个学校总分，初值设为0；
//然后遍历一遍得到最高学校iD和总分

#include<cstdio>

const int maxn = 100010;

int school[maxn] = { 0 };

int main(){
	int n;
	scanf("%d", &n);

	int schID, score;
	for (int i = 0; i < n; i++){
		scanf("%d %d", &schID, &score);
		school[schID] += score;
	}

	int maxID, maxScore = -1;
	for (int i = 1; i <= n; i++){
		if (school[i] > maxScore){
			maxID = i;
			maxScore = school[i];
		}
	}

	printf("%d %d", maxID, maxScore);

	return 0;
}