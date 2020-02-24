
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include "cstdlib"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// Making changes for my second git commit

int main() {

  // Variables
  size_t x=2;
  size_t y=5;
  size_t i, j, dim;

  // Input data
  //cout << "Type the number of horizontal cycles" << endl;
  //cin >> x;
  //cout << "Type the number of vertical cycles" << endl;
  //cin >> y;

  // Computing dimension
  dim = ( 2 * x + 1 ) * ( y + 1 );
  cout << "The number of atoms is: "<< dim << endl;

  // Matrix array
  // arrays index start at 0, ..., dim - 1
  char M[dim][dim];

  // Filling matrix with zeros
  for ( i = 0; i < dim; i++ ) {
    for ( j = 0; j < dim; j++ ) {
      M[i][j] = '0';
      //cout << M[i][j] << " "; 
    }
    //cout << endl;    
  }

	cout << endl ;

  // Filling matrix
  for( i = 0; i < dim; i++ ) {
    M[i][i] = 'a';
    if ( ( i + 1 ) < dim ) {
      M[i][i+1] = 'b';
      M[i+1][i] = 'b';
    }
    if ( i%2 == 0 &&  i + (2*x + 1 ) < dim ) {
      M[i][i+(2*x+1)] = 'b';
      M[i+(2*x+1)][i] = 'b';
    }
  }

  // Output result
  ofstream fs("matrix.out"); 
  for ( i = 0; i < dim; i++ ) {
    for ( j = 0; j < dim; j++ ) {
      cout<< M[i][j] << " ";
      fs<< M[i][j] << " ";
    }
    cout<< endl;
    fs << endl;
  }
	fs.close();
	
	cout << endl;
	/////////////////////////////////////////////
	/////// Numerical matrix ////////////////////
	/////////////////////////////////////////////
	
	double H[dim][dim];

  // Filling matrix with zeros
  for ( i = 0; i < dim; i++ ) {
    for ( j = 0; j < dim; j++ ) {
      H[i][j] = 0.0;
      //cout << H[i][j] << " "; 
    }
    //cout << endl;    
  }

	cout << endl ;

  // Filling matrix
  for( i = 0; i < dim; i++ ) {
    H[i][i] = 0.0;
    if ( ( i + 1 ) < dim ) {
      H[i][i+1] = 1.0;
      H[i+1][i] = 1.0;
    }
    if ( i%2 == 0 &&  i + ( 2*x + 1 ) < dim ) {
      H[i][i+(2*x+1)] = 1.0;
      H[i+(2*x+1)][i] = 1.0;
    }
  }

  // Output result
  ofstream hamiltonian("hamiltonian.out"); 
  for ( i = 0; i < dim; i++ ) {
    for ( j = 0; j < dim; j++ ) {
      cout<< H[i][j] << " ";
      hamiltonian<< H[i][j] << " ";
    }
    cout<< endl;
    hamiltonian << endl;
  }
	hamiltonian.close();
	
	
  return 0;
}
