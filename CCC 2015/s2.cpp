#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <char> jerseys;

int main(){
    int j, n;
    cin >> j >> n;
    for(int i = 1; i <= j; i++){
        char jersey;
        cin >> jersey;
        jerseys.push_back(jersey);
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        char s;
        int num;
        cin >> s >> num;
        if(jerseys[num-1] <= s){
            jerseys[num-1] = 'Z';
            sum += 1;
        }
    }

    cout << sum;

    return 0;
}