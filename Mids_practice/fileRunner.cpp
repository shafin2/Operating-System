#include<bits/stdc++.h>
using namespace std;
int main(){

string filename;
cout << "Enter filename to run : " ;
cin >> filename;

string command = "g++ " + filename + " -o ouput";
system(command.c_str());
system("./ouput");
return 0;
}
