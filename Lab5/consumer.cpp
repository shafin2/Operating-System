#include <bits/stdc++.h>
#include <sys/shm.h> //for shared memory

using namespace std;

int main(){

    int shmid;
    void * shared_memory;
    char input[100];
    shmid=shmget((key_t)1234,1024,0666); // (key,size,permission)

    cout<<"Id of shared memory is : "<<shmid<<endl;
    
    shared_memory=shmat(shmid,NULL,0); //(key,size,permission)
    cout<<"Process attached is : "<<shared_memory<<endl;
    cout<<"Data of shared memory is : "<<endl;
    cout<<(char*)shared_memory<<endl;
    return 0;
}