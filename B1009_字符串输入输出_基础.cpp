//B1009

//��Ŀ�е��Ѳ���������������ף�Ūһ�����飬ֱ�ӵ�������ˡ�����Ҫ�����ڲ����򣬵���˳���򣬾����ˡ�
//��һ�����ַ��������飬�м����һ�¡�

//�����Ҫע�����scanf("%s", str)��gets(str)�������ַ������뷽ʽ������

#include <cstdio>
#include <cstring>

int main(){
	char str[81];
	gets(str);

	char danci[81][81];
	int h = 0, l = 0;//�к���
	int len = strlen(str);

	for (int i = 0; i < len; i++){
		if (str[i] != ' '){
			danci[h][l++] = str[i];
		}
		else{
			danci[h][l] = '\0';//�ؼ�
			                   //ֻ����scanf��puts��ʽ���룬����Ż��Զ����ϡ�\0����������������Ҫ�Լ��� 
			h++;
			l = 0;
		}
	}

	for (int i = h; i >= 0; i--){
		printf("%s", danci[i]);
		if (i > 0) printf(" ");
	}

	

	return 0;
}