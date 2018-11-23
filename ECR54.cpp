#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <iomanip>
#include <queue>

using namespace std;

using ll = long long int;
using P = pair<ll, int>;

struct edge{
  int to;
  ll cost;
};

void djkstra(vector<vector<edge>> &g, int s, int n, vector<int> &path)
{
  vector<ll> d(n, -1);
  priority_queue<P, vector<P>, greater<P>> q;
  d[s] = 0;
  q.push({0, s});
  while(!q.empty())
  {
    P current = q.top();
    q.pop();
    if(d[current.second] != -1 && d[current.second] < current.first)
    {
      continue;
    }
    for(int i = 0; i < g[current.second].size(); i++)
    {
      edge next = g[current.second][i];
      if(d[next.to] > d[current.second] + next.cost || d[next.to] == -1)
      {
        d[next.to] = d[current.second] + next.cost;
        q.push({d[next.to], next.to});
        path[next.to] = current.second;
      }
    }
  }
  /*for(int i = 0; i < n; i++)
  {
    cout << d[i] << " ";
  }
  cout << endl;*/
}

void dfs(vector<vector<int>> &tree, int s, vector<int> &childs, vector<bool> &flag)
{
  flag[s] = true;
  int child_count = 0;
  for(int i = 0; i < tree[s].size(); i++)
  {
    int next = tree[s][i];
    if(!flag[next])
    {
      dfs(tree, next, childs, flag);
      child_count += childs[next] + 1;
      flag[next] = true;
    }
  }
  childs[s] = child_count;
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<edge>> G(n, vector<edge>());
  map<pair<int, int>, int> edge_id;
  for(int i = 0; i < m; i++)
  {
    int x, y;
    ll w;
    cin >> x >> y >> w;
    G[x - 1].push_back({y - 1, w});
    G[y - 1].push_back({x - 1, w});
    edge_id[{x - 1, y - 1}] = i;
  }
  vector<int> path(n, -1);
  djkstra(G, 0, n, path);

  /*for(int i = 0; i < n; i++)
  {
    cout << path[i] << " ";
  }
  cout << endl;*/

  vector<vector<int>> tree(n, vector<int>());
  for(int i = 1; i < n; i++)
  {
    tree[path[i]].push_back(i);
    tree[i].push_back(path[i]);
  }

  /*for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < tree[i].size(); j++)
    {
      cout << tree[i][j] << " ";
    }
    cout << endl;
  }*/

  vector<int> childs(n, 0);
  vector<bool> flag(n, false);
  dfs(tree, 0, childs, flag);
  /*for(int i = 0; i < n; i++)
  {
    cout << childs[i] << " ";
  }
  cout << endl;*/

  vector<P> count_in_d(m);
  for(int i = 0; i < m; i++)
  {
    count_in_d[i] = {0, i};
  }
  for(int i = 1; i < n; i++)
  {
    int to = path[i];
    int from = i;
    int id;
    if(edge_id.count({to, from}))
    {
      id = edge_id[{to, from}];
    }else if(edge_id.count({from, to}))
    {
      id = edge_id[{from, to}];
    }
    count_in_d[id] = {childs[from] + 1, id};
  }
  /*for(int i = 0; i < m; i++)
  {
    cout << count_in_d[i].first << endl;
  }*/
  sort(count_in_d.begin(), count_in_d.end());
  reverse(count_in_d.begin(), count_in_d.end());
  cout << k << endl;
  for(int i = 0; i < k; i++)
  {
    cout << count_in_d[i].second + 1 << " ";
  }
  cout << endl;
  return 0;
}

