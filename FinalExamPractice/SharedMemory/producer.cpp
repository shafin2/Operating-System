// producer.cpp

#include <sys/shm.h>
#include<bits/stdc++.h>

using namespace std;

struct SensorData {
    float temperature;
    double pressure;
};

int main() {
    int shmid;
    void* shm;

    // Create a shared memory segment
    shmid = shmget((key_t)1122, sizeof(SensorData), 0666 | IPC_CREAT);
    if (shmid == -1) {
        cerr << "Shared memory creation failed" << endl;
        return 1;
    }

    // Attach the shared memory segment to the process's address space
    shm = shmat(shmid, NULL, 0);
    if (shm == (void*)-1) {
        cerr << "Shared memory attachment failed" << endl;
        return 1;
    }

    SensorData* data = static_cast<SensorData*>(shm);

    // Get input from the user
    cout << "Enter temperature: ";
    cin >> data->temperature;
    cout << "Enter pressure: ";
    cin >> data->pressure;

    cout << "Data written to shared memory: temperature = " << data->temperature << ", pressure = " << data->pressure << endl;

    return 0;
}

