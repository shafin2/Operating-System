#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

// Define a struct to hold the arguments for the thread function
struct ThreadArgs {
    char label;  // Label for the thread
};

// Thread function
void* seq(void* args) {
    ThreadArgs* threadArgs = (ThreadArgs*)args; // Cast the void pointer to the appropriate type
    cout << "It is " << threadArgs->label << endl; // Access the label using -> notation
    return nullptr;
}

int main() {
    pthread_t t1, t2;
    
    // Create arguments for the threads
    ThreadArgs args1 = {'A'};
    ThreadArgs args2 = {'B'};

    // Create threads and pass the arguments
    pthread_create(&t1, NULL, seq, (void*)&args1);
    pthread_create(&t2, NULL, seq, (void*)&args2);
    
    // Join the threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

