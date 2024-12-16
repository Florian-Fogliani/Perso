#include <stdlib.h>
#include <stdio.h>

static unsigned int combo_rec(const unsigned int* values, unsigned count, unsigned int amount, unsigned index)
{
    if (amount == 0)
        return 1;
    unsigned int res = 0;
    for(unsigned i = index; i < count; i++)
    {
        res += combo_rec(values, count, amount - values[index], i);
    }
    return res;
}

unsigned int coin_combo(const unsigned int* values, unsigned count, unsigned int amount)
{
    return combo_rec(values, count, amount, 0);
}

int main(void)
{
    unsigned coins[] = { 3, 7, 10 };
    printf("%u", coin_combo(coins, 3, 31));
}
