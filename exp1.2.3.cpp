#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
	int i, j, num_pro, burst_t[10], wait_t[10], trnarndt[10], time, ct[10], max;
	float awt = 0, att = 0, temp = 0;
	
	cout << "\n\t\t\t------Round Robin CPU Scheduling Algorithm------\n" << endl;
	cout << "Enter the number of processes -- ";
	cin >> num_pro;
	
	for (i = 0; i < num_pro; i++)
	{
		cout << "\nEnter burst time for process " << i+1 << " -- ";
		cin >> burst_t[i];
		ct[i] = burst_t[i];
	}
	
	cout << "\nEnter the size of time slice -- ";
	cin >> time;
	
	max = burst_t[0];
	
	for (i = 1; i < num_pro; i++)
		for (i = 1; i < num_pro; i++)
			if (max < burst_t[i])
				max = burst_t[i];
	
	for (j = 0; j < (max/time) + 1; j++)
		for (i = 0; i < num_pro; i++)
			if (burst_t[i] != 0)
				if (burst_t[i] <= time)
				{
					trnarndt[i] = temp + burst_t[i];
					temp = temp + burst_t[i];
					burst_t[i] = 0;
				}
				
				else
				{
					burst_t[i] = burst_t[i] - time;
					temp = temp + time;
				}
	
	for (i = 0; i < num_pro; i++)
	{
		wait_t[i] = trnarndt[i] - ct[i];
		att += trnarndt[i];
		awt += wait_t[i]; 
	}
	
	cout << "\nThe Average Turnaround time is -- " << att << endl;
	cout << "The Average Waiting time is -- " << awt << endl;
	cout << "\n\tPROCESS \tBURST TIME \tWAITING TIME \tTURNAROUND TIME\n";
	
	for (i = 0; i < num_pro; i++)
		cout << "\t" << i + 1 << "\t\t" << ct[i] << "\t\t" << wait_t[i] << "\t\t" << trnarndt[i] << "\n";
	
	return 0;
}