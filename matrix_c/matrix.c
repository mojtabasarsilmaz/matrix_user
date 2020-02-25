#include <stdio.h>
#include <math.h>

/* 
    
*/
char *MSGS[] = {
    "How many rows ? ",
    "How many columns ? ",
    " Element = "}; 

int counter = 1;

int numback(int count){
    int number = 0;
    while(number == 0){
        if(count == 2){
            printf("%d%s", counter, MSGS[count]);   
        }else{
            printf("%s", MSGS[count]);
        } 
        scanf("%d", &number);
        if(number == 0){ 
            getchar();
            printf("INPUT ERROR, please input the number NOT String or Character"); 
            printf("\n");
        }
        else{
            break;
        }
    }
    
    return number;
}


int main(){
    
    int x, y, i, j, fs, lenspace, length_element, s_new, s_old, tf;
    char *MSGS[] = {"How many rows? ",
                  "How many columns",
                  "INPUT ERROR, please input the number NOT String or Character",
                  " Element = "}; 
    s_new = 0;

    x = numback(0);    

    y = numback(1);

    int matrix[x][y];

    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            matrix[i][j] = numback(2);
            counter += 1;
            lenspace = floor(log10(matrix[i][j]))+1;
            if(lenspace > s_new){
                s_new = lenspace;
            }
        }
    }
    s_old = s_new;
    for(i=0; i<x; i++){
        printf("[");
        for(j=0; j<y; j++){
            length_element = floor(log10(matrix[i][j]))+1;
            if( length_element < s_new ){
                s_new += (s_old - length_element);
                tf = 1;
            }
            for(fs=0; fs<s_new; fs++){
                printf(" ");
            }
            printf("%d", matrix[i][j]);
            if (tf != 0){
                tf = 0;
                s_new -= (s_old - length_element);
            }
        }
        for(fs=0; fs<s_new; fs++){
            printf(" ");
        }
        printf("]\n");
    }

    return 0;
}
