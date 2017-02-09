//A1006

//设一个结构体来存数据，设一个early、late来存，边输入边处理。
//这题都能有25分，真水

#include <cstdio>

struct Person{
	char name[16];
	int h1, m1, s1;
	int h2, m2, s2;
};

int main(){
	Person temp, early, late;
	early.h1 = 23, early.m1 = 59, early.s1 = 59;
	late.h2 = 0, late.m2 = 0, late.s2 = 0;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%s %d:%d:%d %d:%d:%d", temp.name, &temp.h1, &temp.m1, &temp.s1, &temp.h2, &temp.m2, &temp.s2);

		if (temp.h1 * 3600 + temp.m1 * 60 + temp.s1 < early.h1 * 3600 + early.m1 * 60 + early.s1)
			early = temp;
		if (temp.h2 * 3600 + temp.m2 * 60 + temp.s2 > late.h2 * 3600 + late.m2 * 60 + late.s2)
			late = temp;
	}

	printf("%s %s", early.name, late.name);

	return 0;
}