#ifndef PATH_H
#define PATH_H

#include <stdio.h>
#include <Windows.h> //��32 API
#include <locale.h> //��������
#define MAX_LEN 1024

const char* getUserName() {
	DWORD dwsize = MAX_LEN;
	CHAR strUserName[MAX_LEN] = { 0, };
	INT nError = GetUserName((LPWSTR)strUserName, &dwsize);
	char nonWcUserName[31]; //Windows�� ����� �̸����� �ִ� 30�ڸ� ����� �� �ֽ��ϴ�.
	int last;

	if (!nError) //���� �߻� ��
	{
		printf("�����ڵ� : %d\n", GetLastError()); //�����ڵ� ���
		exit(0); //���α׷� ����
	}

	setlocale(LC_ALL, "Korean");//���� ����
	last = wcstombs(nonWcUserName, (const wchar_t*)strUserName, 100);//�����ڵ� ��Ʈ���� ��Ƽ����Ʈ ��Ʈ������ ��ȯ
	nonWcUserName[last] = 0;//���� ���ڿ� ����

	return nonWcUserName; //��Ƽ����Ʈ ���ڿ� ��ȯ
}

#endif // !PATH_H

