#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n;
int cnt = 0;
int* perm;
vector<vector<int>> a;

void comb(int pos, int startnum)
{
    if(pos >= 3)
    {
        /*
        for(int i = 0; i < pos; ++i)
        {
            cout << perm[i] << " ";
        }
        cout << endl;
        */
        //cout << endl;
        //cout << perm[0] + 1<< "    ";
        for(int i = 0; i < a[perm[pos - 1]].size(); ++i)
        {
           // cout << " !" << perm[0] << "! ";
            //cout << a[perm[pos - 1]][i] + 1<< " ";
            if(perm[0] == a[perm[pos - 1]][i])
            {
                cnt++;
                /*
                for(int i = 0; i < pos; ++i)
                {
                    cout << perm[i]  + 1 << " ";
                }
                cout << endl;
                */
                //cout << " + ";
                break;
            }
        }
        if(pos == n)return;
    }
    for(int i = 0; i < a[perm[pos - 1]].size(); ++i)
    {
        bool was = false;
        for(int k = 0; k < pos; ++k)
        {
            if(a[perm[pos - 1]][i] == perm[k])was = true;
        }
        if(!was && a[perm[pos - 1]][i] > startnum)
        {
            perm[pos] = a[perm[pos - 1]][i];
            comb(pos + 1, startnum);
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m;
    cin >> n >> m;
    perm = new int[n];
    a.resize(n);
    int v1, v2;
    for(int i = 0; i < m; ++i)
    {
        cin >> v1 >> v2;
        a[v1 - 1].push_back(v2 - 1);
        a[v2 - 1].push_back(v1 - 1);
    }
    /*
    for(int i = 0; i < n; ++i)
    {
        cout << i + 1 << ": ";
        for(int k = 0; k < a[i].size(); ++k)
        {
            cout << a[i][k] + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    for(int i = 0; i < n; ++i)
    {
        perm[0] = i;
        comb(1,i);
    }
    cout << cnt / 2;
}

