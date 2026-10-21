travelling salesman problem 
#include <stdio.h>

#define MAX 15
#define INF 999999

int n;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int tsp(int mask, int pos)
{
    int city;

    if(mask == (1 << n) - 1)
    {
        if(cost[pos][0] == -1)
            return INF;

        return cost[pos][0];
    }

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    dp[mask][pos] = INF;

    for(city = 0; city < n; city++)
    {
        if((mask & (1 << city)) == 0 && cost[pos][city] != -1)
        {
            dp[mask][pos] = min(
}
