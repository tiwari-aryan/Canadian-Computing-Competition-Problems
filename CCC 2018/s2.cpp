#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void){
    int n_together, n_separate, g, violations = 0;
    cin >> n_together;
    string together[n_together][2];
    for(int i = 0; i < n_together; i++){
        string first, second;
        cin >> first >> second;
        together[i][0] = first;
        together[i][1] = second;
    }
    cin >> n_separate;
    string separate[n_separate][2];
    for(int i = 0; i < n_separate; i++){
        string first, second;
        cin >> first >> second;
        separate[i][0] = first;
        separate[i][1] = second;
    }
    cin >> g;
    for(int i = 0; i < g; i++){
        string first, second, third;
        cin >> first >> second >> third;
        set <string> groups = {first, second, third};
        set <string> new_groups = {first, second, third};
        for(int j = 0; j < n_together; j++){
            new_groups.insert(together[j][0]);
            new_groups.insert(together[j][1]);
            if(new_groups.size() - groups.size() == 1){
                violations += 1;
                break;
            }
        }
        new_groups = {first, second, third};
        for(int j = 0; j < n_separate; j++){
            new_groups.insert(separate[j][0]);
            new_groups.insert(separate[j][1]);
            if(new_groups.size() == groups.size()){
                violations += 1;
                break;
            }
        }
    }

    cout << violations;

    return 0;
}