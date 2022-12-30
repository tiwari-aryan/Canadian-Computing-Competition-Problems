#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;


class pipe{
    public:
        int self;
        int next;
        int cost;
        bool activated;
        pipe(int self, int next, int cost, bool activated);
        
};

pipe::pipe(int s, int n, int c, bool a){
    self = s;
    next = n;
    cost = c;
    activated = a;
};

vector <pipe> pipes;
vector <pipe> new_pipes;

bool common_elements(vector <pair <int, int>> v1, vector <int> v2){
    for(pair i:v1){
        if(find(v2.begin(), v2.end(), i.first) != v2.end() || i.first == v2[v2.size()-1]){
            return true;
        }
    }
    return false;
}

bool check_cycle(vector<pipe> pipes, int building){

    vector <pair<int, int>> unvisited = {make_pair(building, 0)};
    vector <int> visited;
    
    while(!unvisited.empty()){
        
        for(int i = 0; i < pipes.size(); i++){
            if(pipes[i].self == unvisited[0].first && pipes[i].next != unvisited[0].second){
                unvisited.push_back(make_pair(pipes[i].next, pipes[i].self));
            }
            if(pipes[i].next == unvisited[0].first && pipes[i].self != unvisited[0].second){
                unvisited.push_back(make_pair(pipes[i].self, pipes[i].next));
            }
        }
        visited.push_back(unvisited[0].first);
        unvisited.erase(unvisited.begin());
        if(common_elements(unvisited, visited)){
            return true;
        }
    }
    return false;
    




}

int main(){
    int n, m, d;
    cin >> n >> m >> d;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pipe p(min(a, b), max(a, b), c, true);
        if(i >= n - 1){
            p.activated = false;
        }
        pipes.push_back(p);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m - 1; j++){
            if(pipes[j].cost > pipes[j+1].cost){
                swap(pipes[j], pipes[j+1]);
            }
        }
    }

    int active = 0, inactive = 0;

    for(int i = 0; i < m; i++){
        pipe p = pipes[i];
        new_pipes.push_back(p);
        if(check_cycle(new_pipes, p.self)){
            new_pipes.pop_back();
            if(p.activated){
                active += 1;
            }
        }
    }

    

    for(pipe p:new_pipes){
        if(!p.activated){
            inactive += 1;
        }
    }

    cout << max(active, inactive);

    return 0;
}