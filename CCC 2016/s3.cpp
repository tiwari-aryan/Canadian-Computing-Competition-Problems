#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set <int> gates;
vector <int> planes;

int main(){
    int g, p;
    cin >> g >> p;
    for(int i = 1; i <= g; i++){
        gates.insert(i);
    }

    for(int i = 0; i < p; i++){
        int plane;
        cin >> plane;

        planes.push_back(plane);
    }

    int sum = 0;

    cout << sum;

    return 0;
}