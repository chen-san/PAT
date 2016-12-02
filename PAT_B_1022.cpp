#include <cstdio>

int main(){
	int a, b, d;
	scanf("%d%d%d",&a, &b, &d);

	int sum = a + b;
	int ans[31];

	int cnt = 0;
	do{
		ans[cnt++] = sum % d;
		sum /= d;
	} while (sum != 0);

	for (int i = cnt - 1; i >= 0; i--)
		printf("%d", ans[i]);

	return 0;
}