#include <iostream>
#include <string>

using namespace std;

int main(void){
    string instruction, strings = "", turns = "", action = "";
    bool number = false;

    cin >> instruction;

    for(int i = 0; i < instruction.length(); i++){
        if(instruction[i] == '+' || instruction[i] == '-'){
            number = true;
            action = instruction[i];
            continue;
        }
        if(number){
            turns += instruction[i];
            if((instruction[i+1] >= 65 && instruction[i+1] <= 90) || i == instruction.length() - 1){
                if(action == "+"){
                    cout << strings << " tighten " << turns << endl;
                }
                else if(action == "-"){
                    cout << strings << " loosen " << turns << endl;
                }
                number = false;
                strings = "";
                turns = "";
            }
        }
        else{
            strings += instruction[i];
        }
    }
}