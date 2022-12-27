#include <iostream>

using namespace std;

int main(void){
    int n, sum = 0;
    cin >> n;
    for(int i = n, j = 0; i >= 0; i -= 4, j++){
        if(i % 5 == 0){
            sum += 1;
        }
    }
    cout << sum;

    return 0;
}