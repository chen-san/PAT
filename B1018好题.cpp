//B1018

//�ܺõ�һ���⣬��δ���ʯͷ���Ӳ�����map��B��C��Jת��Ϊ0��1��2���������ֵ+1������ˡ�

#include <cstdio>
#include <map>

using namespace std;

int main(){
	int A[3] = { 0 }, B[3] = { 0 };//����ʤƽ����
	int Awin[3] = { 0 }, Bwin[3] = { 0 };//�������Ʒֱ��ʤ�Ĵ���
	int n;
	map<char, int> mp;
	mp['B'] = 0;
	mp['C'] = 1;
	mp['J'] = 2;

	scanf("%d", &n);
	char c1, c2;
	int k1, k2;
	for (int i = 0; i < n; i++){
		getchar();//�ѻ��м����յ����ؼ�
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

	char num2char[3] = { 'B', 'C', 'J' };//�ٽ�һ�������ַ���ӳ�䣬���鷳

	printf("%d %d %d\n", A[0], A[1], A[2]);
	printf("%d %d %d\n", B[0], B[1], B[2]);

	printf("%c %c", num2char[Aid], num2char[Bid]);


	return 0;
}