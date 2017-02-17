//B1007

//ËØÊýÌâ

#include <cstdio>

bool isPrime(int n){
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0) return false;
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);

	int count = 0;
	for (int i = 3; i + 2 <= n; i += 2){//ÐÞ¼ô
		if (isPrime(i) && isPrime(i + 2))
			count++;
	}

	printf("%d", count);

	return 0;
}