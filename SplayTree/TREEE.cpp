#include "TREEE.H"



tnode* TREEE::leftRotate(tnode* x)
{
    tnode* y = x->get_right();
    x->set_right(y->get_left());
    y->set_left(x);
    return y;
}

tnode* TREEE::rightRotate(tnode* x)
{
    tnode* y = x->get_left();
    x->set_left(y->get_right());
    y->set_right(x);
    return y;
}
///////////////
tnode* TREEE::ifprav(tnode* tree, int field)
{

    if (tree->get_right() == NULL) // ���� �� � ������, �� ��������� 
        return tree;
    if (tree->get_right()->get_field() > field)// Zag-Zig (����� ����)
    {
        tree->get_right()->set_left(splay(tree->get_right()->get_left(), field));// ��������� ���� ��� ������ ������-�����
        if (tree->get_right()->get_left() != NULL)// �������� ������ ������� ��� root-> get_right()
            tree->set_right(rightRotate(tree->get_right()));
    }
    else if (tree->get_right()->get_field() < field)// Zag-Zag (�����-�����) 
    {
        tree->get_right()->set_right(splay(tree->get_right()->get_right(), field));// ��������� ���� ��� ������ ������-������ � �������� ������ �������
        tree = leftRotate(tree);
    }
    return (tree->get_right() == NULL) ? tree : leftRotate(tree);// �������� ������ ������� ��� �����
}

tnode* TREEE::iflev(tnode* tree, int field)
{
    if (tree->get_left() == NULL)// ���� �� � ������, �� ��������� 
        return tree;
    if (tree->get_left()->get_field() > field)// Zig-Zig (C����-C����)
    {
        tree->get_left()->set_left(splay(tree->get_left()->get_left(), field)); // ������� ���������� ������� ���� ��� ������ ������-������
        tree = rightRotate(tree);// ������ ������ �������� ��� �����, ������ �������� ����������� ����� else
    }
    else if (tree->get_left()->get_field() < field) // Zig-Zag (���� �����)
    {
        tree->get_left()->set_right(splay(tree->get_left()->get_right(), field)); //  ������� ���������� ����� ���� ��� ������ ������-�������
        if (tree->get_left()->get_right() != NULL)// ������ ������ ������� ��� root-> get_left()  
            tree->set_left(leftRotate(tree->get_left()));
    }
    return (tree->get_left() == NULL) ? tree : rightRotate(tree);// ������ ������ ������� ��� �����
}

tnode* TREEE::pomosh_v_find(tnode* tree)
{
    if (tree != NULL) //���� �� ���������� ������ ����
    {
        pomosh_v_find(tree->get_left()); //����������� ������� ��� ������ ���������
        pomosh_v_find(tree->get_right()); //����������� ������� ��� ������� ���������
    }
    return tree;
}


tnode* TREEE::splay(tnode* tree, int field)//����������� ������� ������
{
    if ((tree == NULL) || (tree->get_field() == field))// ������� ������: ������ ����� NULL ��� ���� ������������ � �����
        return tree;
    if (tree->get_field() > field)// ���� ����� � ����� ���������
    {
        tree = iflev(tree, field);
    }
    else   // ���� ����� � ������ ���������
        {
        tree = ifprav(tree, field);
        }
}
    


    tnode* TREEE::create(int x, tnode* tree)
    {
        if (tree == NULL) // ���� ������ ���, �� ��������� ������
        {
            tree = new tnode; //������ ��� ����
            tree->set_field(x);   //���� ������
            tree->set_left(NULL);
            tree->set_right(NULL); //����� �������������� ��������
        }
        else  if (x < tree->get_field()) //������� ���������� ������ �������
        {
            tree->set_left(create(x, tree->get_left()));
        }

        else    //������� ���������� ������� �������
        {
            tree->set_right(create(x, tree->get_right()));
        }
        return(tree);
    }

    
tnode* TREEE::del(tnode* tree, int x) // ��������
{
    if (tree == NULL)
        return tree;
    if (x < tree->get_field())
        tree->set_left(del(tree->get_left(), x));
    else
        if (x > tree->get_field())
            tree->set_right(del(tree->get_right(), x));
        else
            if ((tree->get_left() != NULL) && (tree->get_right() != NULL))
            {
                tree->set_field(tree->get_right()->get_field());
                tree->set_right(del(tree->get_right(), tree->get_field()));
            }
            else
                if (tree->get_left() != NULL)
                    tree = tree->get_left();
        else 
            if (tree->get_right() != NULL)
            tree = tree->get_right();
        else
                tree = NULL;
            return tree;
}
                

    void TREEE::find(tnode* tree, int& x)//����� �������� � ������
    {
        if (tree != NULL)//���� ������ �� ������...
        {
            if (x < tree->get_field())//������� ��� ���� �, ���� ��� ������ ��� ������, ��...
                find(tree->get_left(), x);//...���������� �����
            if (x > tree->get_field())//���� ������ ��� ������, ��...
                find(tree->get_right(), x);//...���������� ������
            if (x == tree->get_field())//���� �� ��� �����
            {
                cout << "�����! ������� " << x << " ������������ � ������!\n";//�� ������� ���������
            }
        }
        else//�����...
        {
            cout << "�������� �������� ��� ���� ���\n";//������� � ���, ��� � ������ ����� �������� ���
            x += 1;
        }
    }

    void TREEE::treeprint(tnode* tree)//������ ����� ������
    {
        if (tree != NULL) //���� �� ���������� ������ ����
        {
            cout << tree->get_field() << " "; //���������� ������ ������
            treeprint(tree->get_left()); //����������� ������� ��� ������ ���������
            treeprint(tree->get_right()); //����������� ������� ��� ������� ���������
        }
    }

    tnode* TREEE::clear(tnode* tree)//�������� ���������
    {
        if (tree != NULL)
        {
            clear(tree->get_left());
            clear(tree->get_right());
            delete tree; 
        }
        tree = NULL;

        return tree;
    }