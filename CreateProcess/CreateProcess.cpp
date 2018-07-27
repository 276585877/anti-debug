// CreateProcess.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<windows.h>

int main()
{
	// ���Դ򿪻����壬ȷ���Ƿ��״����г���
	HANDLE hMutex = OpenMutex(MUTEX_MODIFY_STATE, FALSE, L"Global\\MyMutex");
	if (hMutex)
	{
		// �򿪳ɹ�˵����2�����У�ִ����������
		printf("�����������У�\n");
		getchar();
	}
	else
	{
		// ��ʧ��˵����1�����У����������壬�����Դ����������
		CreateMutex(NULL, FALSE, L"Global\\MyMutex");
		TCHAR szPath[MAX_PATH] = {};
		GetModuleFileName(NULL, szPath, MAX_PATH);
		// ���Է�ʽ�򿪳���
		STARTUPINFO si = { sizeof(STARTUPINFO) };
		PROCESS_INFORMATION pi = {};
		BOOL bStatus = CreateProcess(szPath, NULL, NULL, NULL, FALSE,
			DEBUG_PROCESS | DEBUG_ONLY_THIS_PROCESS | CREATE_NEW_CONSOLE,
			NULL, NULL, &si, &pi);
		if (!bStatus) {
			printf("�������Խ���ʧ��!\n");
			return 0;
		}
		// ��ʼ�������¼��ṹ��
		DEBUG_EVENT DbgEvent = { 0 };
		DWORD dwState = DBG_EXCEPTION_NOT_HANDLED;
		// �ȴ�Ŀ��Exe���������¼�
		BOOL bExit = FALSE;
		while (!bExit) {
			WaitForDebugEvent(&DbgEvent, INFINITE);
			if (DbgEvent.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT)
			{
				// �����Խ����˳�
				bExit = TRUE;
			}
			ContinueDebugEvent(DbgEvent.dwProcessId, DbgEvent.dwThreadId, dwState);
		}
		return 0;
	}
    return 0;
}

