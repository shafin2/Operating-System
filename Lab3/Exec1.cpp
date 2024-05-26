// Shafin-uz-zaman
// sp22-bcs-063

#include<bits/stdc++.h>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    
    pid_t process;
    for (int i=0;i<n;i++){
        process =fork();
        if(process == 0){
            cout << "Child process: " << getpid() << " ppid: " << getppid() << endl;
        }
        else if(process > 0){
            //It will not wait for parent process to complete
            wait(NULL);
            break;
        }
        else{
            cout << "Fork failed" << endl;
        }           
    }
    return 0;
}


// So, essentially, the wait() function here ensures that the parent process waits for the termination of the first child process, but not for the subsequent child processes.




