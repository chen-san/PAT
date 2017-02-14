//A1092

//hash题,这道题啊，我冥思苦想了好久也没思路。

//告诉你已经有的东西，和你要的东西，要你算缺还是多。

#include <cstdio>
#include <cstring>

int isHave[128] = { 0 };

int main(){
	char str[1010];
	gets(str);
	int len1 = strlen(str);
	for (int i = 0; i < len1; i++){
		isHave[str[i]]++;//映射的规则仍然用ascii规则，转化都不用转化，因为简单嘛，我懒
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