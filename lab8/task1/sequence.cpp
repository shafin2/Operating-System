#include<pthread.h>
#include<iostream>
#include <unistd.h>

using namespace std;

void *seq(void *args){
	for(int i=20;i<=25;i++){
		cout<< i << endl;
		sleep(1);
	}
	return nullptr;
}

int main(){
	pthread_t id;
	pthread_create(&id,NULL,seq,NULL);

	for(int i=1;i<=5;i++){
		cout<< i << endl;
		sleep(1);
	}
        pthread_join(id,NULL);
	return 0;
}
