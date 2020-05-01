#include <iostream>
#include <vector>
using namespace std;

int n;
int* group;
bool hz = true;
vector<vector<int>> a;

void dfs(int v, int g)
{
    group[v] = g;
    for(int i = 0; i < a[v].size(); ++i)
    {
        if(group[a[v][i]] == 0)
        {
             dfs(a[v][i], g % 2 + 1);
        }
        else
        {

            if(g == group[a[v][i]])
            {
                hz = false;
            }

        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m;
    cin >> n >> m;
    a.resize(n);
    group = new int[n];
    for(int i = 0; i < n; ++i)
    {
        group[i] = 0;

    }
    int v1, v2;
    for(int i = 0; i < m; ++i)
    {
        cin >> v1 >> v2;
        a[v1 - 1].push_back(v2 - 1);
        a[v2 - 1].push_back(v1 - 1);
    }
    for(int i = 0; i < n; ++i)
    {
        if(group[i] == 0)dfs(i,1);
    }
    /*
    for(int i = 0; i < n; ++i)
    {
        cout << group[i] << " ";
    }
    cout << endl;
    */
    if(hz)cout << "YES";
    else cout << "NO";
}

