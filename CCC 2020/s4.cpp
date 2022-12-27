#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, c, count = 0;
    cin >> n >> c;
    double m = c / 2;
    int points[n];
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        points[i] = p;
    }
    for(int i = 0; i < n-2; i++){
        int p1 = points[i];
        for(int j = i+1; j < n-1; j++){
            int p2 = points[j] - p1 >= 0 ? points[j] - p1 : c + points[j] - p1;
            if(p2 == m || p2 == 0){
                continue;
            }
            else{
                for(int k = j+1; k < n; k++){
                    int p3 = points[k] - p1 >= 0 ? points[k] - p1 : c + points[k] - p1;
                    if(p3 == m || p3 == 0){
                        continue;
                    }
                    if((p2 < m && p3 > m && p3 < p2 + m) || (p2 > m && p3 < m && p2 < p3 + m)){
                        count += 1;
                    }
                }
            }
        }
    }
    cout << count;
    
    return 0;
}