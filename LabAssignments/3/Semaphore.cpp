#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>

using namespace std;

int a = 0;
sem_t s1,s2,s3,s4;

void* A(void *arg){
    cout << "Process A finish" << endl;
    sem_post(&s1);
    return nullptr;
}

void* B(void *arg){
    sem_wait(&s1);
    cout << "Process B finish" << endl;
    sem_post(&s2);
    return nullptr;
}

void* C(void *arg){
    sem_wait(&s2);
    cout << "Process C finish" << endl;
    sem_post(&s2);
    sem_post(&s1);
    return nullptr;
}

void* D(void *arg){
    sem_wait(&s2);
    cout << "Process D finish" << endl;
    sem_post(&s2);
    sem_post(&s3);
    return nullptr;
}

void* E(void *arg){
    sem_wait(&s3);
    cout << "process E finish" << endl;
    sem_post(&s3);
    sem_post(&s4);
    return nullptr;
}

void* F(void *arg){
    sem_wait(&s4);
    sem_wait(&s3);
    sem_wait(&s1);
    cout << "process F finish" << endl;
    return nullptr;
}


int main(){

    pthread_t t1,t2,t3,t4,t5,t6;
    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 0);
    sem_init(&s3, 0, 0);
    sem_init(&s4, 0, 0);

    pthread_create(&t1, NULL, A, NULL);
    pthread_create(&t2, NULL, B, NULL);
    pthread_create(&t3, NULL, C, NULL);
    pthread_create(&t4, NULL, D, NULL);
    pthread_create(&t5, NULL, E, NULL);
    pthread_create(&t6, NULL, F, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);

    return 0;
}
