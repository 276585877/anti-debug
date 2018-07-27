// Registry.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
bool CheckDebug_Registry() {
	// �жϵ�ǰϵͳ��32����64λ
	BOOL b64 = FALSE;
	IsWow64Process(GetCurrentProcess(), &b64);
	HKEY hkey = NULL;
	TCHAR *reg = b64 ?
		TEXT("SOFTWARE\\Wow6432Node\\Microsoft\\WindowsNT\\CurrentVersion\\AeDebug")
		: TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AeDebug");
	// ��ע����
	DWORD ret = RegCreateKey(HKEY_LOCAL_MACHINE, reg, &hkey);
	if (ret != ERROR_SUCCESS) return FALSE;
	TCHAR *subkey = TEXT("Debugger");
	TCHAR value[256] = {};
	DWORD len = 256;
	// ��ѯ��Ӧ���ֵ
	ret = RegQueryValueEx(hkey, subkey, NULL,NULL,(LPBYTE)value, &len);
	RegCloseKey(hkey);
	// ����ֻ������OD��Ҳ����ͬʱ����WinDbg,x64Dbg�ȳ��õ�����
	if (_tcsstr(value, TEXT("OLLYDBG")) != NULL)
		return TRUE;
	return FALSE;
}

int main()
{
	if (CheckDebug_Registry())
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
