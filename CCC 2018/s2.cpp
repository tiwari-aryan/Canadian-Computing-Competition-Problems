#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sorted(int size, int arr[]){
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

bool check_grid(int size, vector <vector<int>> measurements){
    for(int i = 0; i < size; i++){
        if(!is_sorted(measurements[i].begin(), measurements[i].end())){
            return false;
        }
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if(measurements[j][i] > measurements[j+1][i]){
                return false;
            }
        }
    }
    return true;
}

void print_grid(int size, vector <vector<int>> measurements){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << measurements[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> rotate(int size, vector <vector<int>> measurements){
    vector <vector <int>> temp = measurements;
    for(int i = 0; i < size; i++){
        for(int j = 0, n = size - 1; n >= 0; j++, n--){
            temp[i][j] = measurements[n][i];
        }
    }
    return temp;
}

int main(){
    int n;
    cin >> n;
    vector <vector <int>> measurements;
    vector <int> row;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int m;
            cin >> m;
            row.push_back(m);
        }
        measurements.push_back(row);
        row.clear();
    }

    for(int i = 0; i < 4; i++){
        measurements = rotate(n, measurements);
        if(check_grid(n, measurements)){
            print_grid(n, measurements);
            break;
        }
    }

    return 0;
}