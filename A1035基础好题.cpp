//A1035

//这道题是好题，由常规操作串联起来的基础好题。
//像这样有关系的好几组数据，就用结构体形式来存储。

//中间有好几步我想偷懒省步骤，发现都不行。

//因为最后要输出修改过的密码数，所以只能全部处理完再输出，不能边处理边输出。
//又因为要输出修改之后的，所以每个修改的还要加一个标志，ischange；

//字符长短都没有告诉我们……

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
		N[i].ischange = false;//初始化一下
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
			printf("There are %d accounts and no account is modified", n);//单复数，坑爹啊
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

