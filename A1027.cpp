//A1027

//����ת��������ת����֮������ֻ����λ�����Բ����Ǹ���·��д����ֱ��ȡ�������

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

