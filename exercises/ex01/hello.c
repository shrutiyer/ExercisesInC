#include <stdio.h>

/*    In the non-optimized version, the value of the variables can be seen even
      though it is never going to be used whereas in the optimized version, the
      compilier probably spots the unused variables and removes them.

      But, when x is printed, the optimized version does save the value in a
      register since it will be used later on for printing. In both this case
      and the one above, there are almost half number of operations (movl,
      subq, addq, xorl) made in the optimized version when compared to the non
      optimized version.

      When the value of y is calculated using x and 1, and y is printed, the
      optimization removes unnecessary steps that the non-optimized version
      performs, automatically calculates the value of y as 6 and prints it.

      In all three cases, there were almost half number of operations (movl,
      subq, addq, xorl) made in the optimized version when compared to the
      non-optimized version.
*/

int main() {
    int x = 5;
    int y = x + 1;
    printf("Value of y %i\n", y);
    return 0;
}
