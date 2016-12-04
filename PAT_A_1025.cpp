#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct Student{
	char id[14];
	int score;
	int locNum;    
	int locRank;
	int totalRank;
}stu[30010];

bool cmp(Student a, Student b){
	if (a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.id, b.id) < 0;
}

int main(){
	int n, m, num = 0;
	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &m);
		for (int j = 0; j < m; j++){
			scanf("%s %d", &stu[num].id, &stu[num].score);
			stu[num].locNum = i;
			num++;
		}

		sort(stu + num - m, stu + num, cmp);

		stu[num - m].locRank = 1;
		for (int j = num - m + 1; j < num; j++){
			if (stu[j].score == stu[j - 1].score)
				stu[j].locRank = stu[j - 1].locRank;
			else
				stu[j].locRank = j + 1 - (num - m);
		}
	}

	sort(stu, stu + num, cmp);
	stu[0].totalRank = 1;
	for (int i = 1; i < num; i++){
		if (stu[i].score == stu[i - 1].score)
			stu[i].totalRank = stu[i-1].totalRank;
		else{
			stu[i].totalRank = i + 1;
		}
	}

	printf("%d\n", num);
	for (int i = 0; i < num; i++){
		printf("%s %d %d %d\n", stu[i].id, stu[i].totalRank, stu[i].locNum, stu[i].locRank);
	}

	return 0;
}