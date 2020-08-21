/*
 * Program to multiply 2 operands (numbers) recursively. We will be using
 * repetitive addition to get the multiplication output.
 *
 * Author: Sunny Bhayani
 */

/* ---- Includes ------------------------------------------------------------ */
#include "stdio.h"  // printf()
#include "stdlib.h" // EXIT_SUCCESS

/* ---- Local function definitions ------------------------------------------ */
/*
 * Function to multiply 2 operands (numbers) recursively.
 *
 * Instead of multiplying the number, we will be using repetitive addition e.g.
 * to get (4 * 5), we will be adding '4' to '4' for '5' times.
 *
 * @param [in]: num1:   operand 1 for multiplication
 * @param [in]: num2:   operand 2 for multiplication. We will be using this
 *                      as a repetitive counter.
 */
static int mul(int num1, int num2)
{
    int ret;

    if (num2 == 1)
    {
        printf("-- reached base case: num1=%d, num2=%d\n", num1, num2);
        ret = num1;
    }
    else
    {
        printf("-- calling recursion: num1=%d, num2=%d\n", num1, num2 - 1);
        ret = num1 + mul(num1, num2 - 1);
    }

    return ret;
}

/*
 * C entry point
 */
int main(void)
{
    int num1 = 4;
    int num2 = 10;
    int res;

    printf("#---- Recursive multiply: %d * %d ----#\n", num1, num2);
    res = mul(num1, num2);
    printf("\nrecursive multiply: %d * %d = %d\n", num1, num2, res);

    return EXIT_SUCCESS;
}
