// BeingDebugged.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

bool CheckDebug() {
	bool bDebugged = false;
	__asm {
		MOV EAX, DWORD PTR FS : [0x30]
		MOV AL, BYTE PTR DS : [EAX + 2]
		MOV bDebugged, AL
	}
	return bDebugged;
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


