#include <iostream>

using namespace std;

int main(void){
    int n, g, f, sp = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> g >> f;
        if(5 * g - 3 * f > 40){
            sp += 1;
        }
    }
    if(sp != n){
        cout << sp;
    }
    else cout << sp << "+";
    return 0;
}