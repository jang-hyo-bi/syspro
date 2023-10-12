#include <stdio.h>
#include"copy.h"

char line[MAXLINE];
char longest[MAXLINE];

main(){
int len;
int max;
int i;
max = 0;
while(i<5){
while(gets(line)!=NULL){
 len=strlen(line);

 if(len>max){
    max = len;
    copy(line,longest);
 }
i++;
}
}
if(max>0)
    printf("%s\n",longest);

}
return 0;
