#include <stdio.h>
#include <iostream>
#include <string>

#include "datastructure.h"


using namespace std;

Datastructure::Datastructure() {
	root = new data();
	count = 0;
}

Datastructure::~Datastructure() {
	empty(root);
	delete root;
}


bool Datastructure::add(std::string word) {
	findNode(word, true);
	
	if (!tmp->done) {
		tmp->done = true;
		count ++;
		return true;
	}
	
	return false;
}

bool Datastructure::findNode(std::string word, bool creating) {
	unsigned long length = word.size();
	data * step = root;
	for (unsigned long i = 0; i < length; i++) {
		unsigned long c = (unsigned long) word[i] - 97;
		if (!step->isNodes[c]) {
			if (!creating) {
				return false;
			}
			step->isNodes[c] = true;
			step->nextNodes[c] = new data();
			// only for removing cache
			/*
			step->numberSet++;
			step->nextNodes[c]->parent = step;
			//*/
		}
		step = step->nextNodes[c];
	}
	
	tmp = step;
	
	return true;
}



bool Datastructure::remove(std::string word) {
	if (!findNode(word, false)) {
		return false;
	}
	tmp->done = false;
	count --;
	
	// this part removing unused branch | when this part is not use (when is commented) then unused branch is cache for quickly insert.
	/*
	if (tmp->numberSet == 0) {
		data * remove = tmp;
		tmp = tmp->parent;
		while (!remove->done && remove->numberSet == 0) {
			for (unsigned long i = 0; i < 26; i++) {
				if (tmp->isNodes[i] && tmp->nextNodes[i] == remove) {
					delete tmp->nextNodes[i];
					tmp->isNodes[i] = false;
					tmp->numberSet--;
					break;
				}
			}
			if (tmp == root) {
				break;
			}
			remove = tmp;
			tmp = tmp->parent;
		}
	}
	//*/
	return true;
}

// Returns true if word was found and false otherwise.
bool Datastructure::search(std::string word) {
	return findNode(word, false);
}

// Solves and returns amount of words in datastructure.
unsigned int Datastructure::amountOfWords() {
	return count;
}

// Empties the datastructure.
void Datastructure::empty() {
	empty(root);
	delete root;
	root = new data();
	
}

// post order recursion
void Datastructure::empty(data * node) {
	if (node->done) {
		count--;
	}
	for (unsigned long i = 0; i < 26 && count > 0; i++) {
		if (node->isNodes[i]) {
			node->isNodes[i] = false;
			empty(node->nextNodes[i]);
			delete node->nextNodes[i];
		}
	}
	
}

// Prints contents of the data structure.
void Datastructure::print() {
	if (count == 0) {
		return ;
	}
	Datastructure::print("", root, 0);
	cout<<endl;
}

// pre order recursion
unsigned long Datastructure::print(std::string partWord, data * node, unsigned long counter) {
	for (unsigned long i = 0; i < 26 && counter < count; i++) {
		if (node->isNodes[i]) {
			partWord.push_back((char)(i+97));
			if (node->nextNodes[i]->done) {
				counter++;
				cout << partWord;
				if (counter < count) {
					cout << SEPARATOR;
				}
				else {
					break;
				}
			}
			counter = print(partWord, node->nextNodes[i], counter);
			partWord.resize(partWord.size()-1);
		}
	}
	return counter;
}



