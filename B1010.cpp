//B1010

//很好的一道题
//用一个数组来存，序号是指数，存的是系数

//几个点，用while EOF来输入一开始不告诉你有多少的输入，这才是现实的嘛
//如何控制输出的空格，没有一个明显的标志，那就自己弄一个count计数
//特殊情况考虑 0 0

#include <cstdio>

int main(){
	int a[1010] = { 0 };
	int k, e;
	int count = 0;
	while (scanf("%d%d", &k, &e) != EOF){
		a[e] = k;
	}
	//求导
	for (int i = 0; i < 1009; i++){
		a[i] = a[i + 1] * (i + 1);
		a[i + 1] = 0;
		if (a[i] != 0) count++;
	}

	//考虑特殊情况
	if (count == 0)
		printf("0 0");
	else{
		for (int i = 1009; i >= 0; i--){
			if (a[i] != 0){
				printf("%d %d", a[i], i);
				count--;
				if (count > 0) printf(" ");
			}
		}
	}

	return 0;
}