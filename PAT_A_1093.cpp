#include <cstdio>
#include <cstring>

const int MAXN = 100010;
const int MOD = 1000000007;

int main(){
	char str[MAXN];
	int leftP[MAXN] = { 0 }, rightT[MAXN]= { 0 };

	scanf("%s", str);
	int len = strlen(str);

	if (str[0] == 'P')
		leftP[0] = 1;
	for (int i = 1; i < len; i++){
		if (str[i] == 'P')
			leftP[i] = leftP[i - 1] + 1;
		else
			leftP[i] = leftP[i - 1];
	}

	if (str[len - 1] == 'T')
		rightT[len - 1] = 1;

	for (int i = len - 2; i >= 0; i--){
		if (str[i] == 'T')
			rightT[i] = rightT[i + 1] + 1;
		else
			rightT[i] = rightT[i + 1];
	}

	int ans = 0;
	for (int i = 0; i < len; i++){
		if (str[i] == 'A')
			ans = (ans + rightT[i] * leftP[i]) % MOD;
	}

	printf("%d", ans);


	return 0;
}