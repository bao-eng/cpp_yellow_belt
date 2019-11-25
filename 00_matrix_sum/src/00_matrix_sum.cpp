#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix{
public:
	Matrix(){
		matrix.resize(0);
	}
	Matrix(int num_rows, int num_cols){
		Reset(num_rows, num_cols);
	}
	void Reset(int num_rows, int num_cols){
		if(num_rows<0||num_cols<0){
			throw out_of_range("");
		}
		matrix.clear();
		matrix.resize(num_rows);
		for(auto& i: matrix){
			i.resize(num_cols);
		}
	}
	int At(int row, int col) const{
		return matrix[row][col];
	}
//	int& At(int row, int col) const{
//		return &matrix[row][col];
//	}
	int GetNumRows() const{
		return matrix.size();
	}
	int GetNumColumns() const{
		return matrix[0].size();
	}

private:

vector<vector<int>> matrix;
};

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if((lhs.GetNumRows()==rhs.GetNumRows())&&(lhs.GetNumColumns()==rhs.GetNumColumns())){
		return true;
	}
	return false;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	if((lhs.GetNumRows()==rhs.GetNumRows())&&(lhs.GetNumColumns()==rhs.GetNumColumns())){
		return true;
	}
	return false;
}

istream operator<<(const Matrix& mtrx){
	for(auto i: mtrx){
		for(auto j: i){
			cout << j << " ";
		}
		cout << endl;
	}

}

istream operator>>(const Matrix& mtrx){


}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
