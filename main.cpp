/* 
 * File:   main.cpp
 * Author: jakeday
 *
 * Created on April 26, 2017, 12:05 PM
 */

#include <cstdlib>
#include <iostream>
#include "sequence.h"
#include "sorted_sequence.h"

using namespace coen70_lab3;
void print_sequence(const sorted_sequence &s);
void print_sequence(const sequence &s);

/*
 * 
 */
int main(int argc, char** argv) {
    
    sorted_sequence s0;
    std::cout << "size: " << s0.size() << std::endl;
    s0.insert(20);
    print_sequence(s0);
    s0.insert(15);
    print_sequence(s0);
    s0.insert(25);
    print_sequence(s0);
    s0.insert(1);
    print_sequence(s0);
    s0.remove_current();
    print_sequence(s0);
    std::cout << "size: " << s0.size() << std::endl;
    sorted_sequence s1,s2;
    s1.insert(5);
    s1.insert(2);
    std::cout << "size s: " << s0.size() << std::endl;
    std::cout << "size s1: " << s1.size() << std::endl;
    std::cout << "size s2: " << s2.size() << std::endl;
    s2 = s0 + s1;
    std::cout << "size s2 new: " << s2.size() << std::endl;
    print_sequence(s2);
    
    sorted_sequence ss;
    ss.insert(4);
    ss.insert(2);
    print_sequence(ss);
    
    sorted_sequence s;
    std::cout << s.size() << std::endl;
    s.insert(10);
    std::cout << "1=" << s.is_item() << std::endl;
    print_sequence(s);
    s.insert(15);
    print_sequence(s);
    s.insert(25);
    print_sequence(s);
    for (int i = 30; i <= 50; i += 5) {
        s.insert(i);
        print_sequence(s);
    }
    for (int i = 3; i <= 27; i += 3) {
        s.insert(i);
        s.advance();
        print_sequence(s);
    }
    s.remove_current();
    print_sequence(s);
    s.remove_front();
    print_sequence(s);
    s.insert(911);
    print_sequence(s);
    s.insert(4411);
    print_sequence(s);
    sorted_sequence r;
    for (double i = 3.1415; i < 100; i = i * 2) {
        r.insert(i);
    }
    print_sequence(r);
    std::cout << std::endl;
    sorted_sequence q = s + r;
    print_sequence(q);
    std::cout << (q).size() << std::endl;
    s += r;
    print_sequence(s);
    return 0;
    
}

void print_sequence(const sorted_sequence &s) {

	std::cout << "[";
	for(int i = 0; i < s.size(); i++){
		std::cout << s[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void print_sequence(const sequence &s) {

	std::cout << "[";
	for(int i = 0; i < s.size(); i++){
		std::cout << s[i] << " ";
	}
	std::cout << "]" << std::endl;
}
