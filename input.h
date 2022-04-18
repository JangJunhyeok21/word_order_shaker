#ifndef INPUT_H
#define INPUT_H

#include "global.h"

int Input() {
	int n = 0, len = 0, count = 0, id = 0;
	char sentence[LENGTH]; //문장을 입력 받을 곳. 한글 기준 50자 내외

	printf("섞을 문장을 입력하세요.(배치 단위 구분은 '/'로 합니다. Ctrl+c입력 시 프로그램 종료.)\n>> ");
	gets_s(sentence,sizeof(sentence)), printf("\n"); //문장 입력 받음.

	//음절 및 어절 카운팅ㄱ
	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] == '/' || sentence[i] == '\n') {
			n++;					//어절 수 세기
			if (len < count) {		//음절 최댓값
				len = count;
			}
			count = 0;
			continue;
		}
		count++;					//음절 수 세기(단위 : 바이트)
	}
	n++;							//어절 수 세기
	if (len < count) {				//음절 최댓값
		len = count;
	}


	data = (int*)malloc(n * sizeof(int));	//인덱스 배열 할당
	s = (char**)malloc(n * sizeof(char*));	//문자열 배열 할당
	//2차원 배열 할당ㄱ
	for (int i = 0; i < n; i++) {
		s[i] = (char*)malloc(len + 1);		//음절 배열 할당
	}

	for (int i = 0; i < n; i++)
		*(data + i) = i;					//인덱스 배열 초기화(1,2,3,...)

	char* temp = strtok(sentence, "/");		// 공백 문자열을 기준으로 문자열을 자름
	while (temp != NULL) {
		strcpy(s[id], temp);				// 문자열을 자른 뒤 메모리 주소를 문자열 포인터 배열에 저장
		id++;								// 인덱스 증가
		temp = strtok(NULL, "/");			// 다음 문자열을 잘라서 포인터를 반환
	}
	return n;
}

#endif // !INPUT_H
