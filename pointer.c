/*
 * ============================================================================
 *
 *       Filename:  pointer.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2019 11:27:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Yuan (yfang@nju.edu.cn)
 *   Organization:  nju
 *
 * ============================================================================
 */


#include <stdlib.h>
#include <stdio.h>

char *func(int *x)
{
    char y = 0x12;
    char *p = &y;
    return p;
}

/* 
* ===  FUNCTION  =============================================================
*         Name:  main
*  Description:  
* ============================================================================
*/
int main (int argc, char *argv[])
{
    int *p = NULL;
    char x[] = {1,2,3,4,5};
    int i;

    p = (int *)func(&i);

    for (i = 0; i < 1; i++) {
        printf("%p, %x\n", p, *p++);
    }
    return EXIT_SUCCESS;
} /* ----------  end of function main  ---------- */
