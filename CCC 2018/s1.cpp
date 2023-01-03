#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

vector <double> villages;
vector <double> neighbourhoods;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        double v;
        cin >> v;
        villages.push_back(v);
    }

    sort(villages.begin(), villages.end());

    for(int i = 1; i < n - 1; i++){
        neighbourhoods.push_back((villages[i] - villages[i - 1]) / 2 + (villages[i + 1] - villages[i]) / 2);
    }

    double min_size = *min_element(neighbourhoods.begin(), neighbourhoods.end());

    cout << fixed << setprecision(1) << min_size;

    return 0;
}