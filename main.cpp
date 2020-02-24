#include <iostream>
#include <math.h>
#include <stdio.h>


using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main() {
	
	int nbx, nby, dim;	
	
	cout << "Type the number of horizontal cycles" << endl;
	cin >> nbx;
	cout << "Type the number of vertical cycles" << endl;
	cin >> nby;
	
	dim = (2*nbx+1)*(nby+1);
	cout << "The number of atoms is: "<<dim << endl;
	
	int H[dim][dim];
	
	for (int i = 1 ; i <= dim ; i++)
		{
			for (int j = 1 ; j <= dim ; j++)
				{
					H[i][j]=0;
					cout << H[i][j] <<"\t";
				}
			cout << endl;
		}
		
	cout << endl;
	for( int i=1 ; i <= dim ; i++)
		{
			H[i][i]=2;
			if( i < dim)
				{
					H[i][i+1]=1;
					H[i+1][i]=1;
				}
			if(i%2 != 0 && i+2*nbx+1 < dim)
				{
					H[i][i+2*nbx+1]=1;
					H[i+2*nbx+1][i]=1;
				}
		}
		
		
		for (int i = 1 ; i <= dim ; i++)
		{
			for (int j = 1 ; j <= dim ; j++)
				{
					cout << H[i][j] <<" ";
				}
			cout << endl;
		}
	
	return 0;
}
