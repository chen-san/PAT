//A1085

//˫ָ��˼��

#include<cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int main(){
	int n;
	long long p, a[maxn];
	scanf("%d%lld", &n, &p);
	for (int i = 0; i < n; i++){
		scanf("%lld", a + i);//�����ʽҪע��
	}
	sort(a, a + n);
	int i = 0, j = 0;
	int maxLength = 0;
	while (j < n){
		while (a[j] <= a[i] * p && j < n){//j < n������
			j++;
		}
		if ((j - i) > maxLength){
			maxLength = j - i;
		}
		i++;
	}

	printf("%d", maxLength);
	return 0;
}