#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n;
bool** a;



int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m;
    cin >> n >> m;
    a = new bool*[n];
    for(int i = 0; i < n; ++i)
    {
        a[i] = new bool[n];
    }
    for(int i = 0; i < n; ++i)
    {
        for(int k = 0; k < n; ++k)
        {
            a[i][k] = false;
        }
    }
    int v1, v2;
    for(int i = 0; i < m; ++i)
    {
        cin >> v1 >> v2;
        a[v1 - 1][v2 - 1] = true;
        a[v2 - 1][v1 - 1] = true;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int k = i + 1; k < n; ++k)
        {
            for(int g = k + 1; g < n; ++g)
            {
                if(a[i][k] && a[k][g] && a[g][i])cnt++;
            }
        }
    }
    cout << cnt;
}
