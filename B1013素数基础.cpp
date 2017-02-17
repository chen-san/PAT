//B1013

//素数题,先打一张素数表出来

#include <cstdio>

const int maxn = 1000001;

bool isPrime(int n){
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0) return false;
	}
	return true;
}

int prime[maxn], num = 0;//用来存素数表

void findPrime(int n){
	for (int i = 2; i < maxn; i++){
		if (isPrime(i)){
			prime[num++] = i;
			if (num >= n) break;
		}
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	findPrime(m);

	int count = 0;
	for (int i = n; i <= m; i++){
		printf("%d", prime[i - 1]);
		count++;
		if (count % 10 == 0 || count == m - n + 1){
			printf("\n");
		}
		else
			printf(" ");
	}

	return 0;
}