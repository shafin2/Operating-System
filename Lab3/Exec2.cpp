// Shafin-uz-zaman
// sp22-bcs-063

#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    pid_t process;
    for (int i = 0; i < n; i++)
    {
        process = fork();
        if (process == 0)
        {
            cout << "Child process: " << getpid() << " ppid: " << getppid() << endl;
            break;
        }
        else if (process > 0)
        {
            wait(NULL);
        }
        else
        {
            cout << "Fork failed" << endl;
        }
    }
    return 0;
}


// also can complie with gcc
// gcc Exec2.cpp -lstdc++

// By using wait(), the parent process ensures that it doesn't proceed further until all child processes it spawned have finished executing. This helps synchronize the execution of parent and child processes and prevents the parent process from completing before its children.