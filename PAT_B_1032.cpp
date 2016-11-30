#include <cstdio>

const int maxn = 100005;
int school[maxn] = { 0 };

int main(){
	int n, schoolID, score;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d%d", &schoolID, &score);
		school[schoolID] += score;
	}

	int k = 1, Max = -1; 
	for (int i = 1; i <= n; i++){
		if (school[i] > Max){
			k = i;
			Max = school[i];
		}
	}

	printf("%d %d\n", k, Max);

	return 0;
}