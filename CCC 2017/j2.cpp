#include <iostream>

using namespace std;

int main(){
    int n, s, sum = 0;
    cin >> n >> s;
    for(int i = 0; i <= s; i++){
        sum += n;
        n *= 10;
    }
    cout << sum;
}