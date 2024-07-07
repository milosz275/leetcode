#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Calculate water bottles you can drink
 * @param numBottles Number of water bottles you have
 * @param numExchange Number of empty water bottles you can exchange for full water bottle
 * @return Number of water bottles you can drink
 */
int numWaterBottles(int numBottles, int numExchange)
{
    int full_bottles = numBottles;
    int empty_bottles = 0;
    int bottles_emptied = 0;
    while (full_bottles > 0)
    {
        bottles_emptied += full_bottles;
        empty_bottles += full_bottles;
        full_bottles = 0;
        while ((empty_bottles - numExchange) >= 0)
        {
            empty_bottles -= numExchange;
            full_bottles += 1;
        }
    }
    return bottles_emptied;
}

int main()
{
    int num_bottles = 9;
    int num_exchange = 3;
    printf("Number of water bottles you can drink: %d\n", numWaterBottles(num_bottles, num_exchange));
    exit(EXIT_SUCCESS);
}
