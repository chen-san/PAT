//A1002

//����ʽ����ӣ���һ�����������ˡ���һ�ζ��룬�ڶ���ֱ����Ӿ�����

//����һ��������count�����һ�ֻ��������֮ǰ����һ�飬�õ�count���鷳��

#include <cstdio>

const int maxn = 1010;
int main(){
	double a[maxn] = { 0 };
	int n;
	scanf("%d", &n);

	double k;
	int e;
	for (int i = 0; i < n; i++){
		scanf("%d%lf", &e, &k);
		a[e] = k;
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%lf", &e, &k);
		a[e] += k;
	}

	int count = 0;
	for (int i = 0; i < 1001; i++){
		if (a[i] != 0)
			count++;
	}

	printf("%d", count);
	for (int i = 1000; i >= 0; i--){
		if (a[i] != 0){
			printf(" %d %.1f", i, a[i]);//ֱ�����������ˣ��Ͳ����ж�count--��
		}
	}

	return 0;
}