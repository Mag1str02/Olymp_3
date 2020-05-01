#include <iostream>
#include <vector>
using namespace std;

bool m[10000];

void dfs(int v)
{
    if(m[v])return;
    m[v] = true;
    dfs((v * 7 + 2) % 10000);
    dfs((v * 2 + 7) % 10000);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < 10000; ++i)
    {
        m[i] = false;
    }
    dfs(n);
    if(m[x])cout << "YES";
    else cout << "NO";
}
