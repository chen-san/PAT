//A1041

//用一个hashTable来存每个数字出现的次数，然后遍历一开始的输入的数，所以一开始还要用一个数组存起来。

#include <cstdio>

int hashTable[10010] = { 0 };
int a[100010];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
		hashTable[a[i]]++;
	}

	int k = -1;
	for (int i = 0; i < n; i++){
		if (hashTable[a[i]] == 1){
			k = a[i];
			break;
		}
	}

	if (k == -1){
		printf("None");
	}
	else{
		printf("%d", k);
	}

	return 0;
}