// POP SS.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
bool CheckDebug_PopSS()
{
	bool bDebugged = false;
	__asm {
		push ss
		pop ss
		pushfd
		test BYTE PTR SS : [ESP + 1], 1
		jne debugged
		jmp over
debugged:
		mov bDebugged,1
over:
		popfd
	}
	return bDebugged;
}
int main()
{
	if (CheckDebug_PopSS())
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
