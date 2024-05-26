#include<bits/stdc++.h>

using namespace std;

int items =0, x;

void producer(){
	cout<<"Producer Produce"<<++items<<endl;
	x=6;
}

void consumer(){
	cout<<"Before consume value of x: "<<x<<endl;
	cout<<"Consuemr consume: "<<--items<<endl;
	x=12;
}

int main(){
	producer();
	producer();
	producer();
	consumer();
	consumer();
	return 0;
}
