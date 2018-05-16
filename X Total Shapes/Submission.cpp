#include <iostream>
using namespace std;

class primes {
    public:
    int myPrime;
    int a;
    int b;
    
    primes();
    bool isPrime(int n);
    void print();
};

bool primes::isPrime(int n) {
    for (int i = 3; i < n/2 + 1; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void primes::print() {
    cout << a << " " << b << endl;
}

primes::primes() {
    cin >> myPrime;
    
    for (int i = 2; i < myPrime / 2; i++) {
        if (isPrime(i)) {
            if (isPrime(myPrime - i)) {
                a = i;
                b = myPrime - i;
                break;
            }
        }
    }
    
    print();
}

int main() {
	//code
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
	    primes p;
	}
	return 0;
}
