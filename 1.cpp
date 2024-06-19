#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
    int rows, cols;
    vector<vector<int>> data;

    Matrix(int r, int c) : rows(r), cols(c), data(vector<vector<int>>(r, vector<int>(c, 0))) {}

    Matrix operator + (const Matrix& a) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + a.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator += (const Matrix& a) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] += a.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator - (const Matrix& a) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - a.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator -= (const Matrix& a) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] -= a.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator * (const Matrix& a) const {
        Matrix result(rows, a.cols);
        int tmpSum = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < a.cols; j++) {
                tmpSum = 0;
                for (int k = 0; k < cols; k++) {
                    tmpSum += data[i][k] * a.data[k][j];
                }
                result.data[i][j] = tmpSum;
            }
        }
        return result;
    }

    Matrix& operator *= (const Matrix& a) {
        *this = *this * a;
        return *this;
    }

    int get_cols() const{

        return cols;
    }
    
    int get_rows() const{

        return rows;
    }
};

istream& operator >> (istream& in, Matrix& matrix) {
    for (int i = 0; i < matrix.get_rows(); i++) {
        for (int j = 0; j < matrix.get_cols(); j++) {
            in >> matrix.data[i][j];
        }
    }
    return in;
}

ostream& operator << (ostream& stream, const Matrix& matrix) {
    for (int i = 0; i < matrix.get_rows(); i++) {
        for (int j = 0; j < matrix.get_cols(); j++) {
            stream << matrix.data[i][j] << " ";
        }
        stream << endl;
    }
    return stream;
}

int main() {

    setlocale(LC_ALL, "ru");

    Matrix A(2,2); 
    Matrix B(2,2); 
    cout << "Введите матрицу A (2 на 2):" << endl;
    cin >> A;
    cout << "Введите матрицу B (2 на 2):" << endl;
    cin >> B;
    cout << "A + B: " << endl << (A+B);
    cout << "A - B: " << endl << (A-B);
    cout << "A * B: " << endl << (A*B);



    return 0;
}
