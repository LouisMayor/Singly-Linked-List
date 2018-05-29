#pragma once

#include <iostream>
#include <cassert>
#include "PositionNode.h"

using uint = unsigned int;

class SingleLinkedList {
public:
	SingleLinkedList( ) = default;
	~SingleLinkedList( ) { clear( ); }

	static PosNode* allocate_node( const PosNode& _input );
	void insert( uint _index, PosNode* const _input );
	void push_front( PosNode* const _input );
	void push_back( PosNode* const _input );

	__forceinline uint size( ) const { return list_size; }
	void clear( );
	void print( );
private:
	SingleLinkedList& operator= ( const SingleLinkedList& ) = delete;
	SingleLinkedList( const SingleLinkedList& ) = delete;
private:
	PosNode* root = nullptr;
	uint list_size = 0;
};

// preferred method of allocating memory instead of passing pointers,
// because this list already handles deletes and looks cleaner
PosNode* SingleLinkedList::allocate_node( const PosNode& _input ) {
	PosNode* tmp = new PosNode( _input );
	return tmp;
}

void SingleLinkedList::insert( uint _index, PosNode* const _input ) {
	assert( ("node is null", _input != nullptr) );
	assert( ("use push_front() instead", _index != 0) );
	assert( ("index too large", (_index > 0 && _index < list_size)) );

	list_size++;
	PosNode* current  = root;
	PosNode* previous = root;
	uint counter = 0;
	while( counter < _index ) {
		counter++;
		if( current->next != nullptr ) {
			previous = current;
		}
		current = current->next;
	}
	previous->next = _input;
	_input->next = current;
}

void SingleLinkedList::push_front( PosNode* const _input ) {
	assert( ("node is null", _input != nullptr) );
	list_size++;
	_input->next = root;
	root = _input;
}

void SingleLinkedList::push_back( PosNode* const _input ) {
	assert( ("node is null", _input != nullptr) );
	// resolve root node
	list_size++;
	if( root == nullptr ) {
		root = _input;
		return;
	}
	if( root->next == nullptr ) {
		root->next = _input;
		return;
	}
	// resolve child nodes
	PosNode* tmp = root;
	while( tmp->next != nullptr ) {
		tmp = tmp->next;		
	}
	tmp->next = _input;	
}

// clears linked list. i.e. deletes all memory
// also called in destructor, just in case
void SingleLinkedList::clear( ) {
	list_size = 0;
	if( root == nullptr ) {
		return;
	}
	// find if list length is greater than 1
	if( root->next != nullptr ) {
		PosNode* tmp = root;
		PosNode* old_node = nullptr;
		while( tmp->next != nullptr ) {
			old_node = tmp;
			tmp = old_node->next;
			delete old_node;
		}
		delete tmp;
	} else {
		delete root;
	}
	// fyi, always remember to point to null
	root = nullptr;
}

void SingleLinkedList::print( ) {
	PosNode* tmp = root;
	uint counter = 0;
	while( tmp != nullptr ) {		
		std::printf( "Node %u: %f, %f, %f\n", counter+1, tmp->GetData().x, tmp->GetData( ).y, tmp->GetData( ).z );
		counter++;
		tmp = tmp->next;
	}
}