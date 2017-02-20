//A1063

//用set，两个的交集/并集

#include <cstdio>
#include <set>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	set<int> s[51];

	int k, x;
	for (int i = 1; i <= n; i++){
		scanf("%d", &k);
		for (int j = 0; j < k; j++){
			scanf("%d", &x);
			s[i].insert(x);
		}
	}

	int m;
	scanf("%d", &m);
	int s1, s2;
	int totalNum, sameNum;
	for (int i = 0; i < m; i++){
		scanf("%d%d", &s1, &s2);
		totalNum = s[s1].size() + s[s2].size();
		sameNum = 0;
		//遍历s1
		for (set<int>::iterator it = s[s1].begin(); it != s[s1].end(); it++){
			if (s[s2].find(*it) != s[s2].end()){
				sameNum++;
			}
		}
		totalNum = totalNum - sameNum;
		printf("%.1f%%\n", 1.0 * sameNum / totalNum * 100);//百分号输出用两个%%，//同理
	}

	return 0;
}