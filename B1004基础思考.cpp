//B1004

//设一个结构体存储学生的姓名、学号、分数，用结构数组来存储这些数据。然后再用快排得到最大最小

//不过这样是偷懒的做法，快排的时间复杂度有nlogn，没必要，遍历一下得到最大最小，时间复杂度只有n了

//还能再简便，其实不用数组存起来，直接边输入边处理，用变量max和min来记录好了。这样空间复杂度都省了。

#include <cstdio>

struct Student{
	char name[11];
	char id[15];
	int score;
};

int main(){
	Student temp, max, min;
	max.score = -1;
	min.score = 101;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%s%s%d", &temp.name, &temp.id, &temp.score);//%s遇到空格会自动停止，所以这样写
		if (temp.score < min.score) min = temp;//结构可以直接赋值
		if (temp.score > max.score) max = temp;
	}

	printf("%s %s\n", max.name, max.id);
	printf("%s %s\n", min.name, min.id);

	return 0;
}