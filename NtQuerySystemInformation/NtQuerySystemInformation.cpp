// NtQuerySystemInformation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <winternl.h>
#pragma comment(lib,"ntdll.lib")
bool CheckDebug_KernelDebug() {
	struct _SYSTEM_KERNEL_DEBUGGER_INFORMATION
	{
		BOOLEAN DebuggerEnabled;
		BOOLEAN DebuggerNotPresent;
	}DebuggerInfo = { 0 };
	NtQuerySystemInformation(
		(SYSTEM_INFORMATION_CLASS)0x23,		//��ѯ��Ϣ����
		&DebuggerInfo,						//�����ѯ��Ϣ
		sizeof(DebuggerInfo),				//��ѯ���ʹ�С
		NULL);								//ʵ�ʷ������ݴ�С
	return DebuggerInfo.DebuggerEnabled;
}

int main()
{
	if (CheckDebug_KernelDebug())
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


