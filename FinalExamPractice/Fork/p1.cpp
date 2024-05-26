#include<bits/stdc++.h>
#include<sys/wait.h>
#include <unistd.h>

using namespace std;

void tree(int level, int currLvl){
	if(currLvl>level){
		return;
	}
	pid_t p;
	for(int i=0;i<3;i++){
		p = fork();
		if(p==0){
			cout<<"Level "<<currLvl<<" : I am child " << getpid() << " with parent " << getppid() << endl;
			tree(level,currLvl+1);
			exit(0);
		}

		else if(p>0){
			wait(NULL);
		}
		else{
			cout<< "didnt fork correctly"<< endl;
		}
	}
}
int main(){
	int n;
	cout << "hello, Enter no of processes: "<<endl;
	cin >> n;
	

	cout<< "Root Process PID" << getpid() << " with parent " << getppid() << endl;
	tree(n,1);

	return 0; 
}
