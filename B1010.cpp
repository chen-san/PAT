//B1010

//�ܺõ�һ����
//��һ���������棬�����ָ���������ϵ��

//�����㣬��while EOF������һ��ʼ���������ж��ٵ����룬�������ʵ����
//��ο�������Ŀո�û��һ�����Եı�־���Ǿ��Լ�Ūһ��count����
//����������� 0 0

#include <cstdio>

int main(){
	int a[1010] = { 0 };
	int k, e;
	int count = 0;
	while (scanf("%d%d", &k, &e) != EOF){
		a[e] = k;
	}
	//��
	for (int i = 0; i < 1009; i++){
		a[i] = a[i + 1] * (i + 1);
		a[i + 1] = 0;
		if (a[i] != 0) count++;
	}

	//�����������
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