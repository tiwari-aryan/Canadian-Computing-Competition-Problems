#include <bits/stdc++.h>

using namespace std;



int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int next = 1;
        stack <int> queue {};
        stack <int> cars {};
        bool valid = true;
        for(int j = 0; j < n; j++){
            int c;
            cin >> c;
            cars.push(c);
        }

        while(!cars.empty() || !queue.empty()){
            if(!cars.empty()){
                if(cars.top() == next){
                    next += 1;
                    cars.pop();
                    continue;
                }
                else{
                    if(!queue.empty()){
                        if(queue.top() == next){
                            next += 1;
                            queue.pop();
                            continue;
                        }
                    }
                    queue.push(cars.top());
                    cars.pop();
                    continue;
                }
            }
            else if(!queue.empty()){
                if(queue.top() == next){
                    next += 1;
                    queue.pop();
                    continue;
                }
                else if(cars.empty()){
                    valid = false;
                    break;
                }
                else{
                    queue.push(cars.top());
                    cars.pop();
                    continue;
                }
            }
        }
        if(valid){
            cout << "Y" << endl;
        }
        else{
            cout << "N" << endl;
        }
    }

    return 0;
}