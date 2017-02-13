//B1015

//最基础的排序题，不过要分一下类。
//我本来做的时候，把每一个类都塞进一个vector里面，最后在输出来，其实没有必要。
//在struct里面设一个flag，排在前面的数设小一点,一起排掉好了，简单明了。
//至于不符合条件的，flag设为最大，输出的时候不输出就行了。都不用额外的空间开销。

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student{
	char id[10];//题目又没有告诉我们序号有多长
	int de, cai, sum;
	int flag;//关键思想
}stu[100010];

bool cmp(Student a, Student b){
	if (a.flag != b.flag) return a.flag < b.flag;
	else if (a.sum != b.sum) return a.sum > b.sum;
	else if (a.de != b.de) return a.de > b.de;
	else return strcmp(a.id, b.id) < 0;//这里字符串一开始我是直接比较了，编译没问题，但是运行出问题，只能用strcmp（）啊
}

int main(){
	int n, L, H;
	scanf("%d%d%d", &n, &L, &H);

	int cnt = n;
	for (int i = 0; i < n; i++){//边输入边处理,其实就是分个类
		scanf("%s%d%d", stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].cai + stu[i].de;
		if (stu[i].cai < L || stu[i].de < L){
			stu[i].flag = 5;
			cnt--;//本来我想从零开始数的，用来发现还是从n往下减方便
		}
		else if (stu[i].de >= H && stu[i].cai >= H) stu[i].flag = 1;
		else if (stu[i].de >= H && stu[i].cai < H) stu[i].flag = 2;
		else if (stu[i].de >= stu[i].cai) stu[i].flag = 3;
		else stu[i].flag = 4;
	}

	sort(stu, stu + n, cmp);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++){
		printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	}

	return 0;
}