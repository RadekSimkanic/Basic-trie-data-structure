// Demo

#include <iostream>
#include <string>

#include "datastructure.h"

using namespace std;


int main() {
	Datastructure ds;
	
	ds.add("h");
	ds.add("hello");
	ds.add("hi");
	ds.add("how");
	ds.add("abc");
	ds.add("abcd");
	ds.add("sdlkjfsl");
	
	ds.print();
	
	if (ds.remove("abc")) {
		cout<<"Delete is success"<<endl;
	}
	
	ds.print();
	
	if (ds.search("h")) {
		cout<<"this word exist"<<endl;
	}
	else {
		cout<<"this word not exist"<<endl;
	}
	
	if (ds.search("hhh")) {
		cout<<"this word exist"<<endl;
	}
	else {
		cout<<"this word not exist"<<endl;
	}
	
	return 0;
}
