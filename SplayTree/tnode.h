#pragma once

class tnode//����� ����
{

    int field_;// ���� ������
    tnode* left_;// ����� �������
    tnode* right_;// ������ �������

public:

    int get_field();
    void set_field(int field);

    tnode* get_right();
    void set_right(tnode* node_value);
    
    tnode* get_left();
    void set_left(tnode* node_value);

};