#include<iostream>
#include<bits/stdc++.h>
#include<sys/wait.h>
#include<unistd.h>

using namespace std; 

void print(int A[], int size){
	for(int i=0;i<size;i++){
		cout << A[i] << endl;
	}
}

void calculations(int A[], int size){

	int p1[2],p2[2];
	pipe(p1);
	pipe(p2);
	
	pid_t pid;
	
	pid =fork();
	
	if(pid<0){
		cout << "Didn't fork" << endl;
		return;
	}
	else if(pid == 0){
		cout << "First child " << endl;
		int sum = 0;
		for(int i=0;i<size;i++){
			sum += A[i];
		}
		write(p1[1],&sum,4);
	}
	else{
		pid = fork();
		if(pid<0){
			cout << "Didn't do 2nd fork" << endl;
			return;
		}
		else if(pid == 0){
			cout << "Second child " << endl;
			int average = 0;
			for(int i=0;i<size;i++){
				average += A[i];
			}
			average = average/size;
			write(p2[1],&average,4);
		}
		else{
			cout << "Parent process waiting ... " << endl;
			
			wait(NULL);
			wait(NULL);
			
			int s,a;
			read(p1[0],&s,4);
			read(p2[0],&a,4);
			
			cout << "Sum : " << s << " , Avg : " << a << endl;
		}
	}
}
int main(){
	cout << "Enter the length of list : " ;
	int length;
	cin >> length;
	int A[length];
	for(int i=0;i<length;i++){
		cout << "Enter " << i+1 << " value : " ;
		cin >> A[i];
	}
	
	calculations(A,length);
	return 0;
}










