//B1022

//����ת����ʮ����ת��ΪD����
//������Ҫ�ú�����

#include <cstdio>

int main(){
	int a, b, D;
	scanf("%d %d %d", &a, &b, &D);

	int sum = a + b;
	int d[31], num = 0;
	do{
		d[num++] = sum % D;
		sum /= D;
	} while (sum != 0);

	for (int i = num - 1; i >= 0; i--){
		printf("%d", d[i]);
	}

//��һ������ӵ�λ����λ���洢D���ƣ�num��ʾ�м�λ��d[num - 1]��d[0]��ΪD���ơ�
//��Ϊ������һλ�����Ա������ѭ����Ϊ�˼���sum ==0�����������dowhile

	return 0;
}


