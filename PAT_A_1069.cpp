#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

void to_array(int n, int num[]){
	for (int i = 0; i < 4; i++){//因为一定是4个，所以这样做最快
		num[i] = n % 10;
		n /= 10;
	}
}

int to_number(int num[]){
	int sum = 0;
	for (int i = 0; i < 4; i++){
		sum = sum * 10 + num[i];
	}
	return sum;
}

int main(){
	int n, num[5];
	scanf("%d", &n);
	int max, min;
	do{
		to_array(n, num);
		sort(num, num + 4);
		min = to_number(num);
		sort(num, num + 4, cmp);
		max = to_number(num);
		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);//想要保留前面的0，只要用格式输出就行了
	} while (n != 0 && n != 6174); //一开始就给你0的情况，也要执行一步

	return 0;
}