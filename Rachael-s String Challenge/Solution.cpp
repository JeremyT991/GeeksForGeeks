#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct entry {
    string word;
    int unique;
};

struct Node {
    entry value;
    Node* next;
};

class myClass {
	public:
	myClass();
	void readIn();
	void print(Node *pos, int position);
	void build();
	void insert(Node *pos, string s);
	bool poke(Node *pos, string s);
	int count(string s);
	void runQueries();
	
	Node *head;
	
	int length;
	int queries;
	string input;
	int totalEntries;
	vector<entry> myDictionary;
};

class distinct {
    public:
    distinct(string s);
    void sort();
    void swap(string &a, string &b);
    void count();
    vector<string> word;
    int value;
    int length;
};

void distinct::count() {
    value = 1;
    for (int i = 0; i < length -1; i++) {
        if (word[i] != word[i+1]) {
            value++;
        }
    }
    
}

void distinct::swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

void distinct::sort() {
    //int n = sizeof(word)/sizeof(word[0]);
    std::sort(word.begin(), word.end());
    /*for (int i = 0; i < length - 1; i++) {
        if (word[i] > word[i+1]) {
            swap(word[i], word[i+1]);
            i = -1;
        }
    }*/
    count();
}

distinct::distinct(string s) {
    length = s.length();
    word.resize(length);
    for (int i = 0; i < length; i++) {
        word[i] = s.substr(i,1);
    }
    sort();
}

int myClass::count(string s) {
    
    distinct dis(s);
    return dis.value;
}

bool myClass::poke(Node *pos, string s) { //return true if value is greater else false
    if (s < pos->value.word)
        return true;
    return false;
}

void myClass::insert(Node *pos, string s) {
    Node *myTemp = new Node;
    myTemp->value.word = s;
    myTemp->value.unique = count(s);
    myTemp->next = NULL;
    
    if (head == NULL) {
        head = myTemp;
        totalEntries++;
    } else if (s == pos->value.word) {
        //skip entry
    } else if (poke(pos, s)) { //insert
        Node *myTemp = new Node;
        myTemp->value.word = pos->value.word;
        myTemp->value.unique = pos->value.unique;
        myTemp->next = pos->next;
        
        pos->value.word = s;
        pos->value.unique = count(s);
        pos->next = myTemp;
        totalEntries++;
    } else { // move to next
            insert(pos->next, s);
    }
}

void myClass::build() {
    
    for (int i = length; i > 0; i--) {
        for (int j = 0; j < length - i + 1; j++) {
            insert(head, input.substr(j, i));
        }
    }
}

void myClass::readIn() {
    cin >> length;
    cin >> queries;
    cin >> input;
}

void myClass::runQueries() {
    int query;
    for (int i = 0; i < queries; i++) {
        cin >> query;
        if (query - 1 < totalEntries) {
            cout << myDictionary[query - 1].unique << endl;
        } else {
            cout << "-1" << endl;
        }
    }
}

void myClass::print(Node *pos, int position) {
    if (pos != NULL) {
        myDictionary[position].word = pos->value.word;
        myDictionary[position].unique = pos->value.unique;
        print(pos->next, position + 1);
    }
}

myClass::myClass() {
    head = NULL;
    totalEntries = 0;
	readIn();
	build();
	myDictionary.resize(totalEntries);
	print(head, 0);
	runQueries();
}

int main() {
	//code
	int t;
	cin >> t;
	
for (int i = 0; i < t; i++) {
	    myClass c;
	    cout << endl;
	}
	return 0;
}
