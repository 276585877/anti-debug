// QueryPerformanceCounter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
bool CheckDebug_QueryPerformanceCounter() {
	LARGE_INTEGER startTime , endTime ;
	QueryPerformanceCounter(&startTime);
	printf("���Ǻ��Ĵ���\nҲ�����Ǻ��Ĵ���ǰ�ķ�����ʱ�������\n");
	QueryPerformanceCounter(&endTime);
	printf("%llx\n", endTime.QuadPart - startTime.QuadPart);
	return endTime.QuadPart - startTime.QuadPart > 0x500;
}

int main()
{
	if (CheckDebug_QueryPerformanceCounter())
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

