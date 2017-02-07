//A1009

//一个数组存第一个多项式，一个数组存结果

#include <cstdio>
int main(){
	double a[1001] = { 0 };
	double ans[2001] = {0};
	double k;
	int e;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%lf", &e, &k);
		a[e] = k;
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%lf", &e, &k);
		for (int j = 0; j < 1001; j++){
			ans[j + e] += a[j] * k;
		}
	}

	int count = 0;
	for (int i = 0; i < 2001; i++){
		if (ans[i] != 0) count++;
	}

	printf("%d", count);

	for (int i = 2000; i >= 0; i--){
		if (ans[i] != 0) printf(" %d %.1f", i, ans[i]);//这样的写法，其实也照顾到了count = 0的情况
	}

	return 0;
}