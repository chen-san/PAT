//A1019

//����⣬£������������Ϊn���ƣ����ж��Ƿ���ġ�
//ʮ���ƻ�Ϊn���Ʊ�׼д���Ǵ���������պ÷����жϣ�һ���򵥵ı����͹���

#include <cstdio>
int main(){
	int a[31];//��Ž���������С�Ƕ����ƣ�31λ���㹻��
	int n, b;

	scanf("%d%d", &n, &b);

	int num = 0;
	do{
		a[num++] = n % b;
		n /= b;
	} while (n != 0);

	num--;//�����һ��

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