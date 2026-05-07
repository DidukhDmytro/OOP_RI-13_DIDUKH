#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Array
{
private:
    T* data;
    int size;

public:
    Array();
    Array(int size);
    Array(const Array<T>& other);
    ~Array();

    int GetSize() const;

    Array<T>& operator=(const Array<T>& other);
    T& operator[](int index);
    const T& operator[](int index) const;

    template <class U>
    friend ostream& operator<<(ostream& out, const Array<U>& arr);

    template <class U>
    friend istream& operator>>(istream& in, Array<U>& arr);
};

template <class T>
Array<T>::Array() : data(nullptr), size(0)
{
}

template <class T>
Array<T>::Array(int size)
{
    if (size < 0)
        throw invalid_argument("Size cannot be negative");

    this->size = size;
    data = new T[size];

    for (int i = 0; i < size; i++)
        data[i] = T();
}

template <class T>
Array<T>::Array(const Array<T>& other)
{
    size = other.size;
    data = new T[size];

    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

template <class T>
Array<T>::~Array()
{
    delete[] data;
}

template <class T>
int Array<T>::GetSize() const
{
    return size;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] data;

        size = other.size;
        data = new T[size];

        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    return *this;
}

template <class T>
T& Array<T>::operator[](int index)
{
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");

    return data[index];
}

template <class T>
const T& Array<T>::operator[](int index) const
{
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");

    return data[index];
}

template <class U>
ostream& operator<<(ostream& out, const Array<U>& arr)
{
    out << "[ ";
    for (int i = 0; i < arr.size; i++)
        out << arr.data[i] << " ";
    out << "]";
    return out;
}

template <class U>
istream& operator>>(istream& in, Array<U>& arr)
{
    cout << "Enter " << arr.size << " elements:" << endl;
    for (int i = 0; i < arr.size; i++)
    {
        cout << "arr[" << i << "] = ";
        in >> arr.data[i];
    }
    return in;
}

int main()
{
    try
    {
        Array<int> a(5);
        cin >> a;
        cout << "Array a: " << a << endl;

        Array<int> b(a);
        cout << "Copied array b: " << b << endl;

        Array<int> c(5);
        c = a;
        cout << "Assigned array c: " << c << endl;

        cout << "a[2] = " << a[2] << endl;
        a[2] = 100;
        cout << "After changing a[2]: " << a << endl;

        Array<double> d(3);
        cin >> d;
        cout << "Array d: " << d << endl;

        cout << "Size of a = " << a.GetSize() << endl;
        cout << "Size of d = " << d.GetSize() << endl;

        cout << "Trying invalid index..." << endl;
        cout << a[10] << endl;
    }
    catch (const exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}