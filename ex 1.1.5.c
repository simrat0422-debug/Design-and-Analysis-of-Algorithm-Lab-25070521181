You are given a set of integers and a target sum.
Write a program that finds all subsets of the given set whose sum is equal to the target sum.
#include <stdio.h>

int arr[20], subset[20];
int ans[1000][20];
int len[1000];
int cnt = 0;

void saveSubset(int size)
{
    len[cnt] = size;
    for (int i = 0; i < size; i++)
        ans[cnt][i] = subset[i];
    cnt++;
}

void findSubsets(int index, int n, int target, int size)
{
    if (target == 0)
    {
        saveSubset(size);
        return;
    }

    if (index == n || target < 0)
        return;

    // Include current element
    subset[size] = arr[index];
    findSubsets(index + 1, n, target - arr[index], size + 1);

    // Exclude current element
    findSubsets(index + 1, n, target, size);
}

int main()
{
    int n, sum;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &sum);

    findSubsets(0, n, sum, 0);

    if (cnt == 0)
    {
        printf("-1");
    }
    else
    {
        for (int i = cnt - 1; i >= 0; i--)
        {
            for (int j = 0; j < len[i]; j++)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
    }

    return 0;
}
