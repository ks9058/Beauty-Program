#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen 함수가 선언된 헤더 파일
#include<stdlib.h> //system()함수가 선언된 헤더 파일이며, #include<stdio.h>의 아랫줄에 삽입
#include <windows.h>

void mainmenu();//미용실 고객 관리 서비스 메뉴, 메인화면

void menu1();//고객정보관리 메뉴
void menu2();//고객추가 메뉴
void menu3();//결제 및 서비스 메뉴

void menu1_1();//전체 고객 정보 보기
void menu1_2();//고객 정보 검색
void menu1_3();//고객 정보 수정

void menu3_1();//결제 및 적립
void menu3_2();//서비스 사용 

void loader();//저장된 값 불러오기 함수
void save(int key, char scan1[15], char scan2[5], int point);//고객 정보 입력 및 수정 시 정보 저장 함수

int keyfind();//사용자가 입력한 키번호로 고객 정보 찾는 함수
int find();//이름 또는 전화번호로 고객 정보를 찾는 함수

int check(int m);//메뉴확인 함수
int yn();//예/아니요 함수

int menu; // 메뉴 이동시 번호를 담는 변수

FILE* fp;


int k;// 파일에서 받아오는것으로 시작해야함			

//고객 정보 구조체
typedef struct {
	int key;// 키번호
	char name[15];// 이름
	char number[5]; //전화번호
	int point;//포인트
}inform;


inform cus[100];//고객 구조체 배열, 100명 할당



int main(void)
{
	loader();

	//메인함수에서 메뉴 실행	
	while (1)
	{

		mainmenu();// 미용실 고객관리 서비스입니다. 후 메뉴 띄우기

		break;
	}
	printf("****************************************************************************************************\n");
	printf("프로그램 종료\n");
	printf("****************************************************************************************************\n");

	fseek(fp, 0, SEEK_SET);
	fprintf(fp, "%d", k);
	fclose(fp);

	return 0;
}


// V
void mainmenu()
{
	while (1)
	{
		system("cls");
		printf("****************************************************************************************************\n");
		printf("미용실 고객 관리 서비스입니다.\n");
		printf("****************************************************************************************************\n");
		printf("0. 나가기\n");
		printf("1. 고객정보관리\n");
		printf("2. 고객추가\n");
		printf("3. 결제 및 서비스\n");
		printf("****************************************************************************************************\n");


		menu = check(0);

		if (menu == 0)
		{
			break;
		}
		else if (menu == 1)
		{
			menu1();
		}
		else if (menu == 2)
		{
			menu2();
		}
		else if (menu == 3)
		{
			menu3();
		}
	}
}


//V
void menu1()
{

	printf("****************************************************************************************************\n");
	printf("고객정보관리 메뉴입니다.\n");
	printf("****************************************************************************************************\n");
	printf("0. 뒤로가기\n");
	printf("1. 전체 고객정보 보기\n");
	printf("2. 고객정보 검색\n");
	printf("3. 고객정보 수정\n");
	printf("****************************************************************************************************\n");


	while (1)
	{
		menu = check(10);

		if (menu == 10)
		{
			break;
		}
		else if (menu == 11)
		{
			menu1_1();
		}
		else if (menu == 12)
		{
			menu1_2();
		}
		else if (menu == 13)
		{
			menu1_3();
		}
		break;
	}

}


//V
void menu2()
{
	char scan1[15];
	char scan2[5];
	printf("****************************************************************************************************\n");
	printf("고객추가 메뉴입니다.\n");
	printf("****************************************************************************************************\n");
	printf("새로 추가하실 고객의 이름:");
	getchar();
	scanf("%s", scan1);
	printf("새로 추가하실 고객의 전화번호 뒷자리:");
	getchar();
	scanf("%s", scan2);;
	printf("****************************************************************************************************\n");
	printf("입력하신 고객의 정보\n");
	printf("이름:%s \n", scan1);
	printf("전화번호 뒷자리:%s", scan2);
	printf("\n");

	while (1)
	{
		printf("****************************************************************************************************\n");
		if (yn() == 0)
		{


			printf("취소되었습니다.\n");
			printf("****************************************************************************************************\n");
			system("pause");
			break;
		}
		else
		{
			save(k, scan1, scan2, 2);

			printf("입력하신 정보가 저장 되었습니다.\n");
			printf("****************************************************************************************************\n");
			system("pause");
			break;
		}
	}
}


//V
void menu3()
{
	printf("****************************************************************************************************\n");
	printf("결제 및 서비스 메뉴입니다.\n");
	printf("****************************************************************************************************\n");
	printf("0. 뒤로가기\n");
	printf("1. 결제 및 적립\n");
	printf("2. 서비스 사용\n");
	printf("****************************************************************************************************\n");

	while (1)
	{
		menu = check(30);


		if (menu == 30)
		{
			break;
		}
		else if (menu == 31)
		{
			menu3_1();
		}
		else if (menu == 32)
		{
			menu3_2();
		}
		break;
	}
}



//V
void menu1_1()
{
	int cnt = 0;
	printf("****************************************************************************************************\n");
	printf("전체 고객 정보입니다.\n");
	printf("****************************************************************************************************\n");


	for (int i = 0; i < sizeof(cus) / sizeof(inform); i++)
	{
		if (cus[i].number[0] > 0)
		{
			printf("KEY: %03d 이름: %s / 전화번호 뒷자리: %s / 포인트: %d\n", i + 1, cus[i].name, cus[i].number, cus[i].point);
			cnt++;
		}
	}
	if (cnt < 1)
	{
		printf("저장된 정보가 없습니다.\n");
	}

	printf("****************************************************************************************************\n");
	system("pause");
}


//V
void menu1_2()
{

	printf("****************************************************************************************************\n");
	printf("고객 정보 검색 메뉴입니다.\n");
	printf("****************************************************************************************************\n");
	printf("고객의 이름 또는 전화번호 뒷자리를 입력하세요:");
	find();
	printf("****************************************************************************************************\n");
	system("pause");
}



void menu1_3()
{
	int keynum = 0;
	char scan1[15];
	char scan2[5];
	printf("****************************************************************************************************\n");
	printf("고객 정보 수정 메뉴입니다.\n");
	printf("****************************************************************************************************\n");
	printf("수정하실 고객의 이름 또는 전화번호 뒷자리를 입력하세요:");

	if (find() == 0)
	{
		printf("****************************************************************************************************\n");
		system("pause");
	}
	else {
		printf("****************************************************************************************************\n");
		printf("수정하실 고객님의 키번호를 입력하세요:");

		keynum = keyfind();

		printf("수정할 고객의 이름을 입력하세요:");
		getchar();
		scanf("%s", scan1);
		printf("수정할 고객의 전화번호 뒷자리를 입력하세요:");
		getchar();
		scanf("%s", scan2);
		printf("****************************************************************************************************\n");
		printf("수정 전 이름:%s \n", cus[keynum].name);
		printf("수정 전 전화번호 뒷자리:%s\n", cus[keynum].number);
		printf("****************************************************************************************************\n");
		printf("수정 후 이름:%s \n", scan1);
		printf("수정 후 전화번호 뒷자리:%s\n", scan2);
		printf("위 사항으로 수정 하시겠습니까?\n");
		printf("****************************************************************************************************\n");


		while (1)
		{
			if (yn() == 1)
			{

				save(keynum, scan1, scan2, 13);

				printf("수정되었습니다.\n");
				printf("****************************************************************************************************\n");
				system("pause");
				break;
			}
			else
			{
				printf("취소되었습니다.\n");
				printf("****************************************************************************************************\n");
				system("pause");
				break;
			}
		}

	}

}





void menu3_1()
{

	int keynum = 0;

	printf("****************************************************************************************************\n");
	printf("결제 및 적립을 위해 이름 또는 전화번호 뒷자리를 입력해주세요:");


	if (find() == 0)
	{
		printf("****************************************************************************************************\n");
		system("pause");
	}
	else
	{
		printf("****************************************************************************************************\n");
		printf("적립할 고객의 키번호를 입력하세요:");
		keynum = keyfind();


		printf("KEY: %03d 이름: %s / 전화번호 뒷자리: %s / 포인트: %d\n", cus[keynum].key, cus[keynum].name, cus[keynum].number, cus[keynum].point);
		printf("이 고객에게 적립하시겠습니까?\n");
		printf("****************************************************************************************************\n");

		while (1)
		{
			if (yn() == 1)
			{
				printf("****************************************************************************************************\n");
				save(keynum, 0, 0, 31);
				printf("적립되었습니다.\n");
				printf("KEY: %03d 이름: %s / 전화번호 뒷자리: %s / 포인트: %d\n", cus[keynum].key, cus[keynum].name, cus[keynum].number, cus[keynum].point);
				printf("****************************************************************************************************\n");
				system("pause");
			}
			else
			{
				printf("취소되었습니다.\n");
				printf("****************************************************************************************************\n");
				system("pause");
				break;
			}
		}
	}
}



void menu3_2()
{
	int keynum = 0;

	printf("****************************************************************************************************\n");
	printf("서비스 사용을 위해 이름 또는 전화번호 뒷자리를 입력해주세요:");

	if (find() == 0)
	{
		printf("****************************************************************************************************\n");
		system("pause");
	}
	else
	{
		printf("****************************************************************************************************\n");
		printf("서비스를 사용할 고객의 키번호를 입력하세요:");
		keynum = keyfind();


		printf("KEY: %03d 이름: %s / 전화번호 뒷자리: %s / 포인트: %d\n", cus[keynum].key, cus[keynum].name, cus[keynum].number, cus[keynum].point);
		printf("이 고객의 포인트를 사용하시겠습니까?\n");
		printf("****************************************************************************************************\n");

		while (1)
		{
			if (yn() == 1)
			{
				if (cus[keynum].point >= 10)
				{
					save(keynum, 0, 0, 32);
					printf("사용되었습니다.\n");
					printf("KEY: %03d 이름: %s / 전화번호 뒷자리: %s / 포인트: %d\n", cus[keynum].key, cus[keynum].name, cus[keynum].number, cus[keynum].point);
					printf("****************************************************************************************************\n");
					system("pause");
				}
				else
				{
					printf("포인트가 부족합니다.\n");
					printf("****************************************************************************************************\n");
					system("pause");
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

}

//반환 되는 정수 값으로 메뉴 선택 -> 1page에서 3항목으로 넘어가면 정수 '10' 받아오고 입력값 '3'을 더해서 '13'반환
int check(int m)
{
	int num = 0;


	printf("메뉴를 선택하세요:");



	while (1)
	{

		scanf("%d", &num);


		num = num + m;


		if (num == 0)
		{
			getchar();
			system("cls");
			return 0;
		}
		else if (num == 1)
		{
			system("cls");
			return 1;
		}
		else if (num == 2)
		{
			system("cls");
			return 2;
		}
		else if (num == 3)
		{
			system("cls");
			return 3;
		}
		else if (num == 10)
		{
			system("cls");
			return 10;
		}
		else if (num == 11)
		{
			system("cls");
			return 11;
		}
		else if (num == 12)
		{
			system("cls");
			return 12;
		}
		else if (num == 13)
		{
			system("cls");
			return 13;
		}
		else if (num == 30)
		{
			system("cls");
			return 30;
		}
		else if (num == 31)
		{
			system("cls");
			return 31;
		}
		else if (num == 32)
		{
			system("cls");
			return 32;
		}
		else
		{
			getchar();
			printf("다시 입력하세요:");
		}
	}
}



int yn()
{
	int ch;
	getchar();
	printf("맞으면 1, 틀리면 0을 입력하세요:");

	while (1)
	{
		scanf("%d", &ch);
		if (ch == 1)
			return 1;
		else if (ch == 0)
			return 0;
		else
			printf("다시 입력하세요:");
	}
}


void save(int key, char scan1[15], char scan2[5], int point)
{
	if (point == 2)//고객추가
	{
		strcpy(cus[key].name, scan1);
		strcpy(cus[key].number, scan2);
		cus[key].key = k + 1;
		cus[key].point = 0;

		fprintf(fp, "\n");
		fprintf(fp, "%d %s %s %d ", cus[key].key, cus[key].name, cus[key].number, cus[key].point);

		k++;
	}
	else if (point == 13)//고객수정
	{
		strcpy(cus[key].name, scan1);
		strcpy(cus[key].number, scan2);
	}
	else if (point == 31)//포인트 적립
	{
		cus[key].point++;
	}
	else if (point == 32)//포인트 사용
	{
		cus[key].point = cus[key].point - 10;
	}
}


int find()
{
	int cnt = 0;
	char scan[15];
	scanf("%s", scan);

	printf("****************************************************************************************************\n");
	for (int i = 0; i < sizeof(cus) / sizeof(inform); i++)
	{
		if (strcmp(scan, cus[i].name) == 0)
		{
			printf("KEY: %03d 이름: %s / 전화번호 뒷자리: %s / 포인트: %d\n", i + 1, cus[i].name, cus[i].number, cus[i].point);
			cnt++;
		}
		else if (strcmp(scan, cus[i].number) == 0)
		{
			printf("KEY: %03d 이름: %s / 전화번호 뒷자리: %s / 포인트: %d\n", i + 1, cus[i].name, cus[i].number, cus[i].point);
			cnt++;
		}

	}
	if (cnt >= 1)
	{
		return 1;
	}
	else
	{
		printf("입력하신 정보와 일치하는 고객이 없습니다.\n");
		return 0;
	}
}


int keyfind()
{
	int keynum = 0;
	int check = 0;

	while (1)
	{
		getchar();
		scanf("%d", &keynum);

		for (int i = 0; i < sizeof(cus) / sizeof(inform); i++)
		{
			if ((keynum == cus[i].key) && (keynum > 0) && (keynum <= sizeof(cus) / sizeof(inform)))
			{
				check = keynum - 1;// 입력한 값의 -1이 사용자가 원하는 번호의 배열번호이다.
				return check;
			}
		}
		if (keynum == 0)
		{
			return 0;
		}
		printf("다시입력하세요:");
	}
}

void loader()
{
	char buffer[60];
	char* temp;
	int i = 0;
	int j = 0;
	fp = fopen("고객관리부.txt", "r+");

	//k값 읽기
	while (fgets(buffer, sizeof(buffer), fp) != NULL)//한 줄 읽기
	{
		temp = strtok(buffer, " "); //띄어쓰기를 기준으로 문자열 자르기
		k = atoi(temp);
	}

	//printf("%d", k);
	//system("pause");

	//고객정보 읽기
	if (fp != NULL)
	{
		for (i; i < k; i++)// 고객 수 만큼 반복
		{
			j = 0;
			while (fgets(buffer, sizeof(buffer), fp) != NULL)//한 줄 읽기
			{
				temp = strtok(buffer, " "); //띄어쓰기를 기준으로 문자열 자르기		

				while (temp != NULL)
				{
					if (j == 0)
					{
						cus[i].key = atoi(temp);
						temp = strtok(NULL, " ");
						j++;
					}
					else if (j == 1)//두번째는 이름
					{
						//strcpy(cus[i].name, temp);
						temp = strtok(NULL, " ");
						j++;
					}
					else if (j == 2)//세번째는 전화번호
					{
						//strcpy(cus[i].number, temp);
						temp = strtok(NULL, " ");
						j++;
					}
					else if (j == 3)//네번째는 포인트
					{
						cus[i].point = atoi(temp);
						temp = strtok(NULL, " ");
						j++;
					}

				}
			}
		}
	}
}
