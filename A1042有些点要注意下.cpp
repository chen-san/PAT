//A1042

//设两个数组存放操作前后的数。操作后在复制过去，给下一次操作，不过这样开销好像有点大。变化的过程也用一个数组
//还有一个点是，在操作过程中，都是用编号代替花色，最后还要建立编号和花色之间的对应关系

#include <cstdio>

int main(){
	int start[55], end[55], shuff[55];
	int n;

	scanf("%d", &n);

	for (int i = 1; i < 55; i++){
		start[i] = i;
	}
	for (int i = 1; i < 55; i++){
		scanf("%d", shuff + i);
	}

	for (int i = 0; i < n; i++){
		for (int j = 1; j < 55; j++){
			end[shuff[j]] = start[j];
		}
		for (int j = 1; j < 55; j++){
			start[j] = end[j];
		}
	}

	//将编号和花色对应
	char huase[5] = { 'S', 'H', 'C', 'D', 'J' };

	for (int i = 1; i < 55; i++){
		printf("%c%d", huase[(start[i] - 1) / 13], (start[i] - 1) % 13 + 1);
		if (i != 54)
			printf(" ");
	}


	return 0;
}