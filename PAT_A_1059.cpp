#include <cstdio>
#include <cmath>

bool isPrime(int x){
	if (x <= 1) return false;
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0) return false;
	}
	return true;
}

int prime[100010], idex = 0;

void findPrime(int x){
	for (int i = 1; i<100010; i++){
		if (isPrime(i) == true)
			prime[idex++] = i;
	}
}

struct Facter{
	int x, cnt;
}fac[100];

int main(){
	int n;
	scanf("%d", &n);

	findPrime(n);
	if (n == 1) printf("1=1");
	else{
		printf("%d=", n);
		int m = 0;

		for (int i = 0; i < idex && prime[i] <= n; i++){
			if (n % prime[i] == 0){

				fac[m].x = prime[i];
				fac[m].cnt = 0;
				while (n % prime[i] == 0){
					fac[m].cnt++;
					n /= prime[i];
				}
				m++;
			}
			if (n == 1) break;

		}

		if (n != 1){
			fac[m].x = n;
			fac[m++].cnt = 1;
		}

		for (int i = 0; i < m; i++){
			printf("%d", fac[i].x);
			if (fac[i].cnt > 1)
				printf("^%d", fac[i].cnt);
			if (i != m - 1)
				printf("*");
		}

	}
	return 0;
}

