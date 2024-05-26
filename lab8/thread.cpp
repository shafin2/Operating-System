#include <pthread.h>
#include <iostream>

using namespace std;

void* function(void* arg) {
    cout << "hello" << endl;
    return nullptr;
}

int main() {
    pthread_t id;
    pthread_create(&id, NULL, function, NULL);
    pthread_join(id, NULL);
    return 0;
}

