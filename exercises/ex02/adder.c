/*
This program allows users to enter integers one per line until they hit Ctrl-D

Author: Shruti Iyer
Last Updated: 2/5/18
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_sum(int numbers_to_sum[], int index) {
    int sum = 0;
    for (int i = 0; i < index; i++) {
        sum += numbers_to_sum[i];
    }
    return sum;
}

int get_user_input(int numbers_to_sum[]) {
    puts("Enter upto 10 integers to sum:");
    int is_continue_reading = 1;
    char integer_entered[11];
    long integer_processed;
    int index = 0;

    while (is_continue_reading) {
        if (scanf("%15s", integer_entered) == EOF) {
            is_continue_reading = 0;
            return index;
        }

        char *ptr = NULL;
        integer_processed = strtol(integer_entered, &ptr, 10);
        if (integer_entered==ptr) {
            puts("Invalid characters entered.");
        } else if (strlen(integer_entered)>9) {
            puts("Integer entered is beyond memory limits.");
        } else if (index > 9) {
            puts("10 integers already entered. Ctrl+D to get the sum.");
        } else {
            numbers_to_sum[index] = integer_processed;
            index++;
        }
    }
}

int main ()
{
    int numbers_to_sum[10];
    int final_index = get_user_input(numbers_to_sum);
    int total_sum = calculate_sum(numbers_to_sum, final_index);
    printf("Total sum of all integers entered is %i\n", total_sum);
    return 0;
}
