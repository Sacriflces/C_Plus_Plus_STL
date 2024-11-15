// std::stack demo
// by Eduardo Corpeño

#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<int> numbers;
	int temp;

	cout << "Pushing...\n";
	while(temp>=0){
		cout<<"Enter numbers: ";
		cin>>temp;
		if(temp>=0)
			numbers.push(temp);
	}
	
	cout << "{ ";
	while(numbers.size()){
		cout << numbers.top() << " ";
		numbers.pop();
	}
	cout << "}" << endl;

	return 0;
}



