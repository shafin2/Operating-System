#include <bits/stdc++.h>
#include <sys/shm.h> //for shared memory
using namespace std;

int main(){

    int shmid;
    void * shared_memory;
    char input[100];
    shmid=shmget((key_t)1234,1024,0666|IPC_CREAT); //IPC_CREAT when making for first time
    //Use shmget to get the shared memory segment
    //it takes 3 arguments, key, size, permission
    //key_t is a data type used for the key to the shared memory segment
    //0666 is the permission, it is the same as the permission in chmod command
    //IPC_CREAT is used to create the shared memory segment

    cout<<"Id of shared memory is : "<<shmid<<endl;
    
    shared_memory=shmat(shmid,NULL,0); //(key,size,permission)
    //Use shmat to attach the shared memory segment
    //it takes 3 arguments, shmid, address, flag
    // 0 means all permissions
    //Attaches a shared memory segment identified by its ID (shmid) to the calling process.

    cout<<"Process attached is : "<<shared_memory<<endl;

    cout<<"Enter data you want to send : "<<endl;
    //cin does not read space like "I am", it will read "I" only
    //Therefore using cin.getline
    cin.getline(input,100);
    strcpy(static_cast<char*>(shared_memory),input);

    return 0;
}