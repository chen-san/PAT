//B1032

//��һ������school[maxn]��ÿ��ѧУ�ܷ֣���ֵ��Ϊ0��
//Ȼ�����һ��õ����ѧУiD���ܷ�

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