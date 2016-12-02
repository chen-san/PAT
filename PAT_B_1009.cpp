#include <cstdio>
#include <cstring>
int main(){
	char str[90];
	char ans[90][90]; //用字符串组来储存每个单词
	gets(str);

	int len = strlen(str);//cstring中的函数

	int row = 0, col = 0;
	for (int i = 0; i < len; i++){
		if (str[i] != ' '){
			ans[row][col++] = str[i];
		}
		else{
			ans[row][col] = '\0';
			row++;
			col = 0;
		}
	}
	ans[row][col] = '\0';

	for (int i = row; i >= 0; i--){
		printf("%s", ans[i]);
		if (i > 0)
			printf(" ");//我已不知道空格怎么打印效率最高
	}

	return 0;
}