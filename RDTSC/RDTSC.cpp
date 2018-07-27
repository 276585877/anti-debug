// RDTSC.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdint.h>
bool CheckDebug_RDTSC() {
	int64_t t1=0, t2=0;
	int lo=0, hi=0;
	__asm {
		rdtsc
		mov [lo], eax
		mov [hi], edx
	}
	t1 = ((int64_t)lo) | ((int64_t)hi << 32);
	__asm{
		rdtsc
		mov[lo], eax
		mov[hi], edx
	}
	t2 = ((int64_t)lo) | ((int64_t)hi << 32);
	printf("t2-t1=%llx\n", t2 - t1);
	// ��ͬ��CPU�ò�ֵ��ͬ�����Խ���ʹ�����ַ����Է���
	return t2 - t1 > 0x100;
}

int main()
{
	if (CheckDebug_RDTSC())
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
