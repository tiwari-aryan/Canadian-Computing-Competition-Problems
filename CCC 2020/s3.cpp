#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> substrings;

int main(){
    string n, h;
    int count = 0;
    cin >> n >> h;

    sort(n.begin(), n.end());
    
    if(h.length() >= n.length()){
        for(int i = 0; i <=  h.length() - n.length(); i++){
            string substring = h.substr(i, n.length()), sorted_substring = h.substr(i, n.length());
            sort(sorted_substring.begin(), sorted_substring.end());
            if(sorted_substring == n && !(find(substrings.begin(), substrings.end(), substring) != substrings.end())){
                substrings.push_back(substring);
                count += 1;
            }
        }
    }

    cout << count;

    return 0;
}