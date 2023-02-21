#include <iostream>

using namespace std;

int main(){
    int n, spice = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        string pepper;
        cin >> pepper;
        if(pepper == "Poblano"){
            spice += 1500;
        }
        else if(pepper == "Mirasol"){
            spice += 6000;
        }
        else if(pepper == "Serrano"){
            spice += 15500;
        }
        if(pepper == "Cayenne"){
            spice += 40000;
        }
        if(pepper == "Thai"){
            spice += 75000;
        }
        if(pepper == "Habanero"){
            spice += 125000;
        }
    }
    cout << spice;

    return 0;
}