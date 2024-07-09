#include <iostream>
#include <vector>

// Include another header file if necessary

// Implement your own matrix and matrix


using namespace std;


template <typename T>
class Matrix {
    private:
    vector<vector<T>> M;
    int m_rows, m_cols;

    public:
    Matrix(int t_rows, int t_cols) : m_rows(t_rows), m_cols(t_cols){
        M.resize(m_rows, vector<T>(m_cols, 0)); //2차원 벡터 resize 방식!
    }

    vector<T>& operator[](int index){
        return M[index]; //M은 객체 그자체가 아니라 그 안의 벡터이므로 main 함수에서 '객체[]' 형태로로 벡터에 접근하려면 이 오버로딩이 필요하다!
    }

    Matrix operator+ (Matrix& Second){
        Matrix Sum(m_rows, m_cols);
        for(int i = 0; i < m_rows; ++i){
            for(int j = 0; j < m_cols; ++j){
                Sum[i][j] = this->M[i][j] + Second.M[i][j]; //Sum과 second는 객체, M은 이 연산자오버로딩을 호출한 m1안의 벡터명
            }
        }
        return Sum;
    }

    Matrix operator- (Matrix& Second){
        Matrix Sub(m_rows, m_cols);
        for(int i = 0; i < m_rows; ++i){
            for(int j = 0; j < m_cols; ++j){
                Sub[i][j] = (Second.M[i][j] - this->M[i][j]);
            }
        }
        return Sub;
    }


    Matrix operator* (Matrix& Second){
        Matrix Mul(m_rows, Second.m_cols);
        for (int  i = 0; i < m_rows; ++i){
            for (int j = 0; j < Second.m_cols; ++j){
                for(int k = 0; k < m_cols; ++k){
                    Mul[i][j] += M[i][k] * Second.M[k][j];
                }
            }
        }
        return Mul;
    }


    Matrix operator*(T Scalar) const {
        Matrix ScalarMul(m_rows, m_cols);
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
                ScalarMul[i][j] = this->M[i][j] * Scalar;
            }
        }
        return ScalarMul;
    }

    friend Matrix operator*(T Scalar, const Matrix& matrix) {
        return matrix * Scalar; // Scalar 곱셈을 전역 함수로 오버로딩
        //이 구문에서 위의 Matrix의 멤버함수 오버로딩을 호툴하게끔 하는것. 이중으로.
    }
    

    friend ostream& operator<<(ostream& os, Matrix& PrintM){  
        //ostream에 &를 하는이유: 복사본을 만들지 않고 원본 객체를 직접 사용. 
        //참조를 반환하면 연산 결과를 다시 ostream 객체로 사용할 수 있게 되어 연속적인 호출이 가능. 
        //반환값이 참조가 아니면 임시 객체가 반환되므로, 이후의 출력 연산이 원본 ostream 객체에서 계속되지 않음.
        for(int i = 0; i < PrintM.m_rows; ++i){
            for(int j = 0; j < PrintM.m_cols; ++j){
                os << PrintM.M[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

};



int main()

{

    Matrix <int> m1(3, 3); //객체  // row size, column size & all elements are initialized into 0s

    m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;

    m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;

    m1[2][0] = 7; m1[2][1] = 8; m1[2][2] = 9;



    Matrix <int> m2(3, 3);  // row size, column size

    m2[0][0] = 9; m2[0][1] = 8; m2[0][2] = 7;

    m2[1][0] = 6; m2[1][1] = 5; m2[1][2] = 4;

    m2[2][0] = 3; m2[2][1] = 2; m2[2][2] = 1;



    Matrix <int> m(3, 3);

    m = m1 + m2;


    // cout은 ostream 클래스의 객체이다.
    // 이 연산이 가능하려면 << 연산자가 'm'이라는 Matrix 클래스의 객체에 대해 오버로딩 되어야 한다.
    // 그러나 +, - 연산자와는 달리 << 연산자의 경우 앞과 뒤에있는 피연산자의 클래스가 각각 ostream과 Matrix로 다르다.
    // 따라서 Matrix 클래스에 대해서만 << 연산자를 오버로딩하면 소용이 없다.
    // 더군다나 ostream은 C++ 표준 라이브러리의 클래스이기 때문에 직접 수정할 수 없다.
    // 따라서 << 연산자를 전역 함수로 오버로딩 하고, 
    // 전역 함수가 Matrix 클래스의 멤버 변수와 함수에 접근할 수 있도록 하기 위해 friend 키워드를 사용하여 선언하는 것이 바람직하다.
    cout << m;



    m = m1 - m2;



    cout << m;

    

    m = m1 * m2;



    cout << m;



    m = 10 * m1;



    cout << m;



    return 0 ; 

}