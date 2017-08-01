#include <cassert>
#include <iostream>
#include "sorted_sequence.h"

using namespace coen70_lab3;

namespace coen70_lab3 {

    sorted_sequence::sorted_sequence() {
        used = 0;
        current_index = 0;
    }

    void sorted_sequence::start() {
        current_index = 0;
    }

    void sorted_sequence::advance() {
        if (is_item()) {
            current_index++;
        } else {
            current_index = 0;
        }
    }

    void sorted_sequence::insert(const value_type& entry) {
        assert(size() < CAPACITY);
        
        //reset index to 0 to check through all values
        start();

        for (int i = 0; i < used; i++) {
            if (entry > data[i]) {
                current_index++;
            }
        }
        
        for (int i = used; i > current_index; i--) {
            data[i] = data[i - 1];
        }
        
        data[current_index] = entry;
        used++;
    }

    void sorted_sequence::remove_current() {
        if (is_item()) {
            for (int i = current_index; i < used - 1; i++) {
                data[i] = data[i + 1];
            }
            used--;
        }
    }

    void sorted_sequence::remove_front() {
        if (is_item()) {
            for (int i = 0; i < used - 1; i++) {

                data[i] = data[i + 1];
            }
            used--;
            current_index = 0;
        }
    }

    void sorted_sequence::end() {
        current_index = used - 1;
    }

    coen70_lab3::sorted_sequence::size_type sorted_sequence::size() const {
        return used;
    }

    bool sorted_sequence::is_item() const {
        //makes sure the sequence isn't empty and the index is valid
        return (used > 0 && current_index < used);
    }

    coen70_lab3::sorted_sequence::value_type sorted_sequence::current() const {
        assert(is_item());

        return data[current_index];
    }

    sorted_sequence operator+(sorted_sequence& lhs, sorted_sequence& rhs) {
        assert((lhs.size() + rhs.size()) < coen70_lab3::sorted_sequence::CAPACITY);

        sorted_sequence s3;

        s3 += lhs;
        s3 += rhs;

        return s3;
    }

    sorted_sequence operator+=(sorted_sequence& lhs, sorted_sequence& rhs) {
        assert((lhs.size() + rhs.size()) < coen70_lab3::sorted_sequence::CAPACITY);

        //reset rhs's index to 0
        rhs.start();

        for (int i = 0; i < rhs.size(); i++) {
            lhs.insert(rhs.current());
            rhs.advance();
        }

        return lhs;
    }
}
