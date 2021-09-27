#include<stdio.h>
main()
{
int pid;
char *args[]={"/bin/ls","-l",0};
printf("\n Parent Process");
pid=fork();
if(pid==0)
{
execv("/bin/ls",args); 
printf("\n Child process");
}
else
{
wait();
printf("\nParent process");
exit(0);
}
}