//B1014

#include <cstdio>
#include <cstring>

char week[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};//其实是建立字符和字符串之间的映射，但其实还是这样方便

int main(){
	char str1[61], str2[61], str3[61], str4[61];
	scanf("%s%s%s%s", str1, str2, str3, str4);
	int len1 = strlen(str1);
	int len3 = strlen(str3);

	int i = 0;//因为后面还要用到，就放在外面
	for (i = 0; i < len1; i++){
		if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G'){
			printf("%s ", week[str1[i] - 'A']);
			break;
		}
	}

	for (i++; i < len1; i++){
		if (str1[i] == str2[i]){
			if (str1[i] >= '0' && str1[i] <= '9'){
				printf("%02d:", str1[i] - '0');
				break;
			}
			else if (str1[i] >= 'A' && str2[i] <= 'N'){
				printf("%d:", str1[i] - 'A' + 10);
				break;
			}
		}
	}

	for (i = 0; i < len3; i++){
		if (str3[i] == str4[i] && ((str3[i] >= 'A' && str3[i] <= 'Z') || str3[i] >= 'a' && str3[i] <= 'z')){
			printf("%02d", i);
			break;
		}
	}
	

}

