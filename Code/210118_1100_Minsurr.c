#include<stdio.h>

int main(void) {

	//ü���� �Է��� ���� �迭 ����(Null ����? ������ 9/9�� ����)
	char Arr[9][9];

	//for�� ������ ���� ���� i, j
	int i, j = 0;

	//���ڿ� �Է¹ޱ�
	for(i = 0; i < 8; i++) {
		scanf("%s", &Arr[i][j]);
	}
	
	printf("\n");

	//��� ü���ǿ� ��ġ�� 'F'�� ������ ī�����ϱ� ���� ����
	int cnt = 0;

	//���� index�� 0�� ¦�� �� �� 
	for(i = 0; i < 8; i+=2) {
		for(j = 0; j < 8; j++) {
			//�� index�� �� index�� 0 �Ǵ� ¦�� �� �� ��� ü����
			if(j % 2 == 0 && Arr[i][j] != '.') {
				cnt ++;
			}
		}
	}
	
	//���� index�� Ȧ�� �� ��
	for(i = 1; i < 8; i += 2) {
		for(j = 0; j < 8; j++) {
			//�� index�� �� index�� Ȧ�� �� �� ��� ü����
			if(j % 2 == 1 && Arr[i][j] !='.') {
				cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;

}
