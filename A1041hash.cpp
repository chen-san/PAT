//A1041

//��һ��hashTable����ÿ�����ֳ��ֵĴ�����Ȼ�����һ��ʼ���������������һ��ʼ��Ҫ��һ�������������

#include <cstdio>

int hashTable[10010] = { 0 };
int a[100010];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
		hashTable[a[i]]++;
	}

	int k = -1;
	for (int i = 0; i < n; i++){
		if (hashTable[a[i]] == 1){
			k = a[i];
			break;
		}
	}

	if (k == -1){
		printf("None");
	}
	else{
		printf("%d", k);
	}

	return 0;
}