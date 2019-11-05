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

int analysis(int x, const char t[])
{
    int i = 0, j = 0;
    char guess[] = {0,0,0,0};
    int hit_a = 0, hit_b = 0;

    for (i = 4; i--;) {
        guess[i] = x & 0xf;
        if (guess[i] > 9)
            return 0x100;
        hit_a = (guess[i] == t[i]);
        x >>= 4;
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j == i) continue;
            hit_b = (guess[i] == t[j]);
        }
    }
    return (hit_a << 4) | hit_b;
}
/* 
* ===  FUNCTION  =============================================================
*         Name:  main
*  Description:  
* ============================================================================
*/
int main (int argc, char *argv[])
{
    char target[] = {0,0,0,0};
    int x, y;

    generate4digits(target);

    printf("Please give your initial guess:\n");
    while(1) {
        scanf("%x", &x);
        y = analysis(x, target);

        if (y == 0x100) {
            printf("Illegal number\n");
        }
        else if (y == 0x40) {
            printf("bingo!\n");
            break;
        } else {
            printf("%dA%dB\n", (y>>4), y&15);
        }
    }
    return EXIT_SUCCESS;
}			/* ----------  end of function main  ---------- */
