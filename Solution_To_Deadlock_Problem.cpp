#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

	int instance[5], sequence[5], safe,s = 0, j, i, completed;
	int available[5], allocation[10][5], max[10][5];
	int need[10][5], process, P[10], countofr, countofp, running[10], count;

	cout << "\nEnter the number of resources (<= 5) : ";
	cin >> countofr;
	for(i = 0; i < countofr; i++){
		cout << "\nEnter the maximum instance of resource R["<<i<<"] : ";
		cin >> instance[i];
		available[i] = instance[i];
	}
	cout << "\nEnter the number of process (<= 10) : ";
	cin >> countofp;
	cout << "\nEnter the allocation matrix : \n";
	for(i = 0; i < countofp; i++){
		cout << "FOR THE PROCESS : P["<<i<<"]" << endl;
		for(j = 0; j < countofr; j++){
			cout << "Allocation of resource R["<<j<<"] is : ";
			cin >> allocation[i][j];
			available[j] = allocation[i][j];
		}
	}

	cout << "\nEnter the MAX matrix : \n";
	for(i = 0; i < countofp; i++){
		cout << "FOR THE PROCESS : P["<<i<<"]" << endl;
		for(j = 0; j < countofr; j++){
			cout << "maximum demand of resource R["<<j<<"] is : ";
			cin >> max[i][j];
		}
	}
	cout << "\nTHE GIVEN DATA IS : \n";

	cout << "\n\nTotal resources in the system : \n";
	for(i = 0; i < countofr; i++){
		cout << "R["<<i<<"] ";
	}
	cout << endl;
	for(i = 0; i < countofr; i++){
		cout << "    " << instance[i];
	}

	cout << "\n\n\tALLOCATION MATRIX : \n\n\t";
	for(i = 0; i < countofr; i++){
		cout << "R["<<i<<"] ";
	}
	cout << endl;
	for(i = 0; i < countofp; i++){
		cout << "P["<<i<<"] " ;
		for(j = 0; j < countofr; j++){
			cout << "      " << allocation[i][j];
		}
		cout << endl;
	}

	cout << "\n\n\tMAX MATRIX : \n\n\t";
	for(i = 0; i < countofr; i++){
		cout << "R["<<i<<"] ";
	}
	cout << endl;
	for(i = 0; i < countofp; i++){
		cout << "P["<<i<<"] ";
		for(j = 0; j < countofr; j++){
			cout << "     " << max[i][j];
		}
		cout << endl;
	}

	for(i = 0; i < countofp; i++){
		for(j = 0; j < countofr; j++){
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}


	cout << "\n\n\tNEED MATRIX : \n\n\t";
	for(i = 0; i < countofr; i++){
		cout << "R["<<i<<"] ";
	}
	cout << endl;
	for(i = 0; i < countofp; i++){
		cout << "P["<<i<<"] " ;
		for(j = 0; j < countofr; j++){
			cout << "     " << need[i][j];
		}
		cout << endl;
	}

	cout << "\nCheck if above state is safe or not : \n";
	cout << "\nSequence in which above requests can be fullfilled\n";
	count = countofp;

	for(i = 0; i < countofp; i++){
		running[i] = 1;
	}

	while(count){
		safe = 0;
		for(i = 0; i < countofp; i++){
			if(running[i]){
				completed = 1;
				for(j = 0; j < countofr; j++){
					if(need[i][j] > available[j]){
						completed = 0;
						break;
					}
				}
				if(completed){
					running[i] = 0;
					count--;
					safe = 1;
					for(j = 0; j < countofr; j++){
						available[j] += allocation[i][j];
					}
					sequence[s++] = i;
					cout << "Running process P["<<i<<"]";
					cout << "\n\nTotal resources now available : \n\n";
					for(j = 0; j < countofr; j++){
						cout << "R[" << j << "] ";
					}
					cout << endl;
					for(j = 0; j < countofr; j++){
						cout << "    " << available[j];
					}
					break;
				}
			}
		}
		if(!safe)	break;
	}
	if(safe){
		cout << "\n\nThe system is in safe state.\n\n";
		cout << "\nSafe sequence is : ";
		for(i = 0; i < countofp; i++){
			cout << "\tP["<<sequence[i]<<"]" << endl;
		}
	}
	else{
		cout << "\n\nThe system is in unsafe state.\n\n";
	}
	return 0;
}
