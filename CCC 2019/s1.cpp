#include <iostream>
#include <string>

using namespace std;

int main(){
    string flips, nums = "1 2\n3 4";
    cin >> flips;
    int h = 0, v = 0;
    for(char i:flips){
        if(i == 'H'){
            char temp1 = nums[0];
            char temp2 = nums[2];
            nums[0] = nums[4];
            nums[2] = nums[6];
            nums[4] = temp1;
            nums[6] = temp2;
        }
        else{
            char temp1 = nums[0];
            char temp2 = nums[4];
            nums[0] = nums[2];
            nums[4] = nums[6];
            nums[2] = temp1;
            nums[6] = temp2;
        }
    }
    cout << nums;

    return 0;
}