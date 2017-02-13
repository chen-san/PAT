//A1012

//因为要根据id查排名，快速的办法时将id作为下标，空间换时间，但是结构体数组空间消耗太大，另开一个数组来存排名，

//结构体里面用一个数组来存成绩，这样排序的时候能够有快捷方法

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct Student{
	int id;
	int grade[4];
}stu[2010];

int now;//得是全局变量

int Rank[1000000][4] = { 0 };//放在主函数内不行，是因为太大了吗？

bool cmp(Student a, Student b){
	return a.grade[now] > b.grade[now];
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);//注意存放位置
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) * 1.0 / 3);//四舍五入函数cmath
	}

	
	

	for (now = 0; now < 4; now++){
		sort(stu, stu + n, cmp);

		Rank[stu[0].id][now] = 1;
		for (int i = 1; i < n; i++){
			if (stu[i].grade[now] == stu[i - 1].grade[now])
				Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
			else
				Rank[stu[i].id][now] = i + 1;
		}

	}

	int query;

	char change[4] = { 'A', 'C', 'M', 'E' };//下标对应字符

	for (int i = 0; i < m; i++){
		scanf("%d", &query);
		if (Rank[query][0] == 0)
			printf("N/A\n");
		else{
			int k = 0;//不仅要找最小值，还要最小值小标，所以设序号
			for (int j = 0; j < 4; j++){
				if (Rank[query][j] < Rank[query][k]){
					k = j;
				}
			}
			printf("%d %c\n", Rank[query][k], change[k]);
		}
	}



	return 0;
}