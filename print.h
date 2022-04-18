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
		fprintf(text, "%s ", s[data[i]]);	//파일에 쓰기
		printf("%s ", s[data[i]]);			//콘솔에 출력
	}
	fprintf(text, "\n");					//줄바꿈
	printf("\n");							//줄바꿈
}

void Permutation(int N, int depth, FILE* text)
{
	int i;

	if (N == depth) {
		print(N, text);
		return;
	}

	for (i = depth; i < N; i++) {
		swap(&data[i], &data[depth]);		//초기 배열 스왑
		Permutation(N, depth + 1, text);	//depth를 깊게 들어가며 재귀
		swap(&data[i], &data[depth]);		//스왑 복구
	}
}

#endif // !PRINT_H
