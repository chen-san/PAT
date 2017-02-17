//A1069

//题目其实简单，二重循环，遍历过去就行了
//存的时候只要存最开头的因子和因数的数量就行了。

//边界条件考虑一下素数

#include <cstdio>
#include <cmath>

int main(){
	int n;
	scanf("%d", &n);

	int first, len = 0;

	int tmpN, tmpF;
	int fac;

	int sqr = (int)sqrt(n * 1.0);
	for (int i = 2; i <= sqr; i++){//这里可以修剪一下因为不可能有超过根号n的连续因子

		if (n % i == 0){
			tmpN = n, tmpF = fac = i;

			while (tmpN % fac == 0){
				tmpN /= fac;
				fac++;
			}

			if (fac - i > len){
				first = tmpF;
				len = fac - i;
			}
		}

	}

	if (len == 0){
		printf("1\n%d", n);
	}
	else{
		printf("%d\n", len);
		for (int i = 0; i < len; i++){
			printf("%d", first + i);
			if (i != len - 1) printf("*");
		}
	}

	return 0;
}