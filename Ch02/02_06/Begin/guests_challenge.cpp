// Birthday Party 
// vector and list usage example
// by Eduardo Corpe�o

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

using namespace std;
 
#define USE_VECTOR
//#define USE_LIST 
 
class guest{
public:
	guest(){}
	~guest(){}
	void set_gender(string in){
		char i = in.c_str()[0];
		if (i=='b' || i=='B' || i=='m' || i=='M')
			gender="Boy";
		else
			gender="Girl";
	}
	string name;
	string gender;
	int age;
};

#ifdef USE_VECTOR
	typedef vector<guest> my_container;
#elif defined USE_LIST
	typedef list<guest> my_container;
#endif

void read_file(my_container * my_guests){
	string in_str;
	ifstream in_file("my_guests.txt");
	if(in_file.is_open()){
		guest temp;
		while(getline(in_file,in_str)){
			temp.name=in_str;
			getline(in_file,in_str);
			temp.set_gender(in_str);
			getline(in_file,in_str);
			temp.age=stoi(in_str);
			my_guests->push_back(temp);
		}
		in_file.close();
	}
	else
		cout << "Unable to open file!\n\n";
}

void print_guests(my_container * my_guests){
	auto it = my_guests->begin();
	
	cout << "-- Container Content Start --\n";
	cout << "-----------------------------\n";
	while(it != my_guests->end()){
		cout << "Name: " << it->name << endl;
		cout << "Gender: " << it->gender << endl;
		cout << "Age: " << it->age << endl;
		cout << "-----------------------------\n";
		it++;
	}
	cout << "--  Container Content End  --\n";
}

void print_guest_by_index(my_container * my_guests, int index)
{
	if (index >= my_guests->size() || index < 0)
		return;

	auto it = my_guests->begin();

	#ifdef USE_VECTOR
	it += index;
	#elif defined USE_LIST
	for (int i = 0; i < index; ++i)
		it++;
	#endif 

		cout << "Printing guest at index " << index << ":" << endl;
		cout << "-----------------------------\n";
		cout << "Name: " << it->name << endl;
		cout << "Gender: " << it->gender << endl;
		cout << "Age: " << it->age << endl;
		cout << "-----------------------------\n";
	
}

void remove_guest_by_index(my_container * my_guests, int index)
{
	if (index >= my_guests->size() || index < 0)
	return;

	auto it = my_guests->begin();

	#ifdef USE_VECTOR
	it += index;
	#elif defined USE_LIST
	for (int i = 0; i < index; ++i)
		it++;
	#endif

	my_guests->erase(it);
} 

float average_guest_age(my_container * my_guests)
{
	float avgAge = 0;

	for (auto &guest : *my_guests)
		avgAge += guest.age;

	avgAge /= my_guests->size();
	return avgAge;
}

int main(){
	my_container * my_guests = new my_container;
	read_file(my_guests);
	print_guests(my_guests);
	print_guest_by_index(my_guests, 3);
	remove_guest_by_index(my_guests, 3);
	cout << "Average age of guests: " << average_guest_age(my_guests) << endl;
	print_guests(my_guests);
	return 0;
}












