#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> //윈32 API
#include <locale.h> //지역설정
#pragma warning(disable:4996)
#define SIZE 100
#define MAX_LEN 1024

int* data; //조합 세팅을 위한 정수 배열
char** s; //문자열 저장 배열

const char* getUserName() {
	DWORD dwsize = MAX_LEN;
	CHAR strUserName[MAX_LEN] = { 0, };
	INT nError = GetUserName(strUserName, &dwsize);
	char nonWcUserName[31]; //Windows의 사용자 이름에는 최대 30자를 사용할 수 있습니다.
	int last;

	if (!nError)
	{
		printf("에러코드 : %d\n", GetLastError());
		exit(0); //에러 발생 시 에러코드 출력 후 종료.
	}

	setlocale(LC_ALL, "Korean");//로케일 설정
	last = wcstombs(nonWcUserName, strUserName, 100);//유니코드 스트링을 멀티바이트 스트링으로 변환
	nonWcUserName[last] = 0;//종료 문자열 설정

	return nonWcUserName;
}

void swap(int* i, int* j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

void print(int N, FILE* text) {
	for (int i = 0; i < N; i++) {
		fprintf(text, "%s ", s[data[i]]);
		printf("%s ", s[data[i]]);
	}
	fprintf(text, "\n");
	printf("\n");
}

void Permutation(int N1, int N2, int depth, FILE* text)
{
	int i;

	if (N2 == depth) {
		print(N1, text);
		return;
	}

	for (i = depth; i < N2; i++) {
		swap(&data[i], &data[depth]);
		Permutation(N1, N2, depth + 1, text);
		swap(&data[i], &data[depth]);
	}
}

int Input() {
	int n = 0, len = 0, count = 0, id = 0;
	char sentence[SIZE]; //문장을 입력 받을 곳. 한글 기준 50자 내외

	printf("섞을 문장을 입력하세요.(단위 구분은 '/'로 합니다.)\n>> ");
	gets(sentence), printf("\n"); //문장 입력 받음.

	//음절 및 어절 카운팅ㄱ
	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] == '/' || sentence[i] == '\n') {
			n++; //어절 수 세기
			if (len < count) { //음절 최댓값
				len = count;
			}
			count = 0;
			continue;
		}
		count++; //음절 수 세기(단위 : 바이트)
	}
	n++; //어절 수 세기
	if (len < count) { //음절 최댓값
		len = count;
	}


	data = (int*)malloc(n * sizeof(int)); //인덱스 배열 할당
	s = (char**)malloc(n * sizeof(char*));
	//2차원 배열 할당ㄱ
	for (int i = 0; i < n; i++) {
		s[i] = (char*)malloc(len + 1);
	}

	for (int i = 0; i < n; i++)
		*(data + i) = i; //인덱스 배열 초기화(1,2,3,...)

	char* temp = strtok(sentence, "/"); // 공백 문자열을 기준으로 문자열을 자름
	while (temp != NULL) {
		strcpy(s[id], temp); // 문자열을 자른 뒤 메모리 주소를 문자열 포인터 배열에 저장
		id++; // 인덱스 증가
		temp = strtok(NULL, "/"); // 다음 문자열을 잘라서 포인터를 반환
	}
	return n;
}

void main()
{
	char path[255] = "\0";
	sprintf(path, "C:/Users/%s/Desktop/order_shaker.txt", getUserName());
	printf("파일 경로 : %s\n\n", path);

	FILE* txt;
	if ((txt = fopen(path, "w")) == NULL) {
		printf("파일 열기 실패");
		return;
	}

	int n; //어절 수 변수
	n = Input();
	Permutation(n, n, 0, txt); //조합 및 출력 시작

	fclose(txt);
	//동적할당 해제ㄱ
	free(data);
	for (int i = 0; i < n; i++) {
		if (s[i] != NULL)
			free(s[i]);
	}
	free(s);

	system("pause");
}