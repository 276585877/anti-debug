// INT 2D.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
bool CheckDebug_INT_2D() {
	BOOL bDebugging = FALSE;
	__asm {
		// install SEH
		push handler
		push DWORD ptr fs : [0]
		mov DWORD ptr fs : [0], esp
		// OD�����0x2d��nop���������ִ��
		// ��ʱ�����ѡ��ֻ�Ǽ������������ܷ�
		int 0x2d
		nop
		mov bDebugging, 1
		jmp normal_code
handler :
		mov eax, dword ptr ss : [esp + 0xc]
		mov dword ptr ds : [eax + 0xb8], offset normal_code
		mov bDebugging, 0
		xor eax, eax
		retn
normal_code :
		//   remove SEH
		pop dword ptr fs : [0]
		add esp, 4
	}
	return bDebugging;
}

int main()
{
	if (CheckDebug_INT_2D())
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
