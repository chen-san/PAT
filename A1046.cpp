//A1046

//��һ���ۼƾ��������dis[],�����Ļ����������ӶȾ���1��Ҫ��Ȼÿ�β����ĸ��ӶȾ���n

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