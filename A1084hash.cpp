//A1084

//hash�⣬��һ��hashTable[]���飬�����������Ϊ��Ӧ���±꣬��������ĸ����ת��Ϊ����

#include <cstdio>
#include <cstring>

bool hash[128] = { false };//ascii��һ����ô��

int main(){
	char str1[81];
	char str2[81];
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int num;
	char c;
	for (int i = 0; i < len2; i++){
		c = str2[i];
		if (c <= 'z' && c >= 'a')
			c = c - 'a' + 'A';
		num = c;//acsii��ֱ��ת��Ϊ��Ӧ����
		hash[num] = true;
	}

	for (int i = 0; i < len1; i++){
		c = str1[i];
		if (c <= 'z' && c >= 'a')
			c = c - 'a' + 'A';
		num = c;
		if (hash[num] == false){
				printf("%c", c);
			hash[num] = true;//��ֻ֤�����һ��
		}
	}


	return 0;
}