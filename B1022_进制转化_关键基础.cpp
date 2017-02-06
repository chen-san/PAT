//B1022

//进制转换，十进制转化为D进制
//基础，要好好掌握

#include <cstdio>

int main(){
	int a, b, D;
	scanf("%d %d %d", &a, &b, &D);

	int sum = a + b;
	int d[31], num = 0;
	do{
		d[num++] = sum % D;
		sum /= D;
	} while (sum != 0);

	for (int i = num - 1; i >= 0; i--){
		printf("%d", d[i]);
	}

//用一个数组从低位到高位来存储D进制，num表示有几位，d[num - 1]到d[0]即为D进制。
//因为至少有一位，所以必须进入循环，为了兼容sum ==0的情况，采用dowhile

	return 0;
}


