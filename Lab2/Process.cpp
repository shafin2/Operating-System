#include<bits/stdc++.h>
#include<sys/wait.h>
#include<unistd.h> // Include the missing header file
using namespace std;
int main()
{
    /* code */
    pid_t pid=fork();
    if  (pid==0){
        cout<<"Child process: "<<getpid() << "ppid: " << getppid() <<endl;

        exit(EXIT_SUCCESS);
    }
    else if(pid>0){
        cout<<"Parent process: "<<getpid() << "ppid: " << getppid() <<endl;
        sleep(5);
        cout << "Child run successfully" << endl;
    }
    else{
        cout<<"Fork failed"<<endl;
    }
    return 0;
}
