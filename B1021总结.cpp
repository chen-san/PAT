//B1021

//��������ʵ������˼·��һ�������Ͷ��룬�ٽ����������������У�Ȼ��ö�ٱ�����
//����ֱ�����ַ�����ʽ���룬�൱�ڴ����ַ������У�ֻ����ö�ٵ�ʱ��Ҫ���ַ�ת��Ϊ���͡�����ʤ��ʡ�ռ�

#include <cstdio>
#include <cstring>
int main(){
	char str[1001];
	scanf("%s", str);
	int len = strlen(str);//Ϊ�˱���

	int count[10] = { 0 };
	for (int i = 0; i < len; i++){
		count[str[i] - '0']++;
	}

	for (int i = 0; i < 10; i++){
		if (count[i])
			printf("%d:%d\n", i, count[i]);
	}
	return 0;
}