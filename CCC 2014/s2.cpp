#include <bits/stdc++.h>

using namespace std;

vector <string> classmates_1;
vector <string> classmates_2;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string c;
        cin >> c;
        classmates_1.push_back(c);
    }

    for(int i = 0; i < n; i++){
        string c;
        cin >> c;
        classmates_2.push_back(c);
    }
    
    bool valid = true;

    for(int i = 0; i < n; i++){
        string c = classmates_1[i];
        string partner = classmates_2[i];
        if(partner == c){
            valid = false;
            break;
        }
        for(int i = 0; i < n; i++){
            if(classmates_1[i] == partner){
                if(classmates_2[i] != c){
                    valid = false;
                }
                break;
            }
        }
    }

    if(valid){
        cout << "good";
    }
    else{
        cout << "bad";
    }

    return 0;
}