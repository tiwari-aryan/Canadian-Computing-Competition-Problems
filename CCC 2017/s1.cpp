#include <iostream>
#include <vector>

using namespace std;

vector <int> swifts;
vector <int> sems;

int main(){
    int n, swifts_sum = 0, sems_sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        swifts.push_back(s);
        swifts_sum += s;
    }
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        sems.push_back(s);
        sems_sum += s;
    }
    int d = 0;
    for(int i = n - 1; i >= 0; i--){
        if(swifts_sum == sems_sum){
            d = i + 1;
            break;
        }
        swifts_sum -= swifts[i];
        sems_sum -= sems[i];
    }
    cout << d;


}