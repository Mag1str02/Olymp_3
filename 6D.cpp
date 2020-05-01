 #include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n;
int* perm;
void gen(int pos, int cnt1, int cnt0)
{
    if(pos == n * 2)
    {
        for(int i  =  0; i < n * 2; ++i)
        {
            if(perm[i] == 1) cout << ")";
            if(perm[i] == 0) cout << "(";
        }
        cout << endl;
        return;
    }

    if(cnt0 < n)
    {
        perm[pos] = 0;
        gen(pos + 1, cnt1, cnt0 + 1);
    }
    if(cnt1 < cnt0)
    {
        perm[pos] = 1;
        gen(pos + 1, cnt1 + 1, cnt0);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    perm = new int[n * 2];
    gen(0,0,0);
}
