//A1011

//ÿ��������ֵ���ҳ����ֵ�������±�

#include <cstdio>
int main(){
	double max;
	int maxid;

	char num2char[3] = { 'W', 'T', 'L' };//�±�ת��Ϊ��ĸ

	double ans = 1.0, x;
	for (int i = 0; i < 3; i++){
		max = 0;
		for (int j = 0; j < 3; j++){
			scanf("%lf", &x);
			if (x > max){
				max = x;
				maxid = j;
			}
		}
		ans *= max;
		printf("%c ", num2char[maxid]);

	}

	printf("%.2f", (ans*0.65 - 1) * 2);

	return 0;
}