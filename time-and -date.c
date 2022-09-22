#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

char * cur_time(char temp[100]){
time_t now=time(NULL);
struct tm* now_time=localtime(&now);
strftime(temp,100,"%H:%M:%S  %d/%m/%Y\n%A  %B",now_time);
return temp;
}
int main(){
char temp[100];
while(1){
    printf("%s",cur_time(temp));
    sleep(1);
    system("cls");
}
}
