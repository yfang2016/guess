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
#include <time.h>

/* 
* ===  FUNCTION  =============================================================
*         Name:  generate4digits
*  Description:  
* ============================================================================
*/
void generate4digits (char *p)
{
    int i = 0;
    time_t t;

    t = time(NULL);
    srand(t);
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
        if (guess[i] == t[i]) {
            hit_a++;
            guess[i] = 'x';   /* mark not to check for position */
        };
        x >>= 4;
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if ((j == i) || (guess[i] == 'x')) continue;
            hit_b += (guess[j] == t[i]);
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
    int x, y, i;
    time_t t1, t2;

    generate4digits(target);
    t1 = time(NULL);
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
    t2 = time(NULL);
    printf("%.24s\n",ctime(&t1));
    printf("%.24s\n",ctime(&t2));
    return EXIT_SUCCESS;
}			/* ----------  end of function main  ---------- */
