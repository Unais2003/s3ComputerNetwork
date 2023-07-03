#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int graph[50][50];
	int i, j, k, t;
	int nn;

	cout << "\nEnter Number of Routers: ";
	cin >> nn;

	
	for (i = 0; i < nn; i++)
	{
		for (j = 0; j < nn; j++)
		{
			graph[i][j] = -1;
		}
	}

	
	char ch[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

	
	for (i = 0; i < nn; i++)
	{
		cout << endl;
		for (j = 0; j < nn; j++)
		{
			if (i == j)
			{
				graph[i][j] = 0;
			}
			if (graph[i][j] == -1)
			{
				cout << "Enter Distance between Routers " << i + 1 << " and " << j + 1 << " : ";
				cin >> t;
				graph[i][j] = graph[j][i] = t;
			}
		}
	}

	
	int via[50][50];
	for (i = 0; i < nn; i++)
	{
		for (j = 0; j < nn; j++)
		{
			via[i][j] = -1;
		}
	}

	cout << "\n**************************************";
	cout << "\n\nAfter Initialization :";
	
	for (i = 0; i < nn; i++)
	{
		cout << "\n\nTable for Router " << i + 1;
		cout << "\n----------------------";
		cout << "\nRouter\t| Dist\t| Via";
		cout << "\n----------------------";
		for (j = 0; j < nn; j++)
		{
			cout << "\n"
				 << j + 1 << "\t| " << graph[i][j] << "\t| ";
			if (via[i][j] == -1)
				cout << "-";
			else
				cout << via[i][j];
		}
	}

	
	int sh[50][50][50];
	for (i = 0; i < nn; i++)
	{
		for (j = 0; j < nn; j++)
		{
			for (k = 0; k < nn; k++)
			{
				
				if ((graph[i][j] > -1) && (graph[j][k] > -1))
				{
					sh[i][j][k] = graph[j][k] + graph[i][j];
				}
				else
				{
					sh[i][j][k] = -1;
				}
			}
		}
	}

	for (i = 0; i < nn; i++)
	{
		cout << "\n\nFor Router " << i + 1;
		cout << "\n-------------";
		for (j = 0; j < nn; j++)
		{
			cout << "\n  From Router " << j + 1;
			for (k = 0; k < nn; k++)
			{
				cout << "\n    Router " << k + 1 << " | " << sh[i][j][k];
			}
		}
	}

	
	int final[50][50];
	for (i = 0; i < nn; i++)
	{
		for (j = 0; j < nn; j++)
		{
			
			final[i][j] = graph[i][j];
			via[i][j] = i;

			
			for (k = 0; k < nn; k++)
			{
				if ((final[i][j] > sh[i][k][j]) || (final[i][j] == -1))
				{
					if (sh[i][k][j] > -1)
					{
						final[i][j] = sh[i][k][j];
						via[i][j] = k;
					}
				}
			}


			if (final[i][j] == -1)
			{
				for (k = 0; k < nn; k++)
				{
					if ((final[i][k] != -1) && (final[k][j] != -1))
					{
						if ((final[i][j] == -1) || ((final[i][j] != -1) && (final[i][j] > final[i][k] + final[k][j])))
						{
							if (final[i][k] + final[k][j] > -1)
							{
								final[i][j] = final[i][k] + final[k][j];
								via[i][j] = k;
							}
						}
					}
				}
			}
		}
	}

	cout << "\n\n**************************************";
	cout << "\n\nAfter Update : ";


	for (i = 0; i < nn; i++)
	{
		cout << "\n\nTable for Router " << i + 1;
		cout << "\n----------------------";
		cout << "\nRouter\t| Dist\t| Via";
		cout << "\n----------------------";
		for (j = 0; j < nn; j++)
		{
			cout << "\n"
				 << j + 1 << "\t| " << final[i][j] << "\t| ";
			if (i == via[i][j])
				cout << "-";
			else
				cout << ch[via[i][j]];
		}
	}

	cout << "\n\n";
	return 0;
}