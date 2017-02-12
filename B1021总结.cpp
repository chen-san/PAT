//B1021

//这种题其实有两种思路，一是以整型读入，再将数存入整型数组中，然后枚举遍历。
//二是直接以字符串形式读入，相当于存入字符数组中，只不过枚举的时候，要将字符转化为整型。但是胜在省空间

#include <cstdio>
#include <cstring>
int main(){
	char str[1001];
	scanf("%s", str);
	int len = strlen(str);//为了遍历

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