// API���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
bool CheckDebug_API() {
	PBYTE pCC = (PBYTE)MessageBoxW;
	if (*pCC == 0xCC)
	{
		return true;
	}
	MessageBoxW(0, L"δ���ֵ�������\n", 0, 0);
	return false;
}

int main()
{
	if (CheckDebug_API())
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
