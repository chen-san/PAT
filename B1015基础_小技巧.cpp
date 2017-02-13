//B1015

//������������⣬����Ҫ��һ���ࡣ
//�ұ�������ʱ�򣬰�ÿһ���඼����һ��vector���棬��������������ʵû�б�Ҫ��
//��struct������һ��flag������ǰ�������Сһ��,һ���ŵ����ˣ������ˡ�
//���ڲ����������ģ�flag��Ϊ��������ʱ����������ˡ������ö���Ŀռ俪����

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student{
	char id[10];//��Ŀ��û�и�����������ж೤
	int de, cai, sum;
	int flag;//�ؼ�˼��
}stu[100010];

bool cmp(Student a, Student b){
	if (a.flag != b.flag) return a.flag < b.flag;
	else if (a.sum != b.sum) return a.sum > b.sum;
	else if (a.de != b.de) return a.de > b.de;
	else return strcmp(a.id, b.id) < 0;//�����ַ���һ��ʼ����ֱ�ӱȽ��ˣ�����û���⣬�������г����⣬ֻ����strcmp������
}

int main(){
	int n, L, H;
	scanf("%d%d%d", &n, &L, &H);

	int cnt = n;
	for (int i = 0; i < n; i++){//������ߴ���,��ʵ���Ƿָ���
		scanf("%s%d%d", stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].cai + stu[i].de;
		if (stu[i].cai < L || stu[i].de < L){
			stu[i].flag = 5;
			cnt--;//����������㿪ʼ���ģ��������ֻ��Ǵ�n���¼�����
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