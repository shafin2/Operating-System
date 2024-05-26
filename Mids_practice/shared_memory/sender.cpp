#include<iostream>
#include<bits/stdc++.h>
#include<sys/shm.h>


using namespace std;

int main(){
	int shmid;
	void *shared_memory;
	
	shmid = shmget((key_t)1122,1024,0666|IPC_CREAT);
	
	shared_memory = shmat(shmid,NULL,0);
	
	cout << "Process attached at : " << shared_memory << endl;
	
	cout << "Enter content to write : " << endl;
	char input[100];
	
	cin.getline(input,100);
	cout << "New shared memory: " << static_cast<char *>(shared_memory) << endl;
	strcpy(static_cast<char *>(shared_memory)+100, input);
	

	return 0;
}	
