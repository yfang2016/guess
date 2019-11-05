/*
 * ============================================================================
 *
 *       Filename:  guess.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/05/2019 10:35:05 PM
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



/* 
* ===  FUNCTION  =============================================================
*         Name:  generate4digits
*  Description:  
* ============================================================================
*/
void generate4digits (char *p)
{
    int i = 0;
    for (i = 0; i < 4; i++) {
        *p++ = rand()%10;
    }
    return;
}		/* -----  end of function generate4digits  ----- */

/* 
* ===  FUNCTION  =============================================================
*         Name:  main
*  Description:  
* ============================================================================
*/
int main (int argc, char *argv[])
{
    char target[] = {0,0,0,0};
    char guess[] = {0,0,0,0};
    int x;

    generate4digits(target);

    printf("Please give your initial guess:\n");
    while(1) {
        scanf("%d", &x);
        y = analysis(x);

        if (y == 0x40) {
            printf("bingo!\n");
            break;
        } else {
            printf("%dA%dB", (y>>4), y&15);
        }
    }
    return EXIT_SUCCESS;
}			/* ----------  end of function main  ---------- */
