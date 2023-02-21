#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector <int> days(5, 0);
    int n, max_day = 0;
    string p;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        for(int j = 0; j < 5; j++){
            if(p[j] == 'Y'){
                days[j] += 1;
                if(max_day < days[j]){
                    max_day = days[j];
                }
            }
        }
    }

    int count = 0;

    for(int i = 0; i < 5; i++){
        if(days[i] == max_day){
            count += 1;
        }
    }

    int print_count = 0;

    for(int i = 0; i < 5; i++){
        if(days[i] == max_day){
            print_count += 1;
            cout << i+1;
            if(print_count != count){
                cout << ",";
            }
            
        }
    }
    
    return 0;
}