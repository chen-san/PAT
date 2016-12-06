#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

void to_array(int n, int num[]){
	for (int i = 0; i < 4; i++){//��Ϊһ����4�����������������
		num[i] = n % 10;
		n /= 10;
	}
}

int to_number(int num[]){
	int sum = 0;
	for (int i = 0; i < 4; i++){
		sum = sum * 10 + num[i];
	}
	return sum;
}

int main(){
	int n, num[5];
	scanf("%d", &n);
	int max, min;
	do{
		to_array(n, num);
		sort(num, num + 4);
		min = to_number(num);
		sort(num, num + 4, cmp);
		max = to_number(num);
		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);//��Ҫ����ǰ���0��ֻҪ�ø�ʽ���������
	} while (n != 0 && n != 6174); //һ��ʼ�͸���0�������ҲҪִ��һ��

	return 0;
}