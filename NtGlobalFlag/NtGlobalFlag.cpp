// NtGlobalFlag.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
bool CheckDebug() {
	int nNtFlag = 0;
	__asm {
		MOV EAX, DWORD PTR FS : [0x30]
		MOV EAX, DWORD PTR DS : [EAX + 0x68]
		MOV nNtFlag, EAX
	}
	return nNtFlag==0x70;
}

int main()
{
	
	if (CheckDebug())
	{
		printf("���ֵ�����\n");
	}
	else
	{
		printf("��������\n");
	}
	getchar();
	return 0;
}