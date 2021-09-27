#include<stdio.h>
int main()
{
int pid;
pid=getpid();
printf("process ID is %d\n",pid);
pid=getppid();
printf("parent process ID id %d\n",pid);
}