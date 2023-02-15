#include <bits/stdc++.h>

using namespace std;

int main(){
    int k, n, m;
    cin >> k >> n >> m;

    vector <tuple<int, int, int>> routes[n];

    pair <int, int> islands[n];
    for(int i = 0; i < n; i++){
        islands[i].first = 100001;
        islands[i].second = 0;
    }

    for(int i = 0; i < m; i++){
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        routes[a-1].push_back(make_tuple(b - 1, t, h));
        routes[b-1].push_back(make_tuple(a - 1, t, h));
    }

    int starting_node, ending_node;
    cin >> starting_node >> ending_node;
    starting_node -= 1;
    ending_node -= 1;

    islands[starting_node].first = 0;
    priority_queue <pair <int, int>> q;

    bool visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    q.push(make_pair(0, starting_node));

    while(!q.empty()){
        int current_node = q.top().second;
        q.pop();
        if(visited[current_node]){
            continue;
        }
        visited[current_node] = true;
        for(auto u: routes[current_node]){
            int destination, time, hull;
            tie(destination, time, hull) = u;
            if(islands[current_node].first + time < islands[destination].first && islands[destination].second + islands[current_node].second + hull < k){
                islands[destination].first = islands[current_node].first + time;
                islands[destination].second += islands[current_node].second + hull;
                q.push(make_pair(-islands[destination].first, destination));
            }
        }
    }

    if(islands[ending_node].first == 100001){
        cout << -1;
    }
    else{
        cout << islands[ending_node].first;
    }

}