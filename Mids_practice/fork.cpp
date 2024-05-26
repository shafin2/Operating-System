#include<sys/wait.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main(){

pid_t pid = fork();

if(pid == 0){
cout<<"Child process: "<<getpid() << "ppid: " << getppid() <<endl;

return 0;
sleep(5);
cout << "Child ka kam khatam" << endl;
}
else if(pid>0){
        cout<<"Parent process: "<<getpid() << "ppid: " << getppid() <<endl;

wait(NULL);
cout << "child fout parent continue"<<endl;
}

return 0;
}
