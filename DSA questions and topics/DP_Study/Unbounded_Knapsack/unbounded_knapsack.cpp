#include <iostream>
#include <vector>
using namespace std;

// Recursion
int maxProfit(vector<int> weights, vector<int> values, int n, int capacity)
{
    static int count = 1;
    cout << "Count: " << count << endl;
    count++;

    if (n == 0 || capacity == 0)
        return 0;

    if (weights[n - 1] <= capacity)
    {
        return max(maxProfit(weights, values, n, capacity - weights[n - 1]) + values[n - 1], maxProfit(weights, values, n - 1, capacity));
    }
    else
        return maxProfit(weights, values, n - 1, capacity);
}

// Memoization
int maxProfitDP(vector<int> weights, vector<int> values, int n, int capacity, vector<vector<int>> &memo)
{
    static int count = 1;
    cout << "Count: " << count << endl;
    count++;

    if (n == 0 || capacity == 0)
        return 0;

    if (memo[n][capacity] != -1)
        return memo[n][capacity];

    if (weights[n - 1] <= capacity)
    {
        return memo[n][capacity] = max(maxProfitDP(weights, values, n, capacity - weights[n - 1], memo) + values[n - 1], maxProfitDP(weights, values, n - 1, capacity, memo));
    }
    else
        return memo[n][capacity] = maxProfitDP(weights, values, n - 1, capacity, memo);
}

int main()
{
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7};

    int size = weights.size();
    int capacity = 8;

    vector<vector<int>> memo(size + 1, vector<int>(capacity + 1, -1));

    // int answer = maxProfit(weights, values, size, capacity);
    // int answer = maxProfitDP(weights, values, size, capacity, memo);

    // Tabulation

    vector<vector<int>> arr(size + 1, vector<int>(capacity + 1, -1));

    for (int j = 0; j <= capacity; j++)
    {
        arr[0][j] = 0;
    }

    for (int i = 0; i <= size; i++)
    {
        arr[i][0] = 0;
    }

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (weights[i - 1] <= j)
            {
                arr[i][j] = max((arr[i][j - weights[i - 1]] + values[i - 1]), arr[i - 1][j]);
            }
            else
                arr[i][j] = arr[i - 1][j];
        }
    }

    int answer = arr[size][capacity];

    cout << "Answer: " << answer << endl;

    return 0;
}