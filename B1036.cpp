//B1036

//ͼ������� Ψһ���ѵ����row���У�col���У����������д���ˣ����˲�����

#include<cstdio>

int main(){
	int row, col;
	char c;

	scanf("%d %c", &row, &c);

	col = (row + 1) / 2;//���Զ������������Ŀ�ݷ���

	for (int i = 1; i <= col; i++){
		if (i == 1 || i == col){
			for (int j = 0; j < row; j++){
				printf("%c", c);
			}
			printf("\n");
		}
		else{
			printf("%c", c);
			for (int j = 1; j < row - 1; j++){
				printf(" ");
			}
			printf("%c\n", c);
		}
	}
	return 0;
}
