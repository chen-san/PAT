//A1092

//hash��,����Ⱑ����ڤ˼�����˺þ�Ҳû˼·��

//�������Ѿ��еĶ���������Ҫ�Ķ�����Ҫ����ȱ���Ƕࡣ

#include <cstdio>
#include <cstring>

int isHave[128] = { 0 };

int main(){
	char str[1010];
	gets(str);
	int len1 = strlen(str);
	for (int i = 0; i < len1; i++){
		isHave[str[i]]++;//ӳ��Ĺ�����Ȼ��ascii����ת��������ת������Ϊ�������
	}

	gets(str);
	int len2 = strlen(str);
	int lack = 0;
	for (int i = 0; i < len2; i++){
		isHave[str[i]]--;
		if (isHave[str[i]] < 0)
			lack++;
	}

	if (lack == 0){
		printf("Yes %d", len1 - len2);
	}
	else
		printf("No %d", lack);

	return 0;
}