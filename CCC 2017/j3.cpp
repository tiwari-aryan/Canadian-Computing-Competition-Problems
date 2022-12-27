#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    if((abs(x1 - x2) + abs(y1 - y2)) % 2 == c % 2){
        cout << "Y";
    }
    else cout << "N";
}