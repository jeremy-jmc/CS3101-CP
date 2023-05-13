#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];

void solve(int C, int n)
{

    for (int i = 0; i <= 2000; i++)
        for (int j = 0; j <= 2000; j++)
            dp[i][j] = 0;

    vector<int> value(n, 0);
    vector<int> weight(n, 0);

    for (int i = 0; i < n; i++)
        cin >> value[i] >> weight[i];

    /// print pre dp

    /// maxi[W][i] is max value you can put in a knapsack of size W
    /// with their index less than i
    for (int x = 0; x <= C; x++)
    {
        for (int i = 0; i < n; i++)
        {
            int &temp = dp[x][i];
            dp[x][i + 1] = max(temp, dp[x][i + 1]);
            if (x + weight[i] <= C)
                dp[x + weight[i]][i + 1] = max(
                    temp + value[i], 
                    dp[x + weight[i]][i + 1]
                );
        }
    }
    /// you want maxi1[C][n]
    for (int x = 0; x <= C; x++)
    {
        for (int i = 0; i <= n; i++)
            cout << dp[x][i] << "\n "[i + 1 <= n];
    }
    
    cout << "\n\n";
    int total = dp[C][n], peso = C;
    vector<int> indices;
    for (int i = n - 1; i >= 0; i--)
    {
        if (total == dp[peso][i])
        {
            continue;
        }
        /// this means total= v_{i} + dp[peso-w_{i}][i]
        /// and we use object i
        else
        {
            indices.push_back(i);
            peso = peso - weight[i];
            total = total - value[i];
        }
    }
    /// for(int i=0;i<n;i++) cout<<"ob "<<i<<"has value "<<value[i]<<" and weight "<<weight[i]<<"\n";
    /// cout<<"max value is "<<dp[C][n]<<"\n";
    /// cout<<"obtained with the index ";

    reverse(indices.begin(), indices.end());

    cout << indices.size() << "\n";
    for (int i = 0; i < indices.size(); i++)
        cout << indices[i] << "\n "[i + 1 < indices.size()];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /// dont forget to erase
    freopen("input_dp.txt", "r", stdin);

    int C, n;
    while (cin >> C)
    {
        cin >> n;
        solve(C, n);
    }
    return 0;
}
