//
//  cPre.c
//  
//
//  Created by Mohammad Memon on 2/21/20.
//

#include <stdio.h>

struct Student{
    
    char name [50];
    float GPA;
    
};
     int main(){

       struct Student students[50];
       char *lineptr = NULL;
       size_t len = 0;
       int count = 0;

       
         while (getline(&lineptr, &len, stdin)!= -1){
        sscanf(lineptr,"%s %f",students[count].name,&students[count].GPA);
              count ++;
         }
         int i;
        for ( i = 0; i<count; i++){
           if(students[i].GPA>3.0){
           printf("%s\n", students[i].name);
           }
        }
        return 0;
    }

