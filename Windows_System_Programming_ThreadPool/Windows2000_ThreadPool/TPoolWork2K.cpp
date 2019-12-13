#include "stdafx.h"
#include "windows.h"
#include "iostream"
using namespace std;

DWORD WINAPI ThreadPoolWorkProc(PVOID pParam)
{
	int nEvtIdx = (int)pParam;
	cout << "=> Thread " << nEvtIdx << "(" << GetCurrentThreadId() << ") signaled ... " << endl;
	Sleep((nEvtIdx + 1) * 10000);
	return 0;
}

void _tmain()
{
	for (int i = 0; i < 10; i++)
	{
		QueueUserWorkItem(ThreadPoolWorkProc, (PVOID)i, WT_EXECUTEDEFAULT);
	}
	getchar();
}