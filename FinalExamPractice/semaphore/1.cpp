#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>

using namespace std;

sem_t s1;

void* A(void *args){
	sem_wait(&s1);
	cout << "I am A" << endl;
	sem_post(&s1);
	return nullptr;
}

void* B(void *args){
	cout << "I am B" << endl;
	sem_post(&s1);
	return nullptr;
}

int main(){
	pthread_t p1,p2;
	sem_init(&s1,0,0);
	pthread_create(&p1,NULL,A,NULL);
	pthread_create(&p2,NULL,B,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	cout << "hello world" << endl;
	return 0;
}
