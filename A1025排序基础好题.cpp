//B1015

//�ұ�������ʱ�����ÿһ����������һ��vector���棬�ֱ�������һ��������ʵû��Ҫ

//���������ʵ��

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student{
	char id[14];
	int score;
	int local;
	int localRank;
	int totalRank;
}stu[30010];

bool cmp(Student a, Student b){
	if (a.score != b.score) return a.score > b.score;
	else return strcmp(a.id, b.id) < 0;
}

int main(){
	int n;
	scanf("%d", &n);

	int m;
	int cnt = 0;//��Ҫ��һ��������
	for (int i = 0; i < n; i++){
		scanf("%d", &m);
		for (int j = 0; j < m; j++){
			scanf("%s%d", stu[cnt].id, &stu[cnt].score);
			stu[cnt].local = i + 1;
			cnt++;
		}

		sort(stu + cnt - m, stu + cnt, cmp);
		stu[cnt - m].localRank = 1;
		for (int j = cnt - m + 1; j < cnt; j++){
			if (stu[j].score == stu[j - 1].score)
				stu[j].localRank = stu[j - 1].localRank;
			else
				stu[j].localRank = j - (cnt - m) + 1;//����Ҫע��һ��
		}
	}

	//������
	sort(stu, stu + cnt, cmp);
	stu[0].totalRank = 1;
	for (int i = 1; i < cnt; i++){
		if (stu[i].score == stu[i - 1].score)
			stu[i].totalRank = stu[i - 1].totalRank;
		else
			stu[i].totalRank = i + 1;
	}

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++){
		printf("%s %d %d %d\n", stu[i].id, stu[i].totalRank, stu[i].local, stu[i].localRank);
	}

	return 0;
}
