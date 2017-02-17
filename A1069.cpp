//A1069

//��Ŀ��ʵ�򵥣�����ѭ����������ȥ������
//���ʱ��ֻҪ���ͷ�����Ӻ����������������ˡ�

//�߽���������һ������

#include <cstdio>
#include <cmath>

int main(){
	int n;
	scanf("%d", &n);

	int first, len = 0;

	int tmpN, tmpF;
	int fac;

	int sqr = (int)sqrt(n * 1.0);
	for (int i = 2; i <= sqr; i++){//��������޼�һ����Ϊ�������г�������n����������

		if (n % i == 0){
			tmpN = n, tmpF = fac = i;

			while (tmpN % fac == 0){
				tmpN /= fac;
				fac++;
			}

			if (fac - i > len){
				first = tmpF;
				len = fac - i;
			}
		}

	}

	if (len == 0){
		printf("1\n%d", n);
	}
	else{
		printf("%d\n", len);
		for (int i = 0; i < len; i++){
			printf("%d", first + i);
			if (i != len - 1) printf("*");
		}
	}

	return 0;
}