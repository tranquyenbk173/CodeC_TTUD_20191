#include<stdio.h>
#include<system.h>
int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory (&si, sizeof(si));
	si.cb = sizeof(si);
	CreateProcess ("Child.exe", NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	WaitforSingSingleObject(pi.hProcess, 10000);
	TerminateProcess(pi.hProcess, 0);
	CloseHandle (pi.hProcess);
	CloseHandle (pi.hThread);
	return 0;
}