#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int first_row[n];
    int second_row[n];
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        first_row[i] = a;
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        second_row[i] = a;
    }
    int num, total = 0;
    for(int i = 0; i < n; i++){
        if(first_row[i] == 1){
            num = 3;
            if(i > 0){
                if(first_row[i-1] == 1){
                    num -= 1;
                }
            }
            if(i < n - 1){
                if(first_row[i+1] == 1){
                    num -= 1;
                }
            }
            if(second_row[i] == 1){
                num -= 1;
            }
            total += num;
        }
    }
    for(int i = 0; i < n; i++){
        if(second_row[i] == 1){
            num = 3;
            if(i > 0){
                if(second_row[i-1] == 1){
                    num -= 1;
                }
            }
            if(i < n - 1){
                if(second_row[i+1] == 1){
                    num -= 1;
                }
            }
            if(first_row[i] == 1){
                num -= 1;
            }
            total += num;
        }
    }
    cout << total;
}