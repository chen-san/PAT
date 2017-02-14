//B1033

//hash题

#include <cstdio>
#include <cstring>

bool isBroken[128] = { false };
int main(){
	char str[100010];
	gets(str);

	int len = strlen(str);
	for (int i = 0; i < len; i++){
		isBroken[str[i]] = true;
	}

	gets(str);
	len = strlen(str);
	for (int i = 0; i < len; i++){
		if (str[i] >= 'A' && str[i] <= 'Z'){
			if (isBroken['+'] == false && isBroken[str[i]] == false)
				printf("%c", str[i]);
		}
		else if (str[i] >= 'a' && str[i] <= 'z'){
			//因为存的都是大写
			if (isBroken[str[i] - 'a' + 'A'] == false)
				printf("%c", str[i]);
		}
		else{
			if (isBroken[str[i]] == false)
				printf("%c", str[i]);
		}
	}

	return 0;
}