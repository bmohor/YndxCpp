#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

class Matrix {
	public:
		Matrix(){
			nums_rows = 0;
			nums_cols = 0;
		}
		Matrix(int x, int y) {
			if (x < 0 || y < 0)
				throw std::out_of_range("Out of range");
			nums_rows = x;
			nums_cols = y;
			for (int i = 0; i < x; i++) {
				std::vector<int> tmp;
				for (int c = 0; c < y; c++) {
					tmp.push_back(0);
				}
				matrix.push_back(tmp);
			}
		}
		void	Resett(int x, int y) {
			if (x < 0 || y < 0)
				throw std::out_of_range("Out of range");
			nums_rows = x;
			nums_cols = y;
			for (int i = 0; i < x; i++) {
				std::vector<int> tmp;
				for (int c = 0; c < y; c++) {
					tmp.push_back(0);
				}
				matrix.push_back(tmp);
			}
		}
		int		Atc(int x, int y) const {
			if (x < 0 || y < 0 || x >= nums_rows || y >= nums_cols) {
				throw std::out_of_range("Out of range");
			}
			return matrix[x][y];
		}
		int&	At(int x, int y) {
			if (x < 0 || y < 0 || x >= nums_rows || y >= nums_cols)
				throw std::out_of_range("Out of range");
			return matrix[x][y];
		}
		int	GetNumRows() const {
			return nums_rows;
		}
		int	GetNumCols() const {
			return nums_cols;
		}
	private:
		int nums_rows;
		int nums_cols;
		std::vector< std::vector<int> > matrix;
};

std::istream&	operator>>(std::istream& stream, Matrix& x) {
	int r, c;
	stream >> r >> c;
	x.Resett(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int num;
			stream >> num;
			x.At(i, j) = num;
		}
	}
	return stream;
}
/*
Matrix			operator+(Matrix &x, Matrix &y) {
	int rows = x.GetNumRows();
	int cols = x.GetNumCols();

}
*/
std::ostream&	operator<<(std::ostream& stream, Matrix& x) {
	int rows = x.GetNumRows();
	int cols = x.GetNumCols();
	stream << rows << ' ' << cols << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; i++){
			stream << x.Atc(i, j) << ' ';
		}
		stream << std::endl;
	}
	return stream;
}
int main() {

	std::vector< std::vector<int> > matrix;
	Matrix one;
	one.Resett(5, 5);
	try {
		std::cout << one.Atc(4, 4);
	} catch(std::out_of_range& ex) {
		std::cout << ex.what() <<std::endl;
	}

//	std::cin >> one >> two;
//	std::cout << one << std::endl;
//	std::cout << two << std::endl;
//	std::cout << one + two << std::endl;
	return 0;
}
