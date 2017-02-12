//B1006

//把输入的数整进数组，再从高位到低位遍历就行了
//都是套路

#include <cstdio>
int main(){
	int a[5];
	int n;
	scanf("%d", &n);

	int num = 0;
	do{
		a[num++] = n % 10;
		n /= 10;
	} while (n != 0);//考虑n=0的情况

	for (int i = num - 1; i >= 0; i--){
		if (i == 2){
			for (int j = 0; j < a[2]; j++)
				printf("B");
		}
		else if (i == 1){
			for (int j = 0; j < a[1]; j++)
				printf("S");
		}
		else{
			for (int j = 1; j <= a[0]; j++)
				printf("%d", j);
		}
	}

	return 0;
}