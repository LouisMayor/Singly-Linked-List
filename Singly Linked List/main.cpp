#include "SinglyLinkedList.h"
#include <iostream>

int main( ) {
	std::printf( "Linked List example:\n" );

	SingleLinkedList list;
	if( true ) {
		std::printf( "\nExample one:\n" );
		list.push_back( SingleLinkedList::allocate_node( PosNode( 10.0f, 423.0f, 438.0f ) ) );
		list.push_back( SingleLinkedList::allocate_node( PosNode( 15.0f, 623.0f, 1438.0f ) ) );
		list.push_back( SingleLinkedList::allocate_node( PosNode( 55.0f, 253.0f, 10.0f ) ) );
		list.insert( 1, SingleLinkedList::allocate_node( PosNode( 105.0f, 915.0f, 60.0f ) ) );

		std::printf( "\nlist size: %u\n", list.size( ) );
		list.print( );
		list.clear( );
	}

	if( true ) {
		std::printf( "\nExample two:\n" );
		list.push_back( SingleLinkedList::allocate_node( PosNode( 10.0f, 423.0f, 438.0f ) ) );
		list.push_back( SingleLinkedList::allocate_node( PosNode( 15.0f, 623.0f, 1438.0f ) ) );
		list.push_back( SingleLinkedList::allocate_node( PosNode( 55.0f, 253.0f, 10.0f ) ) );
		list.push_back( SingleLinkedList::allocate_node( PosNode( 435.0f, 15.0f, 1230.0f ) ) );
		list.push_back( SingleLinkedList::allocate_node( PosNode( 4895.0f, 645.0f, 10.0f ) ) );
		list.insert( 1, SingleLinkedList::allocate_node( PosNode( 105.0f, 915.0f, 60.0f ) ) );
		list.push_front( SingleLinkedList::allocate_node( PosNode( 69.0f, 69.0f, 69.0f ) ) );

		std::printf( "\nlist size: %u\n", list.size( ) );
		list.print( );
		list.clear( );
	}

	std::cin.get( );
	return 0;
}