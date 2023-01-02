#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> scores;

int main(){
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        scores.push_back(a);
    }
    sort(scores.begin(), scores.end());
    int days = n % d;

    return 0;
}