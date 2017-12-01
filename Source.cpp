#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
# include <conio.h>
#include <set>
#include <vector>
#include <map>
#include <utility>
#include <climits>
using namespace std;

struct node
{
	int *neighbour= new int[10];
	int *waight=new int[10];
	int top;
};
void putgraph(node *gr,int tops,int edges)
{
	for (int i = 0;i < tops;i++)
	{
		int r = 0;
		cout << "Input key ";
		cin >> gr[i].top;
		cout << "Input count of neighbours ";
		cin >> r;
		while (r>tops-1)
		{
			cout << "Wrong value. Please, try again" << endl;
			cin >> r;
		}
		cout << endl;
		for (int j = 0;j < r;j++)
		{
			cout << "Input key of neighbour ";
			cin >> gr[i].neighbour[j];
			cout << " Input value of edge ";
			cin >> gr[i].waight[j];
			cout << endl;
		}
	}
}
void getgraph(node *gr, int tops, int edges)
{

	for (int i = 0;i < tops;i++)
		{  			
			
				cout << "top "<< gr[i].top<<"  ";
				for (int j = 0;j < 10;j++)
					cout << gr[i].neighbour[j] << ' ';
				cout << endl;

		}

}
void getways(node *gr, int tops, int edges)
{

	for (int i = 0;i < tops;i++)
	{

		cout << "top " << gr[i].top << "  ";
		for (int j = 0;j < 10;j++)
			cout << gr[i].neighbour[j] << ' ';
		cout << endl;

	}

}
void make_matrix_neigh(node *gr, int tops, int edges)
{

	for (int i = 0;i < tops;i++)
	{
		int k = 1;
		int j = 0;
		while (k<tops+1)//for (int j = 0;j < tops;j++)
		{

			if (gr[i].neighbour[j] != k)
			{
				cout << "0 ";
				//cout << gr[i].neighbour[j]<<" "<< k<<"   ";
				k++;
			}
			if (gr[i].neighbour[j] == k)
			{
				cout << "1 ";
				k++;
				j++;
			}
		}
		cout << endl;
	}

}
void make_matrix_wei(node *gr, int tops, int edges)
{

	for (int i = 0;i < tops;i++)
	{
		int k = 1;
		int j = 0;
		while (k<tops + 1)//for (int j = 0;j < tops;j++)
		{

			if ((gr[i].neighbour[j] != k)&&(k-1==i))
			{
				cout << "0 ";
				//cout << gr[i].neighbour[j]<<" "<< k<<"   ";
				k++;
				continue;
			}
			if ((gr[i].neighbour[j] != k) && (k != i))
			{
				cout << "^ ";
				//cout << gr[i].neighbour[j]<<" "<< k<<"   ";
				k++;
				continue;
			}
			if (gr[i].neighbour[j] == k)
			{
				cout << gr[i].waight[j]<< " ";
				k++;
				j++;
				continue;
			}
		}
		cout << endl;
	}

}
void readgraph(node *graph,string buf2,string num,string text,int tops,int edges)
{
	ifstream imfile;
	imfile.open("input.txt");
	cout << tops << endl;
	getline(imfile, buf2);
	getline(imfile, buf2);
	edges = stoi(buf2);
	cout << edges << endl;
	for (int i = 0;i < tops;i++)
	{
		int k = 0;		
		getline(imfile, text);
		graph[i].top = stoi(text);
		cout << graph[i].top << endl;
		getline(imfile, text);
		for (int j = 0;j < text.length();j++)
		{
			if (text.substr(j, 1) != " ")
			{
				num = num + text.substr(j, 1);
			}
			else
			{
				graph[i].neighbour[k] = stoi(num);
				num =' ';
				k++;
				
			}
		
		}
		graph[i].neighbour[k] = stoi(num);
		num = ' ';
		for (int o = 0;o < 10;o++)
			if (graph[i].neighbour[o]>0)
			cout << graph[i].neighbour[o] << ' ';
		cout << endl;
		getline(imfile, text);
		k = 0;
		for (int j = 0;j < text.length();j++)
		{
			if (text.substr(j, 1) != " ")
			{
				num = num + text.substr(j, 1);
			}
			else
			{
				graph[i].waight[k] = stoi(num);
				num = ' ';
				k++;
			}
		}
		graph[i].waight[k] = stoi(num);
		num = ' ';
		for (int o = 0;o < 10;o++)
			if (graph[i].waight[o]>0)
			cout << graph[i].waight[o] << ' ';
		cout << endl;
	}

}
int main()
{
	int tops = 0;
	int edges = 0;
	int menu = -9;
	string text;
	string buf1,buf2;
	string num;

	
	cout << "Read from file? (1-yep/0-no) ";
	cin >> menu;
	cout << endl;
	while ((menu != 0) && (menu != 1))
	{
		cout << "Wrong value. Please enter (1-yep/0-no) ";
		cin >> menu;
		cout << endl;
	}
	if (menu == 1)
	{
		ifstream imfile;
		imfile.open("input.txt");
		getline(imfile, buf1);
		tops = stoi(buf1);
	}
	if (menu == 0)
	{
		cout << "input count of tops ";
		cin >> tops;
		cout << endl;
	}
	node *graph = new node[tops];
	if (menu == 1)
	{
	readgraph(graph, buf2, num, text, tops, edges);
	}

	else
	{
		cout << "input count of edges ";
		cin >> edges;
		cout << endl;
		node *graph = new node[tops];
		putgraph(graph, tops, edges);
	}
	make_matrix_neigh(graph, tops, edges);
	cout << endl;
	cout << endl;
	make_matrix_wei(graph, tops, edges);
	cout << endl;
	getgraph(graph, tops, edges);

}