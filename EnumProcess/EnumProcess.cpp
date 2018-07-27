// EnumProcess.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <process.h>
#include <TlHelp32.h>
bool CheckDebug_EnumProcess() {
	PROCESSENTRY32 pe32 = { sizeof(pe32) };
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}
	Process32First(hProcessSnap, &pe32);
	do
	{
		// ����ֻ�Ƚ���OllyDbg,Ҳ������������ĵ��Է���������
		if (_tcsicmp(pe32.szExeFile, TEXT("OllyDbg.exe")) == 0)
		{
			CloseHandle(hProcessSnap);
			return TRUE;
		}
	} while (Process32Next(hProcessSnap, &pe32));
	CloseHandle(hProcessSnap);
	return FALSE;
}

int main()
{
	if (CheckDebug_EnumProcess())
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