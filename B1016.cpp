//B1016

//基础，怎样把一个数的每一位取出来。
//10^10超过int范围，所以用long long

#include<cstdio>
int main(){
	long long a, b;
	int da, db;

	scanf("%lld%d%lld%d", &a, &da, &b, &db);

	long long pa = 0, pb = 0;
	while (a != 0){
		if (a % 10 == da){
			pa = pa * 10 + da;
		}
		a /= 10;
	}
	while (b != 0){
		if (b % 10 == db){
			pb = pb * 10 + db;
		}
		b /= 10;
	}

	printf("%lld", pa + pb);

	return 0;
}