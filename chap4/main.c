#include <stdio.h> 
#include "student.h"
int main(int argc, char* argv[]) 
{ 
   struct student rec;
   FILE *fp;
   if (argc != 2) { 
      fprintf(stderr,"How to use: %s FileName\n", argv[0]);
      return 1; 
   }
   if ((fp = fopen(argv[1], "rb")) == NULL ) {
      fprintf(stderr, "Error  Open File\n");
      return 2;
   }

