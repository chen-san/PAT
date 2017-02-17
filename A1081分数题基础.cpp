//A1081

//分数模拟题,基础

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;//用long long ，int可能会溢出

struct Fraction{
	int up, down;
};

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

Fraction reduction(Fraction f){//分数化简，拢共分三步
	if (f.down < 0){
		f.up = -f.up;
		f.down = -f.down;
	}
	if (f.up == 0){
		f.down = 1;
	}
	else{
		int d = gcd(abs(f.up), abs(f.down));//注意先取绝对值
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
		printf("%d", f.up);//整数输出
	}
	else if (abs(f.up) > abs(f.down)){
		printf("%d %d/%d", f.up / f.down, abs(f.up) % abs(f.down), f.down);//带分数输出，注意
	}
	else{
		printf("%d/%d", f.up, f.down);//真分数输出
	}
}


int main(){
	int n;
	scanf("%d", &n);

	Fraction sum, temp;
	sum.up = 0, sum.down = 1;//初始化

	for (int i = 0; i < n; i++){
		scanf("%d/%d", &temp.up, &temp.down);
		sum = add(sum, temp);
	}

	showResult(sum);
	
	return 0;
}