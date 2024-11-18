// Hotel Application
// map usage challenge
// by Eduardo Corpeño

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

bool validRoomNumber(string roomNum)
{
	int floor;
	int room;
	switch(roomNum.length())
	{
		case 3:
			floor = stoi(roomNum.substr(0,1));
			room = stoi(roomNum.substr(1,2));
			if (floor > 0 && floor < 21 && room > 0 && room < 16)
				return true;
			break;
		case 4:
			floor = stoi(roomNum.substr(0,2));
			room = stoi(roomNum.substr(2,2));
			if (floor > 0 && floor < 21 && room > 0 && room < 16)
				return true;
			break;
		default:
			return false;
	}
	return false;
}

int main(){
	map<int,string> hotel;
	int temp;
	string str;
	pair<int,string> p;
	
	cout<<"Inserting...\n";
	while(temp>=0){
		cout<<"Enter room number: ";
		getline(cin,str);
		temp=stoi(str);
		if(temp>=0 && validRoomNumber(str)){
			p.first=temp;
			cout<<"Enter name: ";
			getline(cin,str);
			p.second=str;
			hotel.insert(p);
		}
	}
	
	cout<<"{   ";
	for(auto it = hotel.begin(); it!=hotel.end();it++)
		cout << it->first << "->" << it->second << "   ";
	cout<<"}\n";
	
	temp = 0;
	cout<<"Removing...\n";
	while(temp>=0){
		cout<<"Enter room number: ";
		getline(cin,str);
		temp=stoi(str);
		if(temp>=0)
			hotel.erase(temp);
	}

	cout<<"{   ";
	for(auto it = hotel.begin(); it!=hotel.end();it++)
		cout << it->first << "->" << it->second << "   ";
	cout<<"}\n";
	
	return 0;
}








