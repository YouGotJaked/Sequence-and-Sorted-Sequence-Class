// FILE: sequence.h
// CLASS PROVIDED: sequence (part of the namespace scu_coen70)
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
// typedef ____ value_type
// sequence::value_type is the data type of the items in the
// sequence. It may be any of the C++ built-in types (int, char,
// etc.), or a class with a default constructor, an assignment
// operator, and a copy constructor. 
// 
// typedef ____ size_type 
// sequence::size_type is the data type of any variable that keeps 
// track of how many items are in a sequence. 
// 
// static const size_type CAPACITY = _____ 
// sequence::CAPACITY is the maximum number of items that a sequence 
// can hold. 
// 
// CONSTRUCTOR for the sequence class: 
// sequence( ) 
// Postcondition: The sequence has been initialized as an empty sequence. 
// 
// MODIFICATION MEMBER FUNCTIONS for the sequence class: 
// void start( ) 
// Postcondition: The first item on the sequence becomes the current 
// item(but if the sequence is empty, then there is no current item). 
// 
// void advance( ) 
// Precondition: is_item returns true. 
// Postcondition: If the current item was already the last item in the 
// sequence, then there is no longer any current item. Otherwise, the 
// new current item is the item immediately after the original current
// item. 
// 
// void insert(const value_type& entry) 
// Precondition: size( ) < CAPACITY. 
// Postcondition: A new copy of entry has been inserted in the 
// sequence before the current item. If there was no current item, 
// then the new entry has been inserted at the front of the sequence. 
// In either case, the newly inserted item is now the current item of 
// the sequence. 
// 
// void attach(const value_type& entry) 
// Precondition: size( ) < CAPACITY. 
// Postcondition: A new copy of entry has been inserted in the 
// sequence after the current item. If there was no current item, then 
// the new entry has been attached to the end of the sequence. In 
// either case, the newly inserted item is now the current item of the 
// sequence. 
// 
// void remove_current( ) 
// Precondition: is_item returns true. 
// Postcondition: The current item has been removed from the sequence, 
// and the item after this (if there is one) is now the new current item. 
// 
// void insert_front( )
// Precondition: size() < CAPACITY
// Postcondition: A new value has been inserted at the front of the sequence.
// This new item is now the current item.
//
// void remove_front( )
// Precondition: is_item returns true.
// Postcondition: The value at the front of the sequence has been removed. The
// new front item is now the current item.
//
// void attach_back( )
// Precondition: size() < CAPACITY
// Postcondition: A new value has been inserted at the back of the sequence. The 
// new item is now the current item.
// 
// void end( )
// Postcondition: The last item in the sequence is now the current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class: 
// size_type size( ) const 
// Postcondition: The return value is the number of items in the 
// sequence. 
// 
// bool is_item( ) const 
// Postcondition: A true return value indicates that there is a valid 
// "current" item that may be retrieved by activating the current 
// member function (listed below). A false return value indicates that 
// there is no valid current item. 
// 
// value_type current( ) const 
// Precondition: is_item( ) returns true. 
// Postcondition: The item returned is the current item in the 
// sequence. 
// 
// size_type index( ) const
// Postcondition: The return value is the current index of the sequence
// 
// NON-MEMBER FUNCTIONS for the sequence class: 
// sequence operator+(sequence& lhs, sequence& rhs)
// Precondition: The sum of the sizes of the two sequences being added is
// smaller than the CAPACITY of a sequence.
// Postcondition: A new sequence is returned with the data of rhs being added
// to that of lhs
//
// sequence operator+=(sequence& lhs, sequence& rhs)
// Precondition: The sum of the sizes of the two sequences being added is
// smaller than the CAPACITY of a sequence.
// Postcondition: The new lhs sequence is returned with the data of rhs
// now attached to the back.

#ifndef SEQUENCE_H
#define	SEQUENCE_H
#include <cstdlib>

namespace coen70_lab3 {
    
    class sequence {
        
    public:
        //Typedef and member constants
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 50;
        
        //Constructor
        sequence();
        
        //Modification member functions
        void start();
        void advance();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        void insert_front(const value_type& entry);
        void remove_front();
        void attach_back(const value_type& entry);
        void end();
        
        //Constant member functions
        size_type size() const;
        bool is_item() const;
        value_type current() const;
        size_type index() {
            return current_index;
        }
        
    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
    };
    
    //Non-member functions
    sequence operator+(sequence& lhs, sequence& rhs);
    sequence operator+=(sequence& lhs, sequence& rhs);
}

#endif

