//B1004

//��һ���ṹ��洢ѧ����������ѧ�š��������ýṹ�������洢��Щ���ݡ�Ȼ�����ÿ��ŵõ������С

//����������͵�������������ŵ�ʱ�临�Ӷ���nlogn��û��Ҫ������һ�µõ������С��ʱ�临�Ӷ�ֻ��n��

//�����ټ�㣬��ʵ���������������ֱ�ӱ�����ߴ����ñ���max��min����¼���ˡ������ռ临�Ӷȶ�ʡ�ˡ�

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
		scanf("%s%s%d", &temp.name, &temp.id, &temp.score);//%s�����ո���Զ�ֹͣ����������д
		if (temp.score < min.score) min = temp;//�ṹ����ֱ�Ӹ�ֵ
		if (temp.score > max.score) max = temp;
	}

	printf("%s %s\n", max.name, max.id);
	printf("%s %s\n", min.name, min.id);

	return 0;
}