#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
int res,n;
res=open("fifo1",O_WRONLY);
write(res,"Message",7);
printf("sender process having pid %d send the data\n",getpid());

}
