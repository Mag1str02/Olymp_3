#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int s = 42;
    long long dp[10][s];
    dp[0][1] = 9;
    for(int i = 1; i < 10; ++i)dp[i][1] = 1;
    for(int i = 2; i < s; ++i)
    {
        for(int g = 1; g < 10; ++g)
        {
            dp[g][i] = 0;
            for(int k = g; k < 10; ++k)
            {
                dp[g][i] += dp[k][i-1];
            }
        }
    }
    for(int g = 2; g < s; ++g)
    {
        dp[0][g] = dp[0][g - 1];
        for(int k = 1; k < 10; ++k)
        {
           dp[0][g] += dp[k][g];
        }
    }

    int n;
    int len = 0;
    cin >> n;
    if(n < 10)
    {
        cout << n;
        return 0;
    }
    for(int i = 1; i < s; ++i)
    {
        if(n <= dp[0][i])
        {
            len = i;
            break;
        }
    }
    int num[len  + 1];
    num[0] = 1;
    n = n - dp[0][len-1];
    for(int i = 0; i < len + 1; ++i)
    {
       // cout << n << "    ";
        for(int k = num[i]; k < 10; ++k)
        {
          //  cout << dp[k][len - i] << " ";
             if(n > dp[k][len - i]) n -= dp[k][len - i];
             else
             {
                 num[i + 1] = k;
                 break;
             }
        }
       // cout <<  "    " << n << endl;
    }
    for(int i = 1; i < len + 1; ++i)
    {
        cout << num[i];
    }
   // cout << endl;
   // cout << n;
   return 0;
}
