//B1012

//���������輸�������ģ�����=0�����ǲ����ڣ�����a1�������������ֻ��0���ͻ������⡣
//����Ū��һ��count���飬һ��ans���飬��Ȼ�鷳��һ�㣬����ֱ������

#include <cstdio>

int main(){
	int count[1010] = { 0 }, ans[1010] = { 0 };
	int n;

	scanf("%d", &n);

	int x;
	int flag = 1;
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		switch (x % 5){
		case 0:
			if (x % 2 == 0){
				ans[0] += x;
				count[0]++;
			}
			break;
		case 1:
			ans[1] += x*flag;
			flag = -flag;
			count[1]++;
			break;
		case 2:
			ans[2]++;
			count[2]++;
			break;
		case 3:
			ans[3] += x;
			count[3]++;
			break;
		case 4:
			if (x > ans[4]){
				ans[4] = x;
			}
			count[4]++;
			break;
		}
	}

	if (count[0] == 0) printf("N ");
	else printf("%d ", ans[0]);
	if (count[1] == 0) printf("N ");
	else printf("%d ", ans[1]);
	if (count[2] == 0) printf("N ");
	else printf("%d ", ans[2]);
	if (count[3] == 0) printf("N ");
	else printf("%.1f ", 1.0*ans[3] / count[3]);
	if (count[4] == 0) printf("N");
	else printf("%d", ans[4]);
	

	return 0;
}