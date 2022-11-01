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

    if (tree->get_right() == NULL) // Ключ не в дереве, мы закончили 
        return tree;
    if (tree->get_right()->get_field() > field)// Zag-Zig (Право Лево)
    {
        tree->get_right()->set_left(splay(tree->get_right()->get_left(), field));// Принесите ключ как корень справа-слева
        if (tree->get_right()->get_left() != NULL)// Сделайте первый поворот для root-> get_right()
            tree->set_right(rightRotate(tree->get_right()));
    }
    else if (tree->get_right()->get_field() < field)// Zag-Zag (Право-Право) 
    {
        tree->get_right()->set_right(splay(tree->get_right()->get_right(), field));// Принесите ключ как корень вправо-вправо и сделайте первый поворот
        tree = leftRotate(tree);
    }
    return (tree->get_right() == NULL) ? tree : leftRotate(tree);// Сделайте второй поворот для корня
}

tnode* TREEE::iflev(tnode* tree, int field)
{
    if (tree->get_left() == NULL)// Ключ не в дереве, мы закончили 
        return tree;
    if (tree->get_left()->get_field() > field)// Zig-Zig (Cлева-Cлева)
    {
        tree->get_left()->set_left(splay(tree->get_left()->get_left(), field)); // Сначала рекурсивно введите ключ как корень левого-левого
        tree = rightRotate(tree);// Делаем первое вращение для корня, второе вращение выполняется после else
    }
    else if (tree->get_left()->get_field() < field) // Zig-Zag (Лево Право)
    {
        tree->get_left()->set_right(splay(tree->get_left()->get_right(), field)); //  Сначала рекурсивно введём ключ как корень левого-правого
        if (tree->get_left()->get_right() != NULL)// Делаем первый поворот для root-> get_left()  
            tree->set_left(leftRotate(tree->get_left()));
    }
    return (tree->get_left() == NULL) ? tree : rightRotate(tree);// Делаем второй поворот для корня
}

tnode* TREEE::pomosh_v_find(tnode* tree)
{
    if (tree != NULL) //Пока не встретится пустой узел
    {
        pomosh_v_find(tree->get_left()); //Рекурсивная функция для левого поддерева
        pomosh_v_find(tree->get_right()); //Рекурсивная функция для правого поддерева
    }
    return tree;
}


tnode* TREEE::splay(tnode* tree, int field)//Специальная функция дерева
{
    if ((tree == NULL) || (tree->get_field() == field))// Базовые случаи: корень равен NULL или ключ присутствует в корне
        return tree;
    if (tree->get_field() > field)// Ключ лежит в левом поддереве
    {
        tree = iflev(tree, field);
    }
    else   // Ключ лежит в правом поддереве
        {
        tree = ifprav(tree, field);
        }
}
    


    tnode* TREEE::create(int x, tnode* tree)
    {
        if (tree == NULL) // Если дерева нет, то формируем корень
        {
            tree = new tnode; //Память под узел
            tree->set_field(x);   //Поле данных
            tree->set_left(NULL);
            tree->set_right(NULL); //Ветви инициализируем пустотой
        }
        else  if (x < tree->get_field()) //Условие добавление левого потомка
        {
            tree->set_left(create(x, tree->get_left()));
        }

        else    //Условие добавление правого потомка
        {
            tree->set_right(create(x, tree->get_right()));
        }
        return(tree);
    }

    
tnode* TREEE::del(tnode* tree, int x) // удаление
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
                

    void TREEE::find(tnode* tree, int& x)//Поиск элемента в дереве
    {
        if (tree != NULL)//Если дерево не пустое...
        {
            if (x < tree->get_field())//Смотрим что ищем и, если оно меньше чем корень, то...
                find(tree->get_left(), x);//...спускаемся влево
            if (x > tree->get_field())//Если больше чем корень, то...
                find(tree->get_right(), x);//...спускаемся вправо
            if (x == tree->get_field())//Если мы его нашли
            {
                cout << "Нашёл! Элемент " << x << " присутствует в дереве!\n";//то выводим сообщение
            }
        }
        else//иначе...
        {
            cout << "Искомого элемента тут явно нет\n";//говорим о том, что в дереве этого элемента нет
            x += 1;
        }
    }

    void TREEE::treeprint(tnode* tree)//Прямой обход дерева
    {
        if (tree != NULL) //Пока не встретится пустой узел
        {
            cout << tree->get_field() << " "; //Отображаем корень дерева
            treeprint(tree->get_left()); //Рекурсивная функция для левого поддерева
            treeprint(tree->get_right()); //Рекурсивная функция для правого поддерева
        }
    }

    tnode* TREEE::clear(tnode* tree)//Удаление поддерева
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