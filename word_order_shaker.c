#include "input.c"		//사용자 입력 관련 코드
#include "path.c"		//바탕화면 절대경로 추출
#include "print.c"		//콘솔 및 TXT 출력
#include "global.h"		//전역변수 및 공통 헤더파일 헤더

void main()
{
	char path[255] = "\0";
	sprintf(path, "C:/Users/%s/Desktop/order_shaker.txt", getUserName());	//유저네임 추출 후 절대경로에 삽입
	printf("파일 경로 : %s\n\n", path);										//파일 경로 안내

	FILE* txt;
	if ((txt = fopen(path, "w")) == NULL) { //파일 포인터값이 NULL일때
		printf("파일 열기 실패");			//오류메시지 출력 후 종료
		return;
	}

	int n; //어절 수 변수
	n = Input(); //입력 및 어절 수 반환받기
	Permutation(n, 0, txt); //조합 및 출력 시작

	fclose(txt); //파일 닫기
	//동적할당 해제ㄱ
	free(data);
	for (int i = 0; i < n; i++) {
		if (s[i] != NULL)
			free(s[i]);
	}
	free(s);

	system("pause");
}