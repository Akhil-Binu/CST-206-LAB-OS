#include<stdio.h>
void main()
{
int i=0,j=0,p[i],b[i],g[20],w[20],t[20],a[20],n=0,m;
int k=1,min=0,btime=0;
float avgw=0,avgt=0;
printf("Enter the number of process : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nProcess id : ");
scanf("%d",&p[i]);
printf("Burst Time : ");
scanf("%d",&b[i]);
printf("Arrival Time: ");
scanf("%d",&a[i]);
}
//sort the jobs based on burst time.
int temp=0;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
temp=b[j];
b[j]=b[j+1];
b[j+1]=temp;
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
for(i=0;i<n;i++)
{
btime=btime+b[i];
min=b[k];
for(j=k;j<n;j++)
{
if(btime >= a[j] && b[j]<min)
{
temp=a[j];
a[j]=a[j-1];
a[j-1]=temp;
temp=b[j];
b[j]=b[j-1];
b[j-1]=temp;
temp=p[j];
p[j]=p[j-1];
p[j-1]=temp;
}
}
k++;
}
g[0]=a[0];
for(i=0;i<n;i++)
{
g[i+1]=g[i]+b[i];
if(g[i]<a[i])
g[i]=a[i];
}
for(i=0;i<n;i++)
{
t[i]=g[i+1]-a[i];
w[i]=t[i]-b[i];
avgw+=w[i];
avgt+=t[i];
}
avgw=avgw/n;
avgt=avgt/n;
printf("pid\tBrustTime\tGantChart\tWaiting time\t\tTurnarround Time\n");
for(i=0;i<n;i++)
{
printf(" %d\t %d\t\t%d-%d\t\t%d\t\t\t%d\n",p[i],b[i],g[i],g[i+1],w[i],t[i]);
}
printf("\nAverage waiting time %f",avgw);
printf("\nAverage turnarround time %f\n",avgt);
}