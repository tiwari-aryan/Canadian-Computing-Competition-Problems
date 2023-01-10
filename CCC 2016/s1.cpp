#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> nums;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num == 0){
            nums.pop_back();
        }
        else{
            nums.push_back(num);
        }
    }

    int sum = 0;

    for(int i:nums){
        sum += i;
    }

    cout << sum;

    return 0;
}