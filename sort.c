//
//  cSort.c
//  
//
//  Created by Mohammad Memon on 2/21/20.
//

#include <stdio.h>
#include <string.h>
struct Student{
    
    char name [20];
    
    
};
     int main(){

       struct Student students[20];
       char *lineptr = NULL;
       size_t len = 0;
       int count = 0;
         char temp[20];

         while (getline(&lineptr, &len, stdin)!= -1){
        sscanf(lineptr,"%s", students[count].name);
              count ++;
         }
         
     
         int i;
         int j;
        for (i = 0; i<count; i++){
            for (j = i+1; j < count; j++){
                if ( strcmp(students[i].name, students[j].name) > 0){
                    strcpy(temp, students[i].name);
                    strcpy(students[i].name,students[j].name);
                    strcpy(students[j].name,temp);
             }
           }
        }
            for ( i = 0; i<count; i++){
                  printf("%s\n",students[i].name);
        }

            return 0;
    }
