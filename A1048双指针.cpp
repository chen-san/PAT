//A1048

//双指针思想

#include<cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int a[maxn];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
	}
	sort(a, a + n);

	int i = 0, j = n - 1;
	while (i < j){
		if (a[i] + a[j] == m) break;
		else if (a[i] + a[j] < m) i++;
		else j--;
	}
	if (i < j)//就不用flag来判断了
		printf("%d %d\n", a[i], a[j]);
	else
		printf("No Solution\n");
	return 0;
}