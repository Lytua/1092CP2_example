#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;
int main()
{
    
    int S, T, n, m, stop;
    cin >> S >> T >> n;
    
    vector<vector<int>> routes(n);
    unordered_map<int, vector<int>> to_routes;
    
    for (int i=0; i<n; ++i){
        cin >> m;
        routes[i] = vector<int>(m);
        for (int j=0; j<m; ++j) {
            cin >> stop;
            routes[i][j] = stop;
            to_routes[stop].push_back(i);
        }
    }
    
    queue<pair<int, int>> bfs;
    bfs.push({S, 0});
    unordered_set<int> seen = {S};
    
    while (!bfs.empty()) {
        int stop = bfs.front().first, bus = bfs.front().second;
        bfs.pop();
        if (stop == T){
            cout << bus;
            return 0;
        }
        for (int i : to_routes[stop]) {
            for (int j : routes[i]) {
                if (seen.find(j) == seen.end()) {
                    seen.insert(j);
                    bfs.push({j, bus + 1});
                }
            }
            routes[i].clear();
        }
    }
    
    cout << -1;
    return 0;
}