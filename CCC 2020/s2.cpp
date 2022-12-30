#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector<int>> room;

class coordinate{
    public:
        int r;
        int c;
        coordinate(int x, int y);
};

coordinate::coordinate(int x, int y){
    r = x;
    c = y;
};

int main(){
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        vector <int> row;
        for(int j = 0; j < c; j++){
            int num;
            cin >> num;
            row.push_back(num);
        }
        room.push_back(row);
    }

    vector <coordinate> wanted_cells = {coordinate(r, c)};
    bool visited_cells[1010][1010];

    bool escape = false;

    while(!wanted_cells.empty()){
        int wanted_cell = wanted_cells[0].r * wanted_cells[0].c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(room[i][j] == wanted_cell){
                    if(i == 0 && j == 0){
                        escape = true;
                        break;
                    }
                    if(!visited_cells[i][j]){
                        wanted_cells.push_back(coordinate(i+1, j+1));
                    }
                }
                if(escape == true){
                    break;
                }
            }
        }
        if(escape == true){
            break;
        }
        visited_cells[wanted_cells[0].c-1][wanted_cells[0].r-1] = true;
        wanted_cells.erase(wanted_cells.begin());
    }

    if(escape == true){
        cout << "yes";
    }
    else{
        cout << "no";
    }

    return 0;

}