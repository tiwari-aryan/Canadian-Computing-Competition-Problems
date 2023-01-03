#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> scores;

int main(){
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        scores.push_back(a);
    }
    int days = n / d + 1, trail = n % d, sum1 = 0, sum2 = 0;
    
    int max_score = 0;
    for(int i = 0; i < trail; i++){
        if(scores[i] > max_score){
            max_score = scores[i];
        }
    }
    sum1 += max_score;
    for(int i = trail; i <= scores.size() - d; i += d){
        max_score = 0;
        for(int j = i; j < i + d; j++){
            if(scores[j] > max_score){
                max_score = scores[j];
            }
        }
        sum1 += max_score;
    }

    max_score = 0;
    for(int i = n - trail; i < n; i++){
        if(scores[i] > max_score){
            max_score = scores[i];
        }
    }
    sum2 += max_score;
    for(int i = 0; i <= scores.size() - trail - d; i += d){
        int max_score = 0;
        for(int j = i; j < i + d; j++){
            if(scores[j] > max_score){
                max_score = scores[j];
            }
        }
        sum2 += max_score;
    }
    
    cout << max(sum1, sum2);





    return 0;
}