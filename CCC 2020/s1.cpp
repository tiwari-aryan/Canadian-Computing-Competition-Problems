#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<double, double>> sprinter;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        double t, p;
        cin >> t >> p;
        sprinter.push_back(make_pair(t, p));
    }

    sort(sprinter.begin(), sprinter.end());

    double max_speed = 0.0;

    for(int i = 0; i < n - 1; i++){
        double speed = abs(sprinter[i + 1].second - sprinter[i].second) / (sprinter[i + 1].first - sprinter[i].first);
        if(speed > max_speed){
            max_speed = speed;
        }
    }

    cout << fixed << setprecision(15) << max_speed;


    return 0;
}