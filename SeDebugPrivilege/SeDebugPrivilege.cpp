// SeDebugPrivilege.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <TlHelp32.h>


bool CheckDebug_SeDebugPrivilege() {
	// ��ȡCsrGetProcessId������ַ
	HMODULE hMod = GetModuleHandle(L"ntdll.dll");
	typedef int(*CSRGETPROCESSID)();
	CSRGETPROCESSID CsrGetProcessId = (CSRGETPROCESSID)GetProcAddress(hMod, "CsrGetProcessId");
	// ��ȡcsrss.exe��PID
	DWORD pid = CsrGetProcessId();
	// �򿪳ɹ�˵������Ա+����Ȩ��
	HANDLE hCsr = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
	if (!hCsr)
	{
		return false;
	}
	CloseHandle(hCsr);
	return true;
}


BOOL CheckDebug_EnumProcess_Csrss()
{
	DWORD pid=0;
	DWORD ret = 0;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}
	Process32First(hProcessSnap, &pe32);
	do
	{
		if (wcscmp(pe32.szExeFile, L"csrss.exe") == 0)
		{
			pid = pe32.th32ProcessID;
			break;
		}
	} while (Process32Next(hProcessSnap, &pe32));
	CloseHandle(hProcessSnap);
	HANDLE hCss = OpenProcess(PROCESS_QUERY_INFORMATION, NULL, pid);
	if (!hCss)
	{
		return FALSE;
	}
	CloseHandle(hCss);
	return FALSE;
}

int main()
{
	if (CheckDebug_SeDebugPrivilege())
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
