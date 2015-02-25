
/*
 * Fibonacci sequence
 * By Amirhossein Naemi
 * Febuary, 2015
 * GIT: https://github.com/amirhossein-naemi/Fibonacci
 * This program reads in one integer from a amir.in file and returns the
 * Fibonacci sequence
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

const int colbreaksize = 10;
const int colsize      = 7;

void print_output(ofstream & o, string txt) {
    cout << txt;
    o    << txt;
}

void open_input(ifstream & ifile, string ifilename, ofstream & err) {
    // Sanity check on the file stream
    ifile.open(ifilename.c_str());
    if (!ifile.is_open()) {
        print_output(err, "Error! Cannot open input file: " + ifilename + "\n");
        exit(0);
    }
    return;
}

void open_output(ofstream & o, string ofilename) {
    // Print on output file
    o.open(ofilename.c_str());
    if (!o.is_open()) {
        cout << "Error! The output file: " + ofilename + " is locked\n";
        exit(0);
    }
    return;
}

int main() {

    ofstream err;
    ofstream out;
    ifstream in;
    stringstream str;
    int max;
    unsigned long long fib   = 1;
    unsigned long long fib_1 = 0;
    unsigned long long fib_2 = 0;

    cout << "I was able to compile this code using the HPC at the University of"
         << " Memphis. When I compiled it there, it did not produce any warning"
         << " message. The HPC uses a GNU C++ compiler that can be considered a"
         << " good up to date standard. I also version­controlled this code"
         << " using git, and used a remote repository hosted by github. If I"
         << " can do this, so can you!!!\n\n";

    open_output(err, "amir.err");
    open_output(out, "amir.out");
    open_input(in, "amir.in", err);

    in >> max;

    if (max < 1) {
        print_output(err,
            "Error! input number should be equal or greater than 1\n");
		return 2;
	}

	str  << "I am so cool, that I was also able to write a code that produces"
		 << " the first " << endl << max
         << " numbers of the Fibonacci sequence. Here they are:\n\n";

    for (int i = 1; i <= max; i++) {

        if (i != 1) {
            fib = fib_1 + fib_2;
        }

        fib_2 = fib_1;
        fib_1 = fib;

        str << setw(colsize) << left << fib << "|";

        if (i % colbreaksize == 0)
            str << endl;
    }

    print_output(out, str.str());

    if (err.is_open())
        err.close();
    if (in.is_open())
        in.close();
    if (out.is_open())
        out.close();

    return 0;
}
