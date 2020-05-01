#include <iostream>
#include <vector>
using namespace std;

int n;
int** dist;
pair<int, int>** pr;
vector<pair<int, int>> a;

void check(int x, int y, pair<int, int> from)
{
    if(x >= 0 && x < n && y >= 0 && y < n)
    {
        if(dist[x][y] == -1)
        {
            pair<int, int> buff(x, y);
            a.push_back(buff);
            dist[x][y] = dist[from.first][from.second] + 1;
            pr[x][y] = from;
        }
    }
}

void bfs(pair<int, int> v){
    int id = 0;
    pair<int, int> x;
    int buff;
    a.push_back(v);
    dist[v.first][v.second] = 0;
    while(a.size() > id){
       // cout << id << " " << a.size() << endl;
        x = a[id++];
        check(x.first + 1, x.second + 2, x);
        check(x.first + 1, x.second - 2, x);
        check(x.first - 1, x.second + 2, x);
        check(x.first - 1, x.second - 2, x);

        check(x.first + 2, x.second + 1, x);
        check(x.first + 2, x.second - 1, x);
        check(x.first - 2, x.second + 1, x);
        check(x.first - 2, x.second - 1, x);
       // cout << id << " " << a.size() << endl << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    dist = new int*[n];
    pr = new pair<int,int>*[n];
    for(int i = 0; i < n; ++i)
    {
        dist[i] = new int[n];
        pr[i] = new pair<int,int>[n];
    }
    for(int i = 0; i < n; ++i)
    {
        for(int k = 0; k < n; ++k)
        {
            dist[i][k] = -1;
            pr[i][k] = pair<int,int>(-1, -1);
        }
    }
    int x, y;
    cin >> x >> y;
    pair<int, int> vn(x - 1, y - 1);
    cin >> x >> y;
    pair<int, int> vk(x - 1, y - 1);
    bfs(vn);
    //cout << endl;
    /*
    for(int i = 0; i < n; ++i)
    {
        for(int k = 0; k < n; ++k)
        {
            cout << dist[k][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < n; ++i)
    {
        for(int k = 0; way[way.size()-1].firstk < n; ++k)
        {
            cout << pr[k][i].first << " " << pr[k][i].second << "   ";
        }
        cout << endl;
    }
    cout << endl;
    */
    cout << dist[vk.first][vk.second] << endl;
    vector<pair<int, int>> way;
    way.push_back(vk);
    while(way[way.size()-1].first != -1 && way[way.size()-1].second != -1)
    {
        way.push_back(pr[way[way.size() - 1].first][way[way.size() - 1].second]);
    }
    for(int i = way.size() - 2; i >= 0; --i)
    {
        cout << way[i].first + 1 << " " << way[i].second  + 1 << endl;
    }
}

