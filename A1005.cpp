//A1005

//���ѿ�ʼ�룬Ҫ��Ҫ���ַ�����ʽ���룬����һ�룬������ʽ�Ϳ���ö��ÿһλ�ˡ�
//������һ�룬��10^100�أ���longlongҲ����������ֻ���ַ���
//�򵥻�����

#include <cstdio>
#include <cstring>

int main(){
	char str[102];
	gets(str);//��scanfд������ˣ�Ϊʲô��Ҫ��scanf

	int len = strlen(str);
	int sum = 0;
	for (int i = 0; i < len; i++){
		sum += str[i] - '0';
	}

	int numLen = 0;
	int num[3];
	do{
		num[numLen++] = sum % 10;
		sum /= 10;
	} while (sum != 0);

	char change[10][7] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	for (int i = numLen - 1; i >= 0; i--){
		printf("%s", change[num[i]]);
		if (i != 0) printf(" ");
	}

	return 0;
}