//A1042

//�����������Ų���ǰ��������������ڸ��ƹ�ȥ������һ�β����������������������е�󡣱仯�Ĺ���Ҳ��һ������
//����һ�����ǣ��ڲ��������У������ñ�Ŵ��滨ɫ�����Ҫ������źͻ�ɫ֮��Ķ�Ӧ��ϵ

#include <cstdio>

int main(){
	int start[55], end[55], shuff[55];
	int n;

	scanf("%d", &n);

	for (int i = 1; i < 55; i++){
		start[i] = i;
	}
	for (int i = 1; i < 55; i++){
		scanf("%d", shuff + i);
	}

	for (int i = 0; i < n; i++){
		for (int j = 1; j < 55; j++){
			end[shuff[j]] = start[j];
		}
		for (int j = 1; j < 55; j++){
			start[j] = end[j];
		}
	}

	//����źͻ�ɫ��Ӧ
	char huase[5] = { 'S', 'H', 'C', 'D', 'J' };

	for (int i = 1; i < 55; i++){
		printf("%c%d", huase[(start[i] - 1) / 13], (start[i] - 1) % 13 + 1);
		if (i != 54)
			printf(" ");
	}


	return 0;
}