//A1005

//我已开始想，要不要用字符串形式读入，后来一想，整数形式就可以枚举每一位了。
//后来又一想，这10^100呢，用longlong也不够，还是只能字符串
//简单基础题

#include <cstdio>
#include <cstring>

int main(){
	char str[102];
	gets(str);//比scanf写法快多了，为什么还要用scanf

	int len = strlen(str);
	int sum = 0;
	for (int i = 0; i < len; i++){
		sum += str[i] - '0';
	}

	int numLen = 0;
	int num[3];
	do{
		num[numLen++] = sum % 10;
		sum /= 10;
	} while (sum != 0);

	char change[10][7] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	for (int i = numLen - 1; i >= 0; i--){
		printf("%s", change[num[i]]);
		if (i != 0) printf(" ");
	}

	return 0;
}