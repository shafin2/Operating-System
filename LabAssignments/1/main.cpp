// Shafin zaman
// sp22-bcs-063

#include<bits/stdc++.h>
using namespace std;
int main(){
    string Filename;
    
    cout<< "Input Filename: ";
    cin>> Filename;
    string str = "g++ " + Filename + " -o output";

    const char *command = str.c_str();
    system(command);
    system("./output");

    return 0;
}

// to run this fill first compile with g++ main.cpp -o output
// then run with ./output

// this program is taking filename and running the file