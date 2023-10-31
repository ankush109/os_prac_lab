//  GNU nano 2.9.3                                                             ipc1.cy

// popen is unidirectional to send data to another process and also to recieve data from another process
// popen(process with which you want to communicate,"type read/write")
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
FILE *rd;
char buffer[30];
sprintf(buffer,"name first");
rd=popen("wc -c","w");
fwrite(buffer,sizeof(char),strlen(buffer),rd);
pclose(rd);
}






