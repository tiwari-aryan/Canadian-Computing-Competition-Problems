#include <iostream>

using namespace std;

int main(){
    long long m, hour = 12, minute = 0;
    cin >> m;
    // long long d = m / 720;
    // m %= 720;
    // long long count = 31 * d;
    int count = 0;
    hour = 12;
    minute = 0;
    for(int i = 0; i <= m; i++){
        cout << hour << minute << endl;
        if(hour < 10){
            if(minute >= 10){
                if(hour - (minute / 10) == (minute / 10) - (minute % 10)){
                    count += 1;
                }
            }
        }
        else{
            if(minute >= 10){
                if(1 - (hour % 10) == (hour % 10) - (minute / 10) && (hour % 10) - (minute / 10) == (minute / 10) - (minute % 10)){
                    cout << hour << minute << endl;
                    count += 1;
                }
            }
        }
        minute += 1;
        if(minute == 60){
            minute = 0;
            hour += 1;
        }
        if(hour == 13){
            hour = 1;
        }
    }
    cout << count;


}