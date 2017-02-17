//A1078

//hashģ���⣬����
//����̽�ⷨ

#include <cstdio>

bool isPrime(int n){
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0) return false;
	}
	return true;
}

int main(){
	int Tsize, n;
	scanf("%d%d", &Tsize, &n);

	while (!isPrime(Tsize)){
		Tsize++;
	}

	bool hashTable[10010] = { false };

	int x, m, step;
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		for (step = 0; step < Tsize; step++){//ƽ��̽�鷨�������Ҳ���ó���Tsize

			m = (x + step * step) % Tsize;
			if (hashTable[m] == false){
				hashTable[m] = true;
				if (i == 0)
					printf("%d", m);
				else
					printf(" %d", m);//���Ƹ�ʽ�������������������һ��count
				break;
			}

		}

		if (step == Tsize){
			if (i == 0)
				printf("-");
			else
				printf(" -");
		}
	}

	return 0;
}
