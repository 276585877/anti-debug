// NtQqueryObject.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <winternl.h>
#pragma comment(lib,"ntdll.lib")
bool CheckDebug_QueryObject() {
	typedef struct _OBJECT_TYPE_INFORMATION
	{
		UNICODE_STRING TypeNames;
		ULONG TotalNumberOfHandles;
		ULONG TotalNumberOfObjects;
	}OBJECT_TYPE_INFORMATION, *POBJECT_TYPE_INFORMATION;
	typedef struct _OBJECT_ALL_INFORMATION
	{
		ULONG NumberOfObjectsTypes;
		OBJECT_TYPE_INFORMATION ObjectTypeInfo[1];
	}OBJECT_ALL_INFORMATION, *POBJECT_ALL_INFORMATION;
	//1.��ȡ����ѯ��Ϣ��С
	ULONG uSize = 0;
	NtQueryObject(NULL, (OBJECT_INFORMATION_CLASS)0x03, &uSize, sizeof(uSize), &uSize);
	//2.��ȡ�������Ϣ
	POBJECT_ALL_INFORMATION pObjectAllInfo = (POBJECT_ALL_INFORMATION) new BYTE[uSize+4];
	NtQueryObject(NULL, (OBJECT_INFORMATION_CLASS)0x03, pObjectAllInfo, uSize, &uSize);
	//3.ѭ�����������������Ϣ
	POBJECT_TYPE_INFORMATION pObjectTypeInfo = pObjectAllInfo->ObjectTypeInfo;
	for (int i = 0; i < pObjectAllInfo->NumberOfObjectsTypes; i++)
	{
		//3.1�鿴�˶���������Ƿ�ΪDebugObject
		if (!wcscmp(L"DebugObject", pObjectTypeInfo->TypeNames.Buffer))
		{
			delete[] pObjectAllInfo;
			return true;
		}
		//3.2��ȡ������ռ�ÿռ��С(���ǵ��˽ṹ���������)
		ULONG uNameLength = pObjectTypeInfo->TypeNames.Length;
		ULONG uDataLength = uNameLength - uNameLength % sizeof(ULONG) + sizeof(ULONG);
		//3.3ָ����һ��������Ϣ
		pObjectTypeInfo = (POBJECT_TYPE_INFORMATION)pObjectTypeInfo->TypeNames.Buffer;
		pObjectTypeInfo = (POBJECT_TYPE_INFORMATION)((PBYTE)pObjectTypeInfo + uDataLength);
	}
	delete[] pObjectAllInfo;
	return false;
}

int main()
{
	if (CheckDebug_QueryObject())
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
