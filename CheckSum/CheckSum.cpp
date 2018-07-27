// CheckSum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
bool CheckDebug_Checksum()
{
	BOOL bDebugging = FALSE;
	__asm {
		call CHECKBEGIN
CHECKBEGIN:
		pop esi
		mov ecx, 0x15           // ecx : loop count
		xor eax, eax            // eax : checksum
		xor ebx, ebx

_CALC_CHECKSUM :
		movzx ebx, byte ptr ds : [esi]
		add eax, ebx
		rol eax, 1
		inc esi
		loop _CALC_CHECKSUM
		cmp eax, 0x1859a602
		je _NOT_DEBUGGING
		mov bDebugging, 1
_NOT_DEBUGGING:
	}
	return bDebugging;
}
int main()
{
	if (CheckDebug_Checksum())
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
