/* rotate the matrix 90 degrees to the right 
*/
#include<vector>
#include <iostream>
using namespace std;

void rotate(vector<const char*> &nums, int const rows, int const cols)
{
	if (rows==0 || cols!=rows)
	{
		cout << " the matrix is either empty or not square" << endl;
		return;
	}
	// print out the original matrix
	cout << "This is the original matrix: " << endl << endl;
	int num_chars = 0;
	for (int i = 0; i < rows*cols; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout <<  "   "<< nums[num_chars];
			num_chars++;
			// cout << "j is  " << j << endl;
			
		}
		i = i + rows;
		cout << endl << endl;
	}
	// counter is used to iterate through initial matrix
	int counter = 0;
	// new matrix start in the second half of the vector
	int offset_vector = rows * rows;

	// start populating the last column first to first column
	for (int i = cols ; i > 0; --i)
	{
		for (int j = 0; j < rows*rows; j++)
		{
						nums[offset_vector-1+i+j] = nums[counter];
			j =j + rows-1;
			counter++;

		}
	}


}
int main() {
	std::vector<const char*> mat = { "a","b","c","d","e","f","g","h","i","j",
	"k","l","m","n","o","p"};
	mat.resize(2 * mat.size());
		int const num_rows = 4;
		int const num_cols = 4;
	rotate(mat,num_rows,num_cols);

	// remove the original matrix
	
	mat.erase(mat.begin(), mat.end()-num_rows * num_cols);
	cout << "This is the rotated by 90 degrees matrix: " << endl << endl;
	int num_chars = 0;
	for (int i = 0; i < num_rows * num_cols; i++)
	{
		for (int j = 0; j < num_cols; j++)
		{
			cout << "   " << mat[num_chars];
			num_chars++;
			// cout << "j is  " << j << endl;

		}
		i = i + num_rows;
		cout << endl << endl;
	}
	cout << endl;
	return 0;
}