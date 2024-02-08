#include <iostream>
#include <vector>

using namespace std;

int calculateAsymmetricValue(int start_index, int end_index, int mountains[], int n, vector <vector <int>> &memo){
    if(start_index == end_index){
        return 0;
    }
    else if(start_index == end_index - 1){
        return abs(mountains[start_index] - mountains[end_index]);
    }
    else if(memo[start_index][end_index] != -1){
        return memo[start_index][end_index];
    }
    int mid = (start_index + end_index) / 2;
    int l, r;
    if((end_index - start_index) % 2 == 0){
        l = mid, r = mid;
    }
    else{
        l = mid, r = mid + 1;
    }
    memo[start_index][end_index] = abs(mountains[start_index] - mountains[end_index]) + calculateAsymmetricValue(start_index + 1, end_index - 1, mountains, n, memo);
    return memo[start_index][end_index];
}

int main(){
    int n;
    cin >> n;
    int mountains[n];
    vector <vector <int>> memo(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        mountains[i] = m;
    }
    int best[n];
    best[0] = 0;

    for(int i = 1; i < n; i++){
        best[i] = 5e8;
        for(int start_index = 0; start_index < n - i; start_index++){
            int end_index = start_index + i;
            int value = calculateAsymmetricValue(start_index, end_index, mountains, n, memo);
            best[i] = min(best[i], value);
        }
    }
    for(int i = 0; i < n; i++){
        cout << best[i] << " ";
    }
}