#include <iostream>
#include <vector>
#include <set>


using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    set<pair<int,int> > a;
    int v1, v2;
    for(int i = 0; i < m; ++i)
    {
        cin >> v1 >> v2;
        if(v1 != v2)
        {
             pair<int, int> buff(min(v1,v2),max(v1,v2));
            a.insert(buff);
        }

    }
    cout << n << " " << a.size() << endl;
    for(pair<int, int> i : a)
    {
        cout << i.first << " " << i.second << endl;
    }
}
