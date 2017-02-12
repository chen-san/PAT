//B1031

//以字符串形式输入, 边输入边处理好了

#include <cstdio>
#include <cstring>

int weight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };//权重数组

char change[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

int main(){
	int n;
	char str[19];
	scanf("%d", &n);

	bool fuckone = false;
	for (int i = 0; i < n; i++){
		scanf("%s", str);
		
		int j, ans = 0;
		for (j = 0; j < 17; j++){
			if (str[j] > '9' || str[j] < '0') break;
			ans += (str[j] - '0') * weight[j];
		}
		if (j < 17 || change[ans % 11] != str[17]){
			fuckone = true;
			printf("%s\n", str);
		}
	}

	if (fuckone == false){
		printf("All passed");
	}

	return 0;
}