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
			if (x == 0 || y == 0) {
				y = 0;
				x = 0;
			}
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
		void	Reset(int x, int y) {
			if (x < 0 || y < 0)
				throw std::out_of_range("Out of range");
			if (x == 0 || y == 0) {
				y = 0;
				x = 0;
			}
			nums_rows = x;
			nums_cols = y;
			matrix.clear();
			for (int i = 0; i < x; i++) {
				std::vector<int> tmp;
				for (int c = 0; c < y; c++) {
					tmp.push_back(0);
				}
				matrix.push_back(tmp);
			}
		}
		int		At(int x, int y) const {
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
		int	GetNumColumns() const {
			return nums_cols;
		}
	private:
		int nums_rows;
		int nums_cols;
		std::vector< std::vector<int> > matrix;
};

bool		operator==(const Matrix& x, const Matrix& y) {
	int rows = x.GetNumRows();
	int cols = x.GetNumColumns();
	if (rows != y.GetNumRows())
		return false;
	if (cols != y.GetNumColumns())
		return false;	
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if (x.At(i, j) != y.At(i, j))
				return false;
		}
	}
	return true;
}


Matrix			operator+(const Matrix &x, const Matrix &y) {
	int rows = x.GetNumRows();
	int cols = x.GetNumColumns();
	if (rows != y.GetNumRows())
		throw std::invalid_argument("invalid argument");
	if (cols != y.GetNumColumns())
		throw std::invalid_argument("invalid argument");
	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newMatrix.At(i, j) = x.At(i, j) + y.At(i, j);
		}
	}
	return newMatrix;
}

std::istream&	operator>>(std::istream& stream, Matrix& x) {
	int r, c;
	stream >> r >> c;

	x.Reset(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			stream >> x.At(i, j);
		}
	}
	return stream;
}

std::ostream&	operator<<(std::ostream& stream, const Matrix& x) {
	int rows = x.GetNumRows();
	int cols = x.GetNumColumns();
	stream << rows << ' ' << cols << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++){
			if (j > 0)
				stream << " ";
			stream << x.At(i, j);
		}
		stream << std::endl;
	}
	return stream;
}
