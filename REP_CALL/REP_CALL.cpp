// REP_CALL.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
bool CheckDebug_CheckRepCC()
{
	BOOL bDebugging = FALSE;
	__asm {
		xor eax,eax
		xor ecx,ecx
		inc ecx
		lea esi,key
		// �˴�����ʱkey���ᱻ��0xCC�ϵ�
		// ��key�������ֽڸ�AL
		rep lodsb
key:
		cmp al,0xcc
		je debuging
		jmp over
debuging:
		mov bDebugging,1
over :
	}
	return bDebugging;
}
int main()
{
	if (CheckDebug_CheckRepCC())
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
