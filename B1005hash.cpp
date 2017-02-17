//B1005

//题意很难理解，所谓的关键数就是在所有数的递推序列中没有出现过的数

#include <cstdio>
#include <algorithm>
using namespace std;

bool hashTable[10000] = {false};//大一点
int a[101];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n;
	scanf("%d", &n);

	int m;
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
		m = a[i];
		do{
			if (m % 2 == 0) m /= 2;
			else m = (3 * m + 1) / 2;
			hashTable[m] = true;
		} while (m != 1);
	}

	sort(a, a + n, cmp);

	int cnt = 0;//为了控制空格，还得先数一下有几个
	for (int i = 0; i < n; i++){
		if (hashTable[a[i]] == false)
			cnt++;
	}

	for (int i = 0; i < n; i++){
		if (hashTable[a[i]] == false){
			printf("%d", a[i]);
			cnt--;
			if (cnt != 0){
				printf(" ");
			}
			else
				break;
		}
		
	}


	return 0;
}