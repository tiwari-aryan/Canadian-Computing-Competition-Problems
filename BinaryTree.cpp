#include <iostream>

using namespace std;

struct node;

int main(void){
    node* head = new node(1);
    
}

struct node{
    int val;
    node* left;
    node* right;

    node(int val){
        val = val;
        left = NULL;
        right = NULL;
    }
};