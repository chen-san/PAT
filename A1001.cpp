//A1001

//�ȼ��㣬Ȼ������������������

#include <cstdio>
int main(){
	int a, b, sum;
	scanf("%d%d", &a, &b);
	sum = a + b;
	if (sum < 0){
		printf("-");
		sum = -sum;
	}

	int num[11];
	int len = 0;
	do{
		num[len++] = sum % 10;
		sum /= 10;
	} while (sum != 0);

	for (int i = len - 1; i >= 0; i--){//�Ӹ�λ��ʼ���
		printf("%d", num[i]);
		if (i % 3 == 0 && i != 0) printf(",");//���Ϊ3�ı�������ӡ��������˺þá�
	}
	return 0;
}