#include <iostream>
#include "Matrix.h"

using namespace std;

// класичний клас для вимірювання розміру
class MatrixSizeNormal
{
private:
    int** data;
    int rows;
    int cols;
};

// впакований клас для вимірювання розміру
#pragma pack(push, 1)
class MatrixSizePacked
{
private:
    int** data;
    int rows;
    int cols;
};
#pragma pack(pop)

int main()
{
    try
    {
        cout << "Size of class without #pragma pack(1): " << sizeof(MatrixSizeNormal) << " bytes\n";
        cout << "Size of class with    #pragma pack(1): " << sizeof(MatrixSizePacked) << " bytes\n\n";

        Matrix A;           // без аргументів
        Matrix B(2);        // квадратна 2x2
        Matrix C(2, 3);     // прямокутна 2x3

        // Заповнення B
        B.setElement(0, 0, 1);
        B.setElement(0, 1, 2);
        B.setElement(1, 0, 3);
        B.setElement(1, 1, 4);

        cout << "Matrix B:\n" << B << endl;

        // копіювання
        Matrix D(B);
        cout << "Matrix D (copy of B):\n" << D << endl;

        // присвоєння
        A = B;
        cout << "Matrix A after assignment A = B:\n" << A << endl;

        // ще одна матриця
        Matrix E(2, 2);
        E.setElement(0, 0, 5);
        E.setElement(0, 1, 6);
        E.setElement(1, 0, 7);
        E.setElement(1, 1, 8);

        cout << "Matrix E:\n" << E << endl;

        // бінарні операції
        Matrix Sum = B + E;
        cout << "B + E:\n" << Sum << endl;

        Matrix Diff = E - B;
        cout << "E - B:\n" << Diff << endl;

        Matrix Prod = B * E;
        cout << "B * E:\n" << Prod << endl;

        // унарний мінус
        Matrix Neg = -B;
        cout << "-B:\n" << Neg << endl;

        // +=, -=, *=
        Matrix F(B);
        F += E;
        cout << "F after F += E:\n" << F << endl;

        F = B;
        F -= E;
        cout << "F after F -= E:\n" << F << endl;

        F = B;
        F *= E;
        cout << "F after F *= E:\n" << F << endl;

        // перетворення у рядок
        string strB = (string)B;
        cout << "Matrix B as string:\n" << strB << endl;

        // введення з клавіатури
        Matrix G;
        cin >> G;
        cout << "You entered:\n" << G << endl;

        // масив об'єктів
        Matrix arr[3];
        arr[0] = Matrix(2, 2);
        arr[1] = Matrix(3, 3);
        arr[2] = Matrix(2);

        cout << "Array of matrices created\n";
        cout << "arr[0] size: " << arr[0].getRows() << "x" << arr[0].getCols() << endl;
        cout << "arr[1] size: " << arr[1].getRows() << "x" << arr[1].getCols() << endl;
        cout << "arr[2] size: " << arr[2].getRows() << "x" << arr[2].getCols() << endl;
    }
    catch (const exception& ex)
    {
        cout << "Error: " << ex.what() << endl;
    }

    return 0;
}