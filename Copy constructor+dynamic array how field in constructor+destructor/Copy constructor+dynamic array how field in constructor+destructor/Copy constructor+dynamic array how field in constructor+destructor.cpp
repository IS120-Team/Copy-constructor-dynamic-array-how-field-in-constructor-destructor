#include <iostream>
#include <tuple>
using namespace std;

class Test1
{
private:
    int* data;
    int size;
public:
    Test1(int size)
    {
        this->size = size;
        this->data = new int[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }
    };

    Test1(const Test1& object)
    {
        this->data = new int[object.size];
        this->size = object.size;

        for (int i = 0; i < object.size; i++)
        {
            this->data[i] = object.data[i];
        }
    }

    void fillingFields()
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = rand() % 100;
        }
    }

    void overviewData()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << "\t";
        }
    }

    ~Test1()
    {
        delete[]data;
    };
};

void Foo(Test1 value)
{
    cout << "Foo1" << endl;

}

Test1 Foo2()
{
    cout << "¬ведите размер вашего массива" << endl;
    int number;
    cin >> number;
    Test1 object1(number);
    return object1;
}

int main()
{
    setlocale(LC_ALL, "rus");


    Test1 a(Foo2());
    a.fillingFields();
    a.overviewData();
}