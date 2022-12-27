#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> measurements;
vector <int> low_tides;
vector <int> high_tides;

int main(){
    double n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        measurements.push_back(m);
    }
    sort(measurements.begin(), measurements.end());
    for(int i = 0; i < n; i++){
        if(i < ceil(n/2)){
            low_tides.push_back(measurements[i]);
        }
        else high_tides.push_back(measurements[i]);
    }

    reverse(low_tides.begin(), low_tides.end());
    int index = 0;
    while(index < low_tides.size()){
        if(index == high_tides.size()){
            cout << low_tides[index];
        }
        else cout << low_tides[index] << " " << high_tides[index] << " ";
        index += 1;
    }

}