//A1012

//��ΪҪ����id�����������ٵİ취ʱ��id��Ϊ�±꣬�ռ任ʱ�䣬���ǽṹ������ռ�����̫����һ����������������

//�ṹ��������һ����������ɼ������������ʱ���ܹ��п�ݷ���

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct Student{
	int id;
	int grade[4];
}stu[2010];

int now;//����ȫ�ֱ���

int Rank[1000000][4] = { 0 };//�����������ڲ��У�����Ϊ̫������

bool cmp(Student a, Student b){
	return a.grade[now] > b.grade[now];
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);//ע����λ��
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) * 1.0 / 3);//�������뺯��cmath
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

	char change[4] = { 'A', 'C', 'M', 'E' };//�±��Ӧ�ַ�

	for (int i = 0; i < m; i++){
		scanf("%d", &query);
		if (Rank[query][0] == 0)
			printf("N/A\n");
		else{
			int k = 0;//����Ҫ����Сֵ����Ҫ��СֵС�꣬���������
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