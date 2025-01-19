#include <iostream>
#include <vector>

using namespace std;

struct SparseMatrixEntry {
    int row;
    int col;
    int value;
};

vector<SparseMatrixEntry> createSparseMatrix(vector<vector<int>> &matrix) {
    vector<SparseMatrixEntry> sparseMatrix;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] != 0) {
                SparseMatrixEntry entry = {i, j, matrix[i][j]};
                sparseMatrix.push_back(entry);
            }
        }
    }
    return sparseMatrix;
}

void printSparseMatrix(const vector<SparseMatrixEntry> &sparseMatrix) {
    cout << "Sparse Matrix Representation (Row, Column, Value):" << endl;
    for (const auto &entry : sparseMatrix) {
        cout << "(" << entry.row << ", " << entry.col << ", " << entry.value << ")" << endl;
    }
}

vector<vector<int>> reconstructMatrix(const vector<SparseMatrixEntry> &sparseMatrix, int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    for (const auto &entry : sparseMatrix) {
        matrix[entry.row][entry.col] = entry.value;
    }
    return matrix;
}

void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {5, 0, 0},
        {0, 8, 0},
        {0, 0, 3},
        {0, 6, 0}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    vector<SparseMatrixEntry> sparseMatrix = createSparseMatrix(matrix);
    printSparseMatrix(sparseMatrix);

    vector<vector<int>> reconstructedMatrix = reconstructMatrix(sparseMatrix, matrix.size(), matrix[0].size());
    cout << "Reconstructed Matrix:" << endl;
    printMatrix(reconstructedMatrix);

    return 0;
}
