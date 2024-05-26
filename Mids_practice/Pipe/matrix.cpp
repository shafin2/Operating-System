#include<iostream>
#include<unistd.h>
#include<bits/stdc++.h>
#include<sys/wait.h>

using namespace std; 

void printMatrix(int matrix[][10],int size){
	for(int i=0; i<size;i++){
			for(int j=0; j<size;j++){
				cout << matrix[i][j] << endl;
			}
		}
}
void isSquare(int matrix[][10], int size) {
    int p1[2], p2[2];

    pipe(p1);
    pipe(p2);

    pid_t pid;

    pid = fork();
    if (pid == 0) {
        cout << "First child process" << endl;
        string ss = "hello from 1st";
        write(p1[1], ss.c_str(), ss.size() + 1); // +1 for null terminator
    } else if (pid > 0) {
        pid = fork();
        if (pid == 0) {
            cout << "Second child process" << endl;
            string sss = "hello from 2nd";
            write(p2[1], sss.c_str(), sss.size() + 1); // +1 for null terminator
        } else if (pid > 0) {
            cout << "parent process finally" << endl;
            wait(NULL);
            wait(NULL);

            string s1(100, '\0'), s2(100, '\0'); // Reserve space for 100 characters
            read(p1[0], &s1[0], 100);
            read(p2[0], &s2[0], 100);

            cout << s1 << endl;
            cout << s2 << endl;
        }
    }
}

int main(){
	int size;
	cout << "Enter size of square matrix : " ;
	cin >> size;
	if(size<1 && size>10){
	 cout<< "enter size between 1 and 10 " << endl;
	}
	int matrix[size][10];
	
	for(int i=0; i<size;i++){
		for(int j=0; j<size;j++){
			cout << "Enter value at ("<< i << "," << j << "): ";
			cin >> matrix[i][j];
		}
	}
	isSquare(matrix,size);
	return 0;
}
