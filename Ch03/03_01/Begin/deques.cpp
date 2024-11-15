// std::deque demo
// by Eduardo Corpeño

#include <iostream>
#include <deque>

using namespace std;

int main(){
	deque<int> numbers;
	int temp = 0;

	cout<<"Pushing Back...\n";
	while(temp>=0){
		cout<<"Enter Number: ";
		cin>>temp;
		if(temp>=0)
			numbers.push_back(temp);		
	}

	deque<int>::iterator it;
	cout<<"{ ";
	for(it = numbers.begin(); it != numbers.end(); it++)
		cout<< *it << " ";
	cout<< "}" <<endl;
	
	cout<<"Pushing Front...\n";
	do {
		cout<<"Enter Number: ";
		cin>>temp;
		if(temp>=0)
			numbers.push_front(temp);		
	} while(temp>=0);

	cout<<"{ ";
	for(it = numbers.begin(); it != numbers.end(); it++)
		cout<< *it << " ";
	cout<< "}" <<endl;
	return 0;
}
