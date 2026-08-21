#include<bits/stdc++.h>
using namespace std;
const int N = 1e9;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, int>>>g(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>p;

    for(int i=0; i<m; i++)
    {
        int u, v, x;
        cin>>u>>v>>x;
        g[u].push_back({x, v});
        g[v].push_back({x, u});
    }

    vector<int>d(n+1, N);
    vector<int>par(n+1, -1);
    cout<<"enter source"<<endl;
    int s;
    cin>>s;
    d[s]=0;
    p.push({0, s});

    while(!p.empty())
    {
        int xx= p.top().first;
        int a = p.top().second;
        p.pop();

        if(xx > d[a])continue;

        for(auto i: g[a])
        {
            int xxx = i.first;
            int b = i.second;
            if(d[a]+xxx < d[b])
            {
                d[b] = d[a]+xxx;
                par[b] = a;
                p.push({d[b], b});
            }
        }
    }
    int des;
    cin>>des;

    vector<int>path;
    int y =des;
    while(y!=-1)
    {
        path.push_back(y);
        y= par[y];
    }
    reverse(path.begin(), path.end());

    cout<<path[0];
    for(int i=1; i<path.size(); i++)
    {
        cout<<" -> "<<path[i];
    }

}
