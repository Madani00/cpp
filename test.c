#include <stdio.h>
#include <string.h>


int main()
{ 
    
    char c = 'a';
    int i = strlen(&c);

    printf("%d \n", i);
    return 0;
}