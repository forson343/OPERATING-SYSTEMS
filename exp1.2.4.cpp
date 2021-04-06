#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
	int burst[20], wait[20], trntime[20], i, num_pro;
	float waitavg, trntimeavg;
	int pro[20], k, temp, prior[20];
	
	cout << "\n\t\t\t------Priority CPU Scheduling Algorithm------\n" << endl;
	cout << "Enter the number of processes --- ";
	cin >> num_pro;
	
	for (i = 0; i < num_pro; i++)
	{
		pro[i] = i;
		cout << "Enter the Burst Time & Priority of Process " << i << " --- ";
		cin >> burst[i] >> prior[i];
	}
	
	for (i = 0; i < num_pro; i++)
		for (k = 0; k < num_pro; k++)
			if (prior[i] > prior[k])
			{
				temp = pro[i];
				pro[i] = pro[k];
				pro[k] = temp;
				
				temp = burst[i];
				burst[i] = burst[k];
				prior[k] = temp;
			}
			
	waitavg = wait[0] = 0;
	trntimeavg = trntime[0] = burst[0];
	
	for (i = 0; i < num_pro; i++)
	{
		wait[i] = wait[i - 1] + burst[i - 1];
		trntime[i] = trntime[i - 1] + burst[i - 1];
		
		waitavg = waitavg + wait[i];
		trntimeavg = trntimeavg + trntime[i]; 
	}
	
	cout << "\nPROCESS \t\tPRIORITY \tBURST TIME \tWAITING TIME \tTURNAROUND TIME";
	for (i = 0; i < num_pro; i++)
	{
		cout  << "\n" << pro[i] << "\t\t\t" << prior[i] << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << trntime[i];
	}
	
	cout << "\nAverage Wait Time is --- " << waitavg << endl;
	cout << "Average Turnaround Time is --- " << trntimeavg;
	
	return 0;
}