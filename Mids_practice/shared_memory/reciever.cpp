#include<iostream>
#include<bits/stdc++.h>
#include<sys/shm.h>

using namespace std;

int main(){
	int shmid;
	void * shared_memory;
	
	shmid = shmget((key_t)1122,1024,0666);
	
	shared_memory = shmat(shmid,NULL,0);
	
	cout << "Process attached at" << shared_memory << endl;
	
	cout << "It reads \n" << (char *)shared_memory << endl;
	return 0;
}
