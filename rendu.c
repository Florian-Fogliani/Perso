#include <stdlib.h>
#include <stdio.h>

void coin_combo_rec(const unsigned int* values, unsigned count, unsigned int amount, unsigned int act, unsigned int *dp)
{
    if (act >= count)
    {
        return;
    }
        int coin = values[act];
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
        coin_combo_rec(values, count, amount, act + 1, dp);
    }


unsigned int
coin_combo(const unsigned int* values, unsigned count, unsigned int amount)
{
    unsigned int *dp = malloc(sizeof(unsigned int)*(amount+1));
    for (int i = 0; i <= amount; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    coin_combo_rec(values,count, amount, 0, dp);
    unsigned int res = dp[amount];
    free(dp);
    return res;
}
