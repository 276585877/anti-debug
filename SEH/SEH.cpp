// SEH.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

bool CheckDebug_SEH() {
	BOOL bDebugging = FALSE;
	__asm {
		// install SEH
		push handler
		push DWORD ptr fs : [0]
		mov DWORD ptr fs : [0], esp
		__emit(0xcc)
		// ֻ������޵�����
		// ����mov bDebugging, 1�ĳ�__emit(0xE9)
		// �ڵ������оͻ��ܷ�
		mov bDebugging, 1
		jmp normal_code
handler :
		mov eax, dword ptr ss : [esp + 0xc];// ContextRecord
		mov dword ptr ds : [eax + 0xb8], offset normal_code
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
	if (CheckDebug_SEH())
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