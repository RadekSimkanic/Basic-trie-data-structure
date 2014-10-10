# include <string>

const char SEPARATOR = ' ';

struct data {
	bool done = false;
	bool isNodes[26] = {
		false, false, false, false, false, false, false, false, 
		false, false, false, false, false, false, false, false, 
		false, false, false, false, false, false, false, false, 
		false, false
	};
	data * nextNodes[26];
	//data * parent; // for removing cache
	//short numberSet = 0; // for removing cache
};

class Datastructure {
private:
	data * root;
	data * tmp;
	unsigned int count;

public:

	Datastructure();

	~Datastructure();

	// Returns true if word was added and false otherwise.
	bool add(std::string word);

	// Returns true if word was removed and false otherwise.
	bool remove(std::string word);

	// Returns true if word was found and false otherwise.
	bool search(std::string word);

	// Solves and returns amount of words in datastructure.
	unsigned int amountOfWords();

	// Empties the datastructure.
	void empty();

	// Prints contents of the data structure.
	void print();

private:
	// Copy constructor is forbidden
	Datastructure(const Datastructure&);
	// Assignment operator is forbidden
	Datastructure& operator=(const Datastructure&);

	
	// Find node for next operation
	bool findNode(std::string word, bool creating);
	
	void empty(data * node);
	
	unsigned long print(std::string partWord, data * node, unsigned long counter);

};

