//B1028

//时间年月日的处理

#include <cstdio>

struct Person{
	char name[6];
	int y, m, d;
};

bool isBig(Person p1, Person p2){//判断日期大小， 如果大于等于，返回true
	if (p1.y != p2.y) return p1.y > p2.y;
	else if (p1.m != p2.m) return p1.m > p2.m;
	else return p1.d >= p2.d;
}

bool isSmall(Person p1, Person p2){//判断日期大小， 如果小于等于，返回true
	if (p1.y != p2.y) return p1.y < p2.y;
	else if (p1.m != p2.m) return p1.m < p2.m;
	else return p1.d <= p2.d;
}

int main(){
	Person oldest, youngest, left, right, temp;

	youngest.y = left.y = 1814;
	oldest.y = right.y = 2014;
	youngest.m = right.m = oldest.m = left.m = 9;
	youngest.d = right.d = oldest.d = left.d = 6;

	int n, count = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%s %d/%d/%d", temp.name, &temp.y, &temp.m, &temp.d);
		if (isBig(temp, left) && isSmall(temp, right)){
			count++;
			if (isBig(temp, youngest)) youngest = temp;
			if (isSmall(temp, oldest)) oldest = temp;
		}
	}

	if (count == 0){
		printf("0");//特殊情况考虑
	}
	else{
		printf("%d %s %s", count, oldest.name, youngest.name);
	}


	return 0;
}