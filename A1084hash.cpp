//A1084

//hash题，设一个hashTable[]数组，输入的数字作为对应的下标，输入是字母就先转化为数字

#include <cstdio>
#include <cstring>

bool hash[128] = { false };//ascii码一共这么多

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
		num = c;//acsii码直接转化为对应数字
		hash[num] = true;
	}

	for (int i = 0; i < len1; i++){
		c = str1[i];
		if (c <= 'z' && c >= 'a')
			c = c - 'a' + 'A';
		num = c;
		if (hash[num] == false){
				printf("%c", c);
			hash[num] = true;//保证只被输出一次
		}
	}


	return 0;
}