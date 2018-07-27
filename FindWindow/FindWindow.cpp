// FindWindow.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
bool CheckDebug_FindWindow() {
	// OD������������Ϊ OLLYDBG��Ҳ���Բ�ѯ����������������
	// �������õ���������������ʹ��Spy++�鿴
	if (FindWindow(TEXT("OLLYDBG"), NULL))
		return true;
	return false;
}
BOOL CALLBACK EnumWindowProc(HWND hWnd, LPARAM lParam) {
	TCHAR winTitle[0x100] = {};
	GetWindowText(hWnd, winTitle, 0x100);
	if (_tcsstr(winTitle, TEXT("OllyDbg")))
	{
		// nFind=true
		*((int*)lParam) = true;
		// �ҵ�Ŀ�괰��ֹͣ����
		return false;
	}
	// ����������һ������
	return true;
}
bool CheckDebug_EnumWindow() {
	int nFind = false;
	EnumWindows(EnumWindowProc, (LPARAM)&nFind);
	return nFind != 0;
}
int main()
{
	if (CheckDebug_EnumWindow())
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
