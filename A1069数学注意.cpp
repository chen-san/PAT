//A1069

//数字按位排序，需要把数字转化为int数组或者char数组，这里转化为int数组。
//两个数字想减的时候，再转化为数字。

#include <cstdio>
#include <algorithm>
using namespace std;

void toArray(int n, int num[]){
	for (int i = 0; i < 4; i++){
		num[i] = n % 10;
		n /= 10;
	} //之所以不用常规的写法是这边要凑足四位
}

int toNum(int num[]){
	int sum = 0;
	for (int i = 0; i < 4; i++){
		sum = sum * 10 + num[i];
	}
	return sum;
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int x, num[4];
	scanf("%d", &x);
	int min, max;
	do{
		toArray(x, num);//注意写法
		sort(num, num + 4);
		min = toNum(num);
		sort(num, num + 4, cmp);
		max = toNum(num);
		x = max - min;
		printf("%04d - %04d = %04d\n", max, min, x);
	} while (x != 6174 && x != 0);
	

	return 0;
}