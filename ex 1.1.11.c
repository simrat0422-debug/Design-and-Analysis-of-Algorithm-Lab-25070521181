knapsack problem 
#include <stdio.h>

int main() {
    int N, W;

    scanf("%d", &N);

    int value[N], weight[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &value[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &weight[i]);
    }

    scanf("%d", &W);

    // dp[w] = maximum value achievable with capacity w
    int dp[W + 1];

    for (int w = 0; w <= W; w++) {
        dp[w] = 0;
    }

    // Process each item once
    for (int i = 0; i < N; i++) {
        // Traverse backwards to ensure 0/1 selection
        for (int w = W; w >= weight[i]; w--) {
            int include = dp[w - weight[i]] + value[i];

            if (include > dp[w]) {
                dp[w] = include;
            }
        }
