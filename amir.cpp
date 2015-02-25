/*
 * Fibonacci sequence
 * By Amirhossein Naemi
 * Febuary, 2015
 * GIT: https://github.com/amirhossein-naemi/Fibonacci
 */

#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	cout << "I was able to compile this code using the HPC at the University of"
		<< " Memphis. When I compiled it there, it did not produce any warning "
		<< "message. The HPC uses a GNU C++ compiler that can be considered a "
		<< "good up to date standard. I also version­controlled this code using"
		<< " git, and used a remote repository hosted by github. If I can do "
		<< "this, so can you!!!\n";
	int max=30;
	unsigned long long fib = 1;
	unsigned long long fib_1 = 0;
	unsigned long long fib_2 = 0;
    
	cout << "\nI am so cool, that I was also able to write a code that produces"
		<< " the first " << max <<
		" numbers of the Fibonacci sequence. Here they are:\n\n";

	for (int i = 1; i <= max; i++) {

		if (i != 1)
			fib = fib_1 + fib_2;
		fib_2 = fib_1;
		fib_1 = fib;

		cout << fib << " ";
	}

	return 0;
}
