#ifndef PATH_H
#define PATH_H

#include <stdio.h>
#include <Windows.h> //윈32 API
#include <locale.h> //지역설정
#define MAX_LEN 1024

const char* getUserName() {
	DWORD dwsize = MAX_LEN;
	CHAR strUserName[MAX_LEN] = { 0, };
	INT nError = GetUserName((LPWSTR)strUserName, &dwsize);
	char nonWcUserName[31]; //Windows의 사용자 이름에는 최대 30자를 사용할 수 있습니다.
	int last;

	if (!nError) //에러 발생 시
	{
		printf("에러코드 : %d\n", GetLastError()); //에러코드 출력
		exit(0); //프로그램 종료
	}

	setlocale(LC_ALL, "Korean");//지역 설정
	last = wcstombs(nonWcUserName, (const wchar_t*)strUserName, 100);//유니코드 스트링을 멀티바이트 스트링으로 변환
	nonWcUserName[last] = 0;//종료 문자열 설정

	return nonWcUserName; //멀티바이트 문자열 반환
}

#endif // !PATH_H

