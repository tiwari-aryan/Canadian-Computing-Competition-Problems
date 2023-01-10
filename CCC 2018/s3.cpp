#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Cell{
    public:
        char val;
        pair <int, int> coordinate;
        vector <vector<pair<int, int>>> next_coordinates;
        Cell(char x, pair <int, int> c);

};

Cell::Cell(char x, pair <int, int> c){
    val = x;
    coordinate = c;
};

vector <vector<Cell>> grid;

int main(){
    int r, c, start_r, start_c;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        string row;
        cin >> row;
        vector <Cell> grid_row;
        for(int j = 0; j < c; j++){
            if(row[j] == 'S'){
                start_r = i;
                start_c = j;
            }
            grid_row.push_back(Cell(row[j], make_pair(i, j)));
        }
        grid.push_back(grid_row);
    }






    return 0;
}

