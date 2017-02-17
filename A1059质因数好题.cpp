//A1059

//先打一张素数的表，因为质因数先是素数。然后遍历过去
//

#include <cstdio>

const int maxn = 100010;

bool isPrime(int n){
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0) return false;
	}
	return true;
}

int prime[maxn], num = 0;
void findPrime(){
	for (int i = 2; i < maxn; i++){
		if (isPrime(i)){
			prime[num++] = i;
		}
	}
}

struct factor{
	int x;
	int num;
}fac[10];

int main(){
	int n;
	scanf("%d", &n);
	findPrime();

	printf("%d=", n);//先输出，不然后面就变了
	int fNum = 0;
	for (int i = 0; i < num; i++){

		if (n % prime[i] == 0){
			fac[fNum].x = prime[i];
			fac[fNum].num = 0;
			while (n % prime[i] == 0){
				n /= prime[i];
				fac[fNum].num++;
			}
			fNum++;
		}
		if (n == 1)
			break;
	}

	for (int i = 0; i < fNum; i++){
		printf("%d", fac[i].x);
		if (fac[i].num != 1){
			printf("^%d", fac[i].num);
		}
		if (i != fNum - 1)
			printf("*");
	}
	

	return 0;
}