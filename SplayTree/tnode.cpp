#include "TNODE.H"

int tnode::get_field()
{
	return field_;
}

void tnode::set_field(int field)
{
	field_ = field;
}

tnode* tnode::get_right() 
{
	return right_;
}

void  tnode::set_right(tnode* node_value) 
{
	right_ = node_value;
}

tnode* tnode::get_left()
{
	return left_;
}

void  tnode::set_left(tnode* node_value)
{
	left_ = node_value;
}


