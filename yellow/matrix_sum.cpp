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

Matrix			operator+(const Matrix &x, const Matrix &y) {
	int rows = x.GetNumRows();
	int cols = x.GetNumCols();
	if (rows != y.GetNumRows() || cols != y.GetNumCols())
		throw std::invalid_argument("invalid argument");
	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newMatrix.At(i, j) = x.Atc(i, j) + y.Atc(i, j);
		}
	}
	return newMatrix;
}

bool		operator==(Matrix& x, Matrix& y) {
	int rows = x.GetNumRows();
	int cols = x.GetNumCols();
	if (rows != y.GetNumRows() || cols != y.GetNumCols())
		return false;	
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if (x.Atc(i, j) != y.Atc(i, j))
				return false;
		}
	}
	return true;
}

std::ostream&	operator<<(std::ostream& stream, const Matrix& x) {
	int rows = x.GetNumRows();
	int cols = x.GetNumCols();
	stream << rows << ' ' << cols << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++){
			stream << x.Atc(i, j) << ' ';
		}
		if ((i + 1) != rows)
			stream << std::endl;
	}
	return stream;
}
