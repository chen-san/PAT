#include <cstdio>
#include<algorithm>

using namespace std;

struct mooncake{
	double store;
	double sell;
	double price;
}cake[1010];

bool cmp(mooncake a, mooncake b){
	return a.price > b.price;
}

int main(){
	int n;
	double need;
	scanf("%d%lf", &n, &need);

	for (int i = 0; i < n; i++){
		scanf("%lf", &cake[i].store);
	}

	for (int i = 0; i < n; i++){
		scanf("%lf", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;
	}

	sort(cake, cake + n, cmp);

	double sum = 0;

	for (int i = 0; i < n; i++){
		if (cake[i].store < need){
			need -= cake[i].store;
			sum += cake[i].sell;
		}
		else{
			sum += cake[i].price * need;
			break;
		}
	}

	printf("%.2f", sum);
	return 0;
}