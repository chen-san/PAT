//A1055

//≈≈–ÚÃ‚

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Tuhao{
	char name[10];
	int age, worth;
}hao[100010];

bool cmp(Tuhao a, Tuhao b){
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%s%d%d", hao[i].name, &hao[i].age, &hao[i].worth);
	}
	sort(hao, hao + n, cmp);

	int num, lowAge, highAge;
	int cnt;
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &num, &lowAge, &highAge);
		printf("Case #%d:\n", i + 1);
		cnt = 0;
		for (int j = 0; j < n && cnt < num; j++){
			if (hao[j].age <= highAge && hao[j].age >= lowAge){
				printf("%s %d %d\n", hao[j].name, hao[j].age, hao[j].worth);
				cnt++;
			}
		}
		if (cnt == 0){
			printf("None\n");
		}
	}


	return 0;
}