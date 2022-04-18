#ifndef INPUT_H
#define INPUT_H

#include "global.h"

int Input() {
	int n = 0, len = 0, count = 0, id = 0;
	char sentence[LENGTH]; //������ �Է� ���� ��. �ѱ� ���� 50�� ����

	printf("���� ������ �Է��ϼ���.(��ġ ���� ������ '/'�� �մϴ�. Ctrl+c�Է� �� ���α׷� ����.)\n>> ");
	gets_s(sentence,sizeof(sentence)), printf("\n"); //���� �Է� ����.

	//���� �� ���� ī���ä�
	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] == '/' || sentence[i] == '\n') {
			n++;					//���� �� ����
			if (len < count) {		//���� �ִ�
				len = count;
			}
			count = 0;
			continue;
		}
		count++;					//���� �� ����(���� : ����Ʈ)
	}
	n++;							//���� �� ����
	if (len < count) {				//���� �ִ�
		len = count;
	}


	data = (int*)malloc(n * sizeof(int));	//�ε��� �迭 �Ҵ�
	s = (char**)malloc(n * sizeof(char*));	//���ڿ� �迭 �Ҵ�
	//2���� �迭 �Ҵ礡
	for (int i = 0; i < n; i++) {
		s[i] = (char*)malloc(len + 1);		//���� �迭 �Ҵ�
	}

	for (int i = 0; i < n; i++)
		*(data + i) = i;					//�ε��� �迭 �ʱ�ȭ(1,2,3,...)

	char* temp = strtok(sentence, "/");		// ���� ���ڿ��� �������� ���ڿ��� �ڸ�
	while (temp != NULL) {
		strcpy(s[id], temp);				// ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ����
		id++;								// �ε��� ����
		temp = strtok(NULL, "/");			// ���� ���ڿ��� �߶� �����͸� ��ȯ
	}
	return n;
}

#endif // !INPUT_H
