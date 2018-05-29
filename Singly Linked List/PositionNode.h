#pragma once

struct PosData {
	PosData( const float _X, const float _Y, const float _Z ) {
		x = _X;
		y = _Y;
		z = _Z;
	}
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

class PosNode {
public:
	PosNode( ) = default;
	PosNode( const float, const float, const float );
	PosNode( const PosNode& );
	PosNode( const PosNode&& );
	PosData GetData( );
	PosNode& operator= ( const PosNode& );
private:		
public:
	PosNode* next = nullptr;
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

PosNode::PosNode( const float _X, const float _Y, const float _Z ) {
	x = _X;
	y = _Y;
	z = _Z;
}

PosNode::PosNode( const PosNode& _input ) {
	x = _input.x;
	y = _input.y;
	z = _input.z;
}

PosNode::PosNode( const PosNode&& _input ) {
	x = _input.x;
	y = _input.y;
	z = _input.z;
}

PosData PosNode::GetData( ) {
	PosData tmp( x, y, z );
	return tmp;
}

PosNode& PosNode::operator= ( const PosNode& _input ) {
	x = _input.x;
	y = _input.y;
	z = _input.z;
	return (*this);
}