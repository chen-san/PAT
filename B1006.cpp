//B1006

//����������������飬�ٴӸ�λ����λ����������
//������·

#include <cstdio>
int main(){
	int a[5];
	int n;
	scanf("%d", &n);

	int num = 0;
	do{
		a[num++] = n % 10;
		n /= 10;
	} while (n != 0);//����n=0�����

	for (int i = num - 1; i >= 0; i--){
		if (i == 2){
			for (int j = 0; j < a[2]; j++)
				printf("B");
		}
		else if (i == 1){
			for (int j = 0; j < a[1]; j++)
				printf("S");
		}
		else{
			for (int j = 1; j <= a[0]; j++)
				printf("%d", j);
		}
	}

	return 0;
}