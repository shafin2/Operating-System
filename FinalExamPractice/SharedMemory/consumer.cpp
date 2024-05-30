// consumer.cpp

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

    // Get the shared memory segment
    shmid = shmget((key_t)1122, sizeof(SensorData), 0666);
    if (shmid == -1) {
        cerr << "Shared memory segment not found" << endl;
        return 1;
    }

    // Attach the shared memory segment to the process's address space
    shm = shmat(shmid, NULL, 0);
    if (shm == (void*)-1) {
        cerr << "Shared memory attachment failed" << endl;
        return 1;
    }

    SensorData* data = static_cast<SensorData*>(shm);

	cout << typeid(data->temperature).name() << endl;
    // Convert the data to a string
    string sensorDataStr = "Temperature: " + to_string(data->temperature) + ", Pressure: " + to_string(data->pressure);


	string fileData = "echo " + sensorDataStr + "| cat > Data.txt";
	system(fileData.c_str());
	
	string show = "cat Data.txt";
	system(show.c_str());


    return 0;
}

