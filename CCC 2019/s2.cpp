#include <iostream>
#include <cmath>

using namespace std;

bool check_prime(int a){
    for(int i = 2; i <= sqrt(a); i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n, add = 0;
    cin >> n;
    int nums[n][2];

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(t % 2 == 0){
            add = 1;
        }
        else{
            add = 0;
        }
        for(int j = t + add, k = t - add; ; j += 2, k -= 2){
            if(check_prime(j) && check_prime(k)){
                nums[i][0] = j;
                nums[i][1] = k;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << nums[i][0] << " " << nums[i][1] << endl;
    }

    return 0;
}