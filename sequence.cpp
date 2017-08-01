#include <cassert>
#include <iostream>
#include "sequence.h"

using namespace coen70_lab3;

namespace coen70_lab3 {

    sequence::sequence() {
        used = 0;
        current_index = 0;
    }

    void sequence::start() {
        current_index = 0;
    }

    void sequence::advance() {
        if (is_item()) {
            current_index++;
        }
        else {
            current_index = 0;
        }
    }

    void sequence::insert(const value_type& entry) {
        assert(size() < CAPACITY);

        if (is_item()) {
            for (int i = used; i > current_index; i--) {
                data[i] = data[i - 1];
            }
            data[current_index] = entry;
            used++;
        } else {
            insert_front(entry);
        }  
    }

    void sequence::attach(const value_type& entry) {
        assert(size() < CAPACITY);

        if (is_item()) {
            for (int i = used; i > current_index; i--) {
                data[i] = data[i + 1];
            }
            data[(current_index) + 1] = entry;
            used++;
        } else {
            attach_back(entry);
        }
    }

    void sequence::remove_current() {
        if (is_item()) {
            for (int i = current_index; i < used - 1; i++) {
                data[i] = data[i + 1];
            }
            used--;
        }
    }

    void sequence::insert_front(const value_type& entry) {
        assert(size() < CAPACITY);
        
        for (int i = used - 1; i >= 0; i--) {
            data[i + 1] = data[i];
        }

        data[0] = entry;
        used++;
        current_index = 0;
    }

    void sequence::remove_front() {
        if (is_item()) {
            for (int i = 0; i < used - 1; i++) {
                data[i] = data[i + 1];
            }
            used--;
            current_index = 0;
        }
    }

    void sequence::attach_back(const value_type& entry) { 
        assert(size() < CAPACITY);
        data[used++] = entry;
        current_index++;
    }

    void sequence::end() {
        current_index = used - 1;
    }

    coen70_lab3::sequence::size_type sequence::size() const {
        return used;
    }

    bool sequence::is_item() const {
        //makes sure the sequence isn't empty and the index is valid
        return (used > 0 && current_index < used);
    }

    coen70_lab3::sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_index];
    }

    sequence operator+(sequence& lhs, sequence& rhs) {
        assert((lhs.size() + rhs.size()) < coen70_lab3::sequence::CAPACITY);

        sequence s3;
        
        s3 += lhs;
        s3 += rhs;

        return s3;
    }

    sequence operator+=(sequence& lhs, sequence& rhs) {
        assert((lhs.size() + rhs.size()) < coen70_lab3::sequence::CAPACITY);
       
        //reset rhs's index to 0
        rhs.start();
        
        for (int i = 0; i < rhs.size(); i++) {
            lhs.attach_back(rhs.current());
            rhs.advance();
        }

        return lhs;
    }
}