//B1009

//题目有点难操作，倒序输出容易，弄一个数组，直接倒序就行了。但是要单词内不倒序，单词顺序倒序，就难了。
//用一个存字符串的数组，中间操作一下。

//这道题要注意的是scanf("%s", str)和gets(str)这两个字符串输入方式的区别

#include <cstdio>
#include <cstring>

int main(){
	char str[81];
	gets(str);

	char danci[81][81];
	int h = 0, l = 0;//行和列
	int len = strlen(str);

	for (int i = 0; i < len; i++){
		if (str[i] != ' '){
			danci[h][l++] = str[i];
		}
		else{
			danci[h][l] = '\0';//关键
			                   //只有以scanf和puts方式输入，后面才会自动加上‘\0’结束符，其它都要自己加 
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