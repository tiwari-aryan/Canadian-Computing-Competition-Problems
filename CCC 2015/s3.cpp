#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector <int> gates;

int main() {
  int g, p, planes = 0;
  cin >> g >> p;
  for (int i = 0; i < g; i++) {
    gates.push_back(0);
  }

  for (int i = 0; i < p; i++) {
    int plane;
    bool found = false;
    cin >> plane;
    plane -= 1;
    int position = plane;
    while(position >= 0){
        if(gates[position] == 0){
            found = true;
            break;
        }
        else{
            int a = gates[position];
            gates[position] += 1;
            position -= a;
        }
    }
    if (!found) {
      break;
    } else {
        planes += 1;
        gates[position] += 1;
    }
  }

  cout << planes;
}