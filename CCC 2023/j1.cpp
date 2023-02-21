#include <iostream>

using namespace std;

int main(){
    int d, c, f;
    cin >> d >> c;
    f = d * 50 - c * 10;
    if(d > c){
        f += 500;
    }
    cout << f;


    return 0;
}