//A1001

//先计算，然后把数化成数组就行了

#include <cstdio>
int main(){
	int a, b, sum;
	scanf("%d%d", &a, &b);
	sum = a + b;
	if (sum < 0){
		printf("-");
		sum = -sum;
	}

	int num[11];
	int len = 0;
	do{
		num[len++] = sum % 10;
		sum /= 10;
	} while (sum != 0);

	for (int i = len - 1; i >= 0; i--){//从高位开始输出
		printf("%d", num[i]);
		if (i % 3 == 0 && i != 0) printf(",");//序号为3的倍数后面加“，”想了好久。
	}
	return 0;
}