//A1080

//�ṹ�������ѧ����id���ɼ���־Ը��������֮���������ѧУ���棬
//ѧУ�����ýṹ��ʵ�֣�������Ҫ���Ѿ���ȥ��ѧ��������Ҫ�����ѧ����������������vector�졣
//��������Ҫ���������

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
		stu[i].sum = stu[i].GE + stu[i].GI;//����ƽ������ֱ�Ӻ;�����
		for (int j = 0; j < k; j++){
			scanf("%d", &stu[i].zhiyuan[j]);
		}
	}

	sort(stu, stu + n, cmp);

	stu[0].rank = 1;
	for (int i = 1; i < n; i++){
		if (stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE)
			stu[i].rank = stu[i - 1].rank;//���ܷ���ͬ������
		else
			stu[i].rank = i + 1;
	}

	for (int i = 0; i < n; i++){//������ȥ
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
			for (int j = 0; j < school[i].size(); j++){//	��ʵҲ������һ��iterator����
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
