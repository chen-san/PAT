//A1069

//���ְ�λ������Ҫ������ת��Ϊint�������char���飬����ת��Ϊint���顣
//�������������ʱ����ת��Ϊ���֡�

#include <cstdio>
#include <algorithm>
using namespace std;

void toArray(int n, int num[]){
	for (int i = 0; i < 4; i++){
		num[i] = n % 10;
		n /= 10;
	} //֮���Բ��ó����д�������Ҫ������λ
}

int toNum(int num[]){
	int sum = 0;
	for (int i = 0; i < 4; i++){
		sum = sum * 10 + num[i];
	}
	return sum;
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int x, num[4];
	scanf("%d", &x);
	int min, max;
	do{
		toArray(x, num);//ע��д��
		sort(num, num + 4);
		min = toNum(num);
		sort(num, num + 4, cmp);
		max = toNum(num);
		x = max - min;
		printf("%04d - %04d = %04d\n", max, min, x);
	} while (x != 6174 && x != 0);
	

	return 0;
}