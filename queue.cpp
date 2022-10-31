#include <iostream>

/*
    Очередь.

    Необходимо разработать программу, реализующую работу с очередью.

    Программа должна содержать функции:
        вставки
        извлечения

    Необходимо предусмотреть: 
        контроль на переполнение
        контроль на отсутствие элементов
        отображение на экране значения извлекаемого элемента
*/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int num = 3;
class My_queue {
private:
    int* mass;
    int begin_element;
    int last_element;
public:
    My_queue()
    {
        mass = new int[num];
        begin_element = 0;
        last_element = 0;
    }
    My_queue(int num_el)
    {
        num = num_el;
        begin_element = 0;
        last_element = 0;
        mass = new int[num_el];
    }

    void enter_element(int element)
    {
        mass[last_element] = element;
        last_element = (last_element + 1) % num;
    }
    bool My_queue_is_empty()
    {
        return  begin_element == last_element;
    }
    bool My_queue_is_full()
    {
        return  begin_element == (last_element + 1) % num;
    }

    int extract_element()
    {
        return mass[begin_element++];
    }

    ~My_queue()
    {
        delete[] mass;
    }
};
int main()
{
    cout << "Task 'queue'" << endl;
    int n;
    int  element;
    int answer;
    char repeat;
    cout << "Enter the number of element: ";
    cin >> n;
    My_queue  mass(++n);
    do
    {

        cout << "Enter operation number:\n 1.Enter element.\n 2.Delete element.\n Value: ";
        cin >> answer;
        switch (answer)
        {
        case 1:
            if (mass.My_queue_is_full() == 0)
            {
                cout << "Enter the element: ";
                cin >> element;
                mass.enter_element(element);
            }
            else
                cout << "queue is full" << endl;
            break;
        case 2:
            if (mass.My_queue_is_empty() == 0)
            {
               cout << "Element: " <<  mass.extract_element() << endl;
            }
            else
                cout << "queue is empty" << endl;
            break;
        default:
            cout << "Error! No such operation!" << endl;
        }
        cout << "Repeat operation? (y/n)" << endl;
        cout << "Answer: ";
        cin >> repeat;
    } while (repeat != 'n');
    return 0;
}           