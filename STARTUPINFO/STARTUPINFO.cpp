// STARTUPINFO.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
bool CheckDebug_STARTUPINFO() {
	STARTUPINFO si = {};
	GetStartupInfo(&si);
	if (si.dwX || si.dwY || si.dwXSize || si.dwYSize)
	{
		printf("%x %x %x %x\n", si.dwX, si.dwY, si.dwXSize, si.dwYSize);
		return true;
	}
	return false;
}

int main()
{
	if (CheckDebug_STARTUPINFO())
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
