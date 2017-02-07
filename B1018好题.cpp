//B1018

//很好的一道题，如何处理石头剪子布，用map将B、C、J转化为0、1、2，则发现如果值+1，则相克。

#include <cstdio>
#include <map>

using namespace std;

int main(){
	int A[3] = { 0 }, B[3] = { 0 };//各自胜平负数
	int Awin[3] = { 0 }, Bwin[3] = { 0 };//三种手势分别获胜的次数
	int n;
	map<char, int> mp;
	mp['B'] = 0;
	mp['C'] = 1;
	mp['J'] = 2;

	scanf("%d", &n);
	char c1, c2;
	int k1, k2;
	for (int i = 0; i < n; i++){
		getchar();//把换行键吸收掉，关键
		scanf("%c %c", &c1, &c2);
		k1 = mp[c1];
		k2 = mp[c2];

		if ((k1 + 1) % 3 == k2){
			A[0]++;
			B[2]++;
			Awin[k1]++;
		}
		else if (k1 == k2){
			A[1]++;
			B[1]++;
		}
		else{
			A[2]++;
			B[0]++;
			Bwin[k2]++;
		}

	}

	int Aid = 0, Bid = 0;
	for (int i = 0; i < 3; i++){
		if (Awin[i] > Awin[Aid]) Aid = i;
		if (Bwin[i] > Bwin[Bid]) Bid = i;
	}

	char num2char[3] = { 'B', 'C', 'J' };//再建一个数到字符的映射，真麻烦

	printf("%d %d %d\n", A[0], A[1], A[2]);
	printf("%d %d %d\n", B[0], B[1], B[2]);

	printf("%c %c", num2char[Aid], num2char[Bid]);


	return 0;
}