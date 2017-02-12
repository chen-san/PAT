//A1027

//进制转化，而且转化后之后有且只有两位，可以不用那个套路的写法，直接取余就行了

#include <cstdio>
int main(){
	char n2c[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };

	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);

	printf("#");
	printf("%c%c", n2c[r / 13], n2c[r % 13]);
	printf("%c%c", n2c[g / 13], n2c[g % 13]);
	printf("%c%c", n2c[b / 13], n2c[b % 13]);



	return 0;
}

