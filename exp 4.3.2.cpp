#include <iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;


int main() 
{
	int ms, mp[10], i, temp, n = 0;
	char ch = 'y';
	
	cout << "\nEnter the total memory avaiable (in Bytes)-- ";
	cin >> ms;
	
	temp = ms;
	
	for (i = 0; ch == 'y'; i++, n++)
	{
		cout << "\nEnter memory required for process " <<  i + 1 <<  "(in Bytes)-- ";
		cin >> mp[i];
		
		if(mp[i] <= temp)
		{
			cout << "\nMemory is allocated for Process " << i + 1;
			temp = temp - mp[i];
		}
		
		else
		{
			cout << "\nMemory is full";
			break;
		}
		
		cout << "\nDo you want to continue (Y/N)-- ";
		cin >> ch;
	}
	
	cout << "\n\nTotal Memory Available-- " << ms;
		
	cout << "\n\n\tPROCESS\t\tMEMORY ALLOCATED ";
	
	for(i = 0; i < n ;i++)
        cout << "\n  \t\t" << i+1 << mp[i];
	
	cout << "\nTotal Memory Allocated is" << ms -  temp;
	cout << "\nTotal External Fragmentation is " << temp;
	
	return 0;
}