#pragma once

class tnode//класс узла
{

    int field_;// поле данных
    tnode* left_;// левый потомок
    tnode* right_;// правый потомок

public:

    int get_field();
    void set_field(int field);

    tnode* get_right();
    void set_right(tnode* node_value);
    
    tnode* get_left();
    void set_left(tnode* node_value);

};