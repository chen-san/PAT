//A1035

//������Ǻ��⣬�ɳ���������������Ļ������⡣
//�������й�ϵ�ĺü������ݣ����ýṹ����ʽ���洢��

//�м��кü�������͵��ʡ���裬���ֶ����С�

//��Ϊ���Ҫ����޸Ĺ���������������ֻ��ȫ������������������ܱߴ���������
//����ΪҪ����޸�֮��ģ�����ÿ���޸ĵĻ�Ҫ��һ����־��ischange��

//�ַ����̶�û�и������ǡ���

#include <cstdio>
#include <cstring>

struct node{
	char name[20];
	char password[20];
	bool ischange;
}N[1001];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%s%s", N[i].name, N[i].password);
		N[i].ischange = false;//��ʼ��һ��
	}

	int cnt = 0;
	for (int i = 0; i < n; i++){

		int len = strlen(N[i].password);
		for (int j = 0; j < len; j++){
			if (N[i].password[j] == '1'){
				N[i].password[j] = '@';
				N[i].ischange = true;
			}
			else if (N[i].password[j] == '0'){
				N[i].password[j] = '%';
				N[i].ischange = true;
			}
			else if (N[i].password[j] == 'l'){
				N[i].password[j] = 'L';
				N[i].ischange = true;
			}
			else if (N[i].password[j] == 'O'){
				N[i].password[j] = 'o';
				N[i].ischange = true;
			}
		}

		if (N[i].ischange == true) cnt++;
	}

	if (cnt == 0){
		if (n == 1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified", n);//���������ӵ���
	}
	else{
		printf("%d\n", cnt);
		for (int i = 0; i < n; i++){
			if (N[i].ischange == true){
				printf("%s %s\n", N[i].name, N[i].password);
			}
		}
	}

	return 0;
}

