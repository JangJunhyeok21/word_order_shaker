#ifndef PRINT_H
#define PRINT_H

#include "global.h"

void swap(int* i, int* j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

void print(int N, FILE* text) {
	for (int i = 0; i < N; i++) {
		fprintf(text, "%s ", s[data[i]]);	//���Ͽ� ����
		printf("%s ", s[data[i]]);			//�ֿܼ� ���
	}
	fprintf(text, "\n");					//�ٹٲ�
	printf("\n");							//�ٹٲ�
}

void Permutation(int N, int depth, FILE* text)
{
	int i;

	if (N == depth) {
		print(N, text);
		return;
	}

	for (i = depth; i < N; i++) {
		swap(&data[i], &data[depth]);		//�ʱ� �迭 ����
		Permutation(N, depth + 1, text);	//depth�� ��� ���� ���
		swap(&data[i], &data[depth]);		//���� ����
	}
}

#endif // !PRINT_H
