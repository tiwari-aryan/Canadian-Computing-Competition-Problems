#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector <int> wood;
vector <int> first_half;
vector <int> second_half;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        wood.push_back(w);
    }
    int same_count = 0, total_count = 0;
    sort(wood.begin(), wood.end());
    for(int i: wood){
        cout << i << " ";
    }
    cout << endl;
    if(n % 2 != 0){
        for(int i = 0; i < (n/2); i++){
            first_half.push_back(wood[i+1] - wood[i]);
        }
        for(int i = (n/2); i < n - 1; i++){
            second_half.push_back(wood[i+1] - wood[i]);
        }
    }
    else{
        for(int i = 0; i < (n/2); i++){
            first_half.push_back(wood[i+1] - wood[i]);
        }
        for(int i = (n/2) - 1; i < n - 1; i++){
            second_half.push_back(wood[i+1] - wood[i]);
        }
    }
    reverse(second_half.begin(), second_half.end());
    for(int i:first_half){
        cout << i << " ";
    }
    cout << endl;
    for(int i:second_half){
        cout << i << " ";
    }
    cout << endl;
    int count = 0, max_count = 0, heights = 0;
    bool found = false;
    for(int i = 0; i < first_half.size(); i++){
        int index = i;
        for(int j = 0; j < second_half.size(); j++){
            if(first_half[index] == second_half[j]){
                found = true;
                count += 1;
                index += 1;
            }
            else{
                if(found){
                    if(count > max_count){
                        max_count = count;
                        found = false;
                        heights = 0;
                    }
                    if(count == max_count){
                        heights += 1;
                    }
                    count = 0;
                }
            }
            if(j == second_half.size() - 1){
                if(found){
                    if(count > max_count){
                        max_count = count;
                        found = false;
                        heights = 0;
                    }
                    if(count == max_count){
                        heights += 1;
                    }
                    count = 0;
                }
            }
        }

    }
    if(max_count == 0){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += i;
        }
        cout << 1 << " " << sum;
    }
    else cout << max_count << " " << heights;



    


}