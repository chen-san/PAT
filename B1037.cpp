//B1037

//���ֽ��Ƶ�ת������ʵ�������գ�ʱ�����࣬����Ϊ��С��λ�����ˡ�
//�����Ļ����ж�һ�£����������

#include <cstdio>
int main(){
	int x1, y1, z1;
	int x2, y2, z2;
	scanf("%d.%d.%d %d.%d.%d", &x1, &y1, &z1, &x2, &y2, &z2);

	int price = x1 * 29 * 17 + y1 * 29 + z1;
	int money = x2 * 29 * 17 + y2 * 29 + z2;

	int change = money - price;

	if (change < 0){
		printf("-");
		change = -change;
	}

	printf("%d.%d.%d", change / 29 / 17, change / 29 % 17, change % 29);

	return 0;
}