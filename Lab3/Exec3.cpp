// Shafin-uz-zaman
// sp22-bcs-063

#include <bits/stdc++.h>
#include <sys/wait.h>

//need to add following lib otherwise it give error on fork
#include <unistd.h>

using namespace std;
int main()
{
    string str;
    cout << "Enter command: ";
    cin >> str;

    pid_t process;
    process = fork();
    if(process==0){

        //Comment out because taking command from user
        // string str ="ls -l";
        const char *command = str.c_str();
        system(command);
    }
    else{
        wait(NULL);
    }
        
    return 0;
}
