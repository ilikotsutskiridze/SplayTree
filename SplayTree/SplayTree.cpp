#include "TREEE.H"

int main()
{
    setlocale(LC_ALL, "Russian");//добавим русский язык
    TREEE treee;
    treee.minitree = NULL;
    string iter="";
    bool exit=true;

    while (exit)
    {
        cout << "Выберете, что хотите сделать:\n\n";
        cout << "Напишите <Create>, чтобы создать дерево\n";
        cout << "Напишите <Add>, чтобы добавить элемент в дерево\n";
        cout << "Напишите <Delete>, чтобы удалить узел\n";
        cout << "Напишите <Find>, чтобы найти элемент в дереве\n";
        cout << "Напишите <Clear>, чтобы удалить дерево и очистить память \n";
        cout << "Напишите <End>, чтобы завершить программу\n\n";

        cin >> iter;

        if (iter == "Create")
        {
            int n; //Количество элементов
            int s; //Число, передаваемое в дерево

            cout << "Введите количество элементов: ";
            cin >> n; //Вводим количество элементов

            for (size_t i = 0; i < n; ++i)
            {
                cout << "Ведите очередной элемент:  ";
                cin >> s; //Считываем элемент...

                treee.minitree=treee.create(s, treee.minitree); //... и каждый кладем в дерево
                treee.minitree = treee.splay(treee.minitree, s);
            }
            cout << "Ваше дерево: ";
            treee.treeprint(treee.minitree);
            cout << "\n";
        }
        else
            if (iter == "Add")
            {
                int s; //Число, передаваемое в дерево

                cout << "Ведите очередной элемент:  ";
                cin >> s; //Считываем элемент...

                treee.minitree = treee.create(s, treee.minitree); //... и каждый кладем в дерево
                treee.minitree = treee.splay(treee.minitree, s);

                cout << "Ваше дерево: ";
                treee.treeprint(treee.minitree);
                cout << "\n";
            }
            else
                if (iter == "Delete")
                {
                    int s; 

                    cout << "Ведите элемент, который хотите удалить: ";
                    cin >> s; //Считываем элемент...

                    TREEE treee1;
                    treee1.minitree = treee.pomosh_v_find(treee.minitree);
                    treee.minitree = treee.splay(treee.minitree, s);

                    treee.minitree = treee.del(treee.minitree, s);

                    treee1.minitree = treee.pomosh_v_find(treee.minitree);
                    treee.minitree = treee.splay(treee.minitree, s);
                    cout << "Ваше дерево: ";
                    treee.treeprint(treee.minitree);
                }
                else
                    if (iter == "Find")
                    {
                        int chi;
                        cout << "Введите искомый элемент: ";
                        cin >> chi;
                        int chi0 = chi;
                        treee.find(treee.minitree, chi0);

                        if (chi0 == chi)//если элемент есть...
                        {
                            treee.minitree = treee.splay(treee.minitree, chi);
                            cout << "Ваше дерево: ";
                            treee.treeprint(treee.minitree);
                        }
                        else//если его там нет... :(
                        {
                            TREEE treee1;
                            treee1.minitree = treee.pomosh_v_find(treee.minitree);
                            treee.minitree = treee.splay(treee1.minitree, chi);
                            cout << "Ваше дерево: ";
                            treee.treeprint(treee.minitree);
                        }

                        cout << "\n";
                    }
                    else
                        if (iter == "Clear")
                        {
                            string sogl = "";
                            cout << "Хотите ли вы удалить дерево? (Введите yes/no)\n";
                            cin >> sogl;
                            if (sogl == "yes")
                            {
                                treee.minitree = treee.clear(treee.minitree);
                                treee.treeprint(treee.minitree);
                                cout << "Память очищена\n";
                            }
                            else
                                cout << "Тогда продолжим...\n";
                        }
                        else
                            if (iter == "End")
                            {
                                cout << "Спасибо за внимание!\n";
                                exit = 0;
                            }
        cout << "\n\n";
    }
}