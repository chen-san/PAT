#include <cstdio>
#include <cmath>

int prime[1000000];

bool isPrime(int n){
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

void findPrime(int n){
	int idex = 1;
	for (int i = 1; idex <= n; i++){
		if (isPrime(i) == true){
			prime[idex++] = i;
		}
	}
}
int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	findPrime(n);

	for (int i = m; i <= n; i++){
		printf("%d", prime[i]);
		if (i == n || (i-m + 1) % 10 == 0)
			printf("\n");
		else
			printf(" ");
	}
	return 0;
}