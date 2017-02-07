//A1002

//多项式的相加，用一个数组存就行了。第一次读入，第二次直接相加就行了

//得设一个计数的count，而且还只能最后输出之前遍历一遍，得到count。麻烦。

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
			printf(" %d %.1f", i, a[i]);//直接这样就行了，就不用判断count--了
		}
	}

	return 0;
}