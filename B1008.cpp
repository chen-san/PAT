//B1008

//难点在于如何打空格？哈哈

#include <cstdio>

int main(){
	int a[110];
	int n, m, count = 0;

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	m = m % n;

	for (int i = n - m; i < n; i++){
		printf("%d", a[i]);
		count++;
		if (count != n) printf(" ");
	}

	for (int i = 0; i < n - m; i++){
		printf("%d", a[i]);
		count++;
		if (count != n) printf(" ");
	}


	return 0;
}