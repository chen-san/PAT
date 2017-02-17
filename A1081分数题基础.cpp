//A1081

//����ģ����,����

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;//��long long ��int���ܻ����

struct Fraction{
	int up, down;
};

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

Fraction reduction(Fraction f){//��������£��������
	if (f.down < 0){
		f.up = -f.up;
		f.down = -f.down;
	}
	if (f.up == 0){
		f.down = 1;
	}
	else{
		int d = gcd(abs(f.up), abs(f.down));//ע����ȡ����ֵ
		f.up /= d;
		f.down /= d;
	}

	return f;
}

Fraction add(Fraction a, Fraction b){
	Fraction res;
	res.up = a.up * b.down + b.up * a.down;
	res.down = a.down * b.down;
	return reduction(res);
}

void showResult(Fraction f){
	if (f.down == 1){
		printf("%d", f.up);//�������
	}
	else if (abs(f.up) > abs(f.down)){
		printf("%d %d/%d", f.up / f.down, abs(f.up) % abs(f.down), f.down);//�����������ע��
	}
	else{
		printf("%d/%d", f.up, f.down);//��������
	}
}


int main(){
	int n;
	scanf("%d", &n);

	Fraction sum, temp;
	sum.up = 0, sum.down = 1;//��ʼ��

	for (int i = 0; i < n; i++){
		scanf("%d/%d", &temp.up, &temp.down);
		sum = add(sum, temp);
	}

	showResult(sum);
	
	return 0;
}