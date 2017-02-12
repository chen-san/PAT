//A1019

//这道题，拢共分俩步，化为n进制，再判断是否回文。
//十进制化为n进制标准写法是存在数组里，刚好方便判断，一个简单的遍历就够了

#include <cstdio>
int main(){
	int a[31];//存放进制数，最小是二进制，31位就足够了
	int n, b;

	scanf("%d%d", &n, &b);

	int num = 0;
	do{
		a[num++] = n % b;
		n /= b;
	} while (n != 0);

	num--;//多加了一次

	int flag = 0;
	for (int i = 0; i <= num / 2; i++){
		if (a[i] != a[num - i]){
			flag = 1;
			break;
		}
	}

	if (flag == 1) printf("No\n");
	else printf("Yes\n");

	for (int i = num; i >= 0; i--){
		printf("%d", a[i]);
		if (i != 0) printf(" ");
	}

	return 0;
}