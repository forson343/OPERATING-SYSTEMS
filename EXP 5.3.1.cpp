#include <iostream>
#include<stdio.h>
#include<conio.h>
#define max 25

using namespace std;


int main() 
{
	int frag[max], b[max], f[max], i, j, nb, nf, temp;
	static int bf [max], ff[max];

	cout << "\n\tMemory Management Scheme - First Fit";
	cout << "\nEnter the number of blocks: ";

	cin >> nb;

	cout << "Enter the number of files: ";
	cin >> nf;

	cout << "\nEnter the size of the blocks:- \n";
	
	for(i = 1; i <= nb; i++)
	{
	    cout << "Block " << i << ":";
	    cin >> b[i];
	}

	for(i = 1; i <= nf; i++)
	{
		cout << "File " << i << ":";
		cin >> f[i];
	}

	for (i = 1; i <= nf; i++)
	{
		for(j = 1; j <= nb; j++)
		{
			if (bf[j] != 1)
			{
				temp = b[j] - f[i];
				if(temp >= 0)
				{
					ff[i] = j;
					break;
				}
			}
		}
		frag[i] = temp;
		bf[ff[i]] = 1;
	}
	cout << "\nFile No.:\tFile Size:\tBlock Size:\tFragement";
	for(i = 1; i <= nf; i++)
		cout << "\n\t\t\t\t\t\t\t\t" << i << f[i] <<ff[i] << b[ff[i]] << frag[i];
	return 0;
}