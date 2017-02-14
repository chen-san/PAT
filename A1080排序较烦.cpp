//A1080

//结构体里面存学生的id、成绩和志愿，排完序之后遍历塞进学校里面，
//学校可以用结构体实现，但是又要有已经进去的学生数，还要有最后学生的排名，还是用vector快。
//最后输出还要按序号排序

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Student{
	int id;
	int GE, GI;
	int sum;
	int rank;
	int zhiyuan[6];
}stu[40010];

bool cmp(Student a, Student b){
	if (a.sum != b.sum) return a.sum > b.sum;
	else return a.GE > b.GE;
}

bool cmpid(Student a, Student b){
	return a.id < b.id;
}

vector<Student> school[110];

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	int  schRL[110];
	for (int i = 0; i < m; i++){
		scanf("%d", schRL + i);
	}

	for (int i = 0; i < n; i++){
		scanf("%d%d", &stu[i].GE, &stu[i].GI);
		stu[i].id = i;
		stu[i].sum = stu[i].GE + stu[i].GI;//不用平均数，直接和就行了
		for (int j = 0; j < k; j++){
			scanf("%d", &stu[i].zhiyuan[j]);
		}
	}

	sort(stu, stu + n, cmp);

	stu[0].rank = 1;
	for (int i = 1; i < n; i++){
		if (stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE)
			stu[i].rank = stu[i - 1].rank;//光总分相同还不够
		else
			stu[i].rank = i + 1;
	}

	for (int i = 0; i < n; i++){//遍历过去
		for (int j = 0; j < k; j++){
			if (school[stu[i].zhiyuan[j]].size() < schRL[stu[i].zhiyuan[j]] \
				|| school[stu[i].zhiyuan[j]].back().rank == stu[i].rank){
				school[stu[i].zhiyuan[j]].push_back(stu[i]);
				break;
			}
		}
	}

	for (int i = 0; i < m; i++){
		if (school[i].size() == 0)
			printf("\n");
		else{
			sort(school[i].begin(), school[i].end(), cmpid);
			for (int j = 0; j < school[i].size(); j++){//	其实也可以设一个iterator遍历
				printf("%d", school[i][j].id);
				if (j != school[i].size() - 1)
					printf(" ");
				else
					printf("\n");
			}
		}
	}

	return 0;
}
