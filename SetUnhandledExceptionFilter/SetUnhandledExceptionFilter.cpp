// SetUnhandledExceptionFilter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

LONG WINAPI Fun(
	_In_ struct _EXCEPTION_POINTERS *ExceptionInfo
) {
	// ����mov bDebug, 1����ָ��
	// int 3�쳣ʱ��eip�ᱻ�ز���cc��������Ҫ+5
	ExceptionInfo->ContextRecord->Eip += 5;
	return EXCEPTION_CONTINUE_EXECUTION;
}
bool CheckDebug_SetUnhandledExceptionFilter() {
	bool bDebug = false;
	__asm {
		__emit(0xCC);
		// ��������ʱ��Fun��������������ָ��
		// ����ʱ���������᲻ͣ�յ�int 3�쳣���������
		mov bDebug, 1
	}
	return bDebug;
}
int main()
{
	SetUnhandledExceptionFilter(Fun);
	if (CheckDebug_SetUnhandledExceptionFilter())
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