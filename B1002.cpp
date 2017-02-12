//B1002

//以字符串形式输入, 处理得到和，和再化成一个整型数组处理比较好。
//一道题考了两个点，可以

#include <cstdio>
#include <cstring>

int main(){
	char str[102];
	scanf("%s", str);
	int len = strlen(str);
	int sum = 0;
	for (int i = 0; i < len; i++){
		sum += str[i] - '0';
	}

	int num = 0, ans[4];//得到的和最多也就900
	do{
		ans[num++] = sum % 10;
		sum /= 10;
	} while (sum != 0);

	char change[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

	for (int i = num - 1; i >= 0; i--){
		printf("%s", change[ans[i]]);
		if (i > 0) printf(" ");
	}

	return 0;
}

