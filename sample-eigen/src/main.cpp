#include <iostream>
#include "Eigen/Dense"
#include <vector>

using namespace std;
using namespace Eigen;

int main(){


  VectorXd my_vector(2);
  my_vector << 10, 20;
  cout << "2D vector:" << endl;
  cout << my_vector << endl;
  /********
  10
  12
  *********/

  MatrixXd my_matrix(2, 2);
  my_matrix << 1, 2,
               3, 4;
  cout << "2 x 2 matrix" << endl;
  cout << my_matrix << endl;
  /********
  1 2
  3 4
  *********/

  cout << "change 2nd row, 1st col to 11" << endl;
  cout << "change 2nd row, 1st col to 12" << endl;
  my_matrix(1,0) = 11;
  my_matrix(1, 1) = 12;
  cout << my_matrix << endl;
  /********
  1  2
  11 12
  *********/

  cout << "transpose of original matrix" << endl;
  cout << my_matrix.transpose() << endl;
  /********
  1 11
  2 12
  *********/

  cout << "inverse of original matrix" << endl;
  cout << my_matrix.inverse() << endl;
  /********
  -1.2  0.2
   1.1 -0.1
  *********/

  cout << "multiply matrix and vector" << endl;
  cout << my_matrix * my_vector << endl;
  /********
   50
   350
  *********/



  MatrixXd I = MatrixXd::Identity(4, 4);
  cout << "identity matrix 4 x 4" << endl;
  cout << I << endl;
  /********
  1 0 0 0
  0 1 0 0
  0 0 1 0
  0 0 0 1
  *********/


  vector<VectorXd> vect;

  VectorXd v(1);
  v << 1;
  vect.push_back(v);
  v << 2;
  vect.push_back(v);
  v << 4;
  vect.push_back(v);

  cout << "vectors in vect printed one at at time" << endl;

  for (int i = 0; i < vect.size(); i++){
    cout << vect[i] << endl;
  }
  /********
   1
   2
   4
  *********/

  VectorXd x(4);
  x << 10, 20, 1, 2;

  MatrixXd H(2, 4);
  H << 1, 0, 0, 0,
			 0, 1, 0, 0;

  cout << "vector x - 4" << endl;
  cout << x << endl;

  cout << "matrix  H - 2 x 4" << endl;
  cout << H << endl;

  cout << "multiplication H * x" << endl;
  cout << H * x << endl;

  return 0;
}
