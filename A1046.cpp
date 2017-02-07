//A1046

//设一个累计距离的数组dis[],这样的话，操作复杂度就是1，要不然每次操作的复杂度就是n

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int main(){
	int n;
	int dis[maxn] = { 0 };
	scanf("%d", &n);

	int sum = 0;
	int x;
	for (int i = 1; i <= n; i++){
		scanf("%d", &x);
		dis[i + 1] = x + dis[i];
		sum += x;
	}

	int m;
	scanf("%d", &m);
	int left, right;
	int res;
	for (int i = 0; i < m; i++){
		scanf("%d%d", &left, &right);
		if (left > right) swap(left, right);
		res = dis[right] - dis[left];

		printf("%d\n", min(res, sum - res));
	}

	return 0;
}