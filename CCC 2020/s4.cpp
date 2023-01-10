#include <iostream>
#include <climits>
#include <string>

using namespace std;

int string_size;

class section{
    public:
        int a = 0, b = 0, c = 0;
        void add(char character){
            if(character == 'A'){
                a += 1;
            }
            else if(character == 'B'){
                b += 1;
            }
            else if(character == 'C'){
                c += 1;
            }
        }
        void remove(char character){
            if(character == 'A'){
                a -= 1;
            }
            else if(character == 'B'){
                b -= 1;
            }
            else if(character == 'C'){
                c -= 1;
            }
        }
};

int solution(string s){
    section total_string;
    for(int i = 0; i < string_size; i++){
        total_string.add(s[i]);
    }
    section a, b, c;
    for(int i = 0; i < total_string.a; i++){
        a.add(s[i]);
    }
    for(int i = total_string.a; i < total_string.a + total_string.b; i++){
        b.add(s[i]);
    }
    for(int i = total_string.a + total_string.b; i < total_string.a + total_string.b + total_string.c; i++){
        c.add(s[i]);
    }
    int min_swaps = INT_MAX;

    for(int i = 0; i < string_size; i++){
        int swaps = a.b + a.c + b.a + b.c - min(a.b, b.a);
        min_swaps = min(swaps, min_swaps);
        a.add(s[i + total_string.a]);
        a.remove(s[i]);
        b.add(s[i + total_string.a + total_string.b]);
        b.remove(s[i + total_string.a]);
        c.add(s[i + total_string.a + total_string.b + total_string.c]);
        c.remove(s[i + total_string.a + total_string.b]);
    }

    return min_swaps;
}

int main(){
    string s;
    cin >> s;
    string_size = s.length();
    s += s;

    int num_swaps = solution(s);

    for(int i = 0; i < string_size; i++){
        if(s[i] == 'A'){
            s[i] = 'C';
        }
        else if(s[i] == 'C'){
            s[i] = 'A';
        }
    }
    num_swaps = min(num_swaps, solution(s));

    cout << num_swaps;

    return 0;
}