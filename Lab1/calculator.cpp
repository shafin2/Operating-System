#include<iostream>

using namespace std;

int main(){
int num1, num2, ans;
char opr,user;

while(true){
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: " ;
	cin >> num2;
	cout << "Enter operator +,-,*,/,% : " ;
	cin >> opr;
	if(opr == '+'){
		ans = num1 + num2;
		cout << "Your sum is " << ans << endl;
	}
	else if(opr == '-'){
		ans= num1 - num2;
		cout << "Your subtraction is " << ans << endl;
	}
	else if(opr == '*'){
		ans= num1 * num2;
		cout << "Multiplication of " << num1 << " and " << num2 << " is " << ans << endl;
	}
	else{
	cout << "Wrong  operator" << endl;
	}
	
	cout << "Press y to continue and any key to exit: ";
	cin >> user;
	if(user=='y'){
		continue;
	}
	else{
		break;
	}
}
return 0;
}
