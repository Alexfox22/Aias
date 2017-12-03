#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
# include <conio.h>
#include <vector>

using namespace std;

struct node
{
	//vector<int> neighbour;
	//vector<int> waight;
	int *neighbour = new int[100];
	int *waight = new int[100];
	int top;
	bool IsBlue;
};
struct minimum
{
	int min;
	int pos;
	int str;
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
		{
			if (gr[i].neighbour[j] > 0)
			{
				cout << gr[i].neighbour[j] << ' ';
			}
		}
		cout << endl;
	}
}
void make_matrix_neigh(node *gr, int tops, int edges)
{

	for (int i = 0;i < tops;i++)
	{
		
		int j = 0;
		for (int k = 1;k < tops+1;k++)
		{

			if (gr[i].neighbour[j] != k)
			{
				cout << "0 ";
				//cout << "fasas"<<gr[i].neighbour[j]<<" "<< k<<"   ";
				
			}
			else /*(gr[i].neighbour[j] == k)*/
			{
				cout << "1 ";
				j++;
			}
		}
		cout << endl;
	}

}
void outp(int **mas,int tops)
{
	for (int j = 0;j < tops;j++)
	{
		for (int i = j;i < tops;i++)
			cout << mas[j][i] << " ";
		cout << endl;
	}
	cout << endl;
}
void make_matrix_wei(node *gr, int tops, int edges,int **mas)
{

	for (int i = 0;i < tops;i++)
	{
		int k = 1;
		int j = 0;
		for (int k = 1;k < tops + 1;k++)
		{

			if (gr[i].neighbour[j] != k)
			{
				if (k - 1 == i)
				{
					cout << "0 ";
					mas[i][k - 1] = 0;
					//cout << gr[i].neighbour[j]<<" "<< k<<"   ";
				}
				if (k-1 != i)
				{
					cout << "^ ";
					mas[i][k - 1] = 0;
					//cout << gr[i].neighbour[j]<<" "<< k<<"   ";
					
				}
			}
			if (gr[i].neighbour[j] == k)
			{
				cout << gr[i].waight[j] << " ";
				mas[i][k - 1] = gr[i].waight[j];

				j++;
			}

		}
		cout << endl;
	}

}
minimum findmin(int start,int tops, int *mas,int pos)
{
	minimum min;
	min.min = INT_MAX;
	for(int k=start;k<tops;k++)
	{
		if ((mas[k] < min.min) && (mas[k] > 0))
		{
			min.min = mas[k];
			min.pos = k;
			
		}
	}
	return min;
}
void readgraph(node *graph,string buf2,string num,string text,int tops,int edges)
{
	ifstream imfile;
	imfile.open("input1.txt");
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
int insertsortpos(int *mas, int len, int key)
{
	if (mas[0] == 0)
		return 0;
	int k = 1;
	while (mas[k] < key) k++;
	for (int i = key;i < len;i++)
	{
		int buf;
		buf = mas[i];
		mas[i] = key;
		mas[i + 1] = buf;
	}
	return k;
}
//void make_podgr(node *mas, minimum *min,int tops)
//{
//	for (int i = 0;i < tops-1;i++)
//	{
//		mas[i].top = i+1;
//		
//		mas[i].neighbour[0] = min[i].pos + 1;
//		
//		mas[i].waight[0] = min[i].min;
//		
//	}
//
//}
int main()
{
	int tops = 0;
	int edges = 0;
	int menu = INT_MIN;
	string text;
	string buf1,buf2;
	string num;
	int pos = 0;
	minimum min;
	
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
	int **mas = new int*[tops];
	node *resPrim = new node[tops];			//ðåçóëüòàò äëÿ Ïðèìà
	minimum *masmin = new minimum[tops];

	for (int i = 0;i < tops;i++)
	{
		mas[i] = new int[tops];
		masmin[i].min = 0;
	}
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
	for (int i = 0;i < tops;i++)
		graph[i].IsBlue = false;
	make_matrix_neigh(graph, tops, edges);
	cout << endl;
	cout << endl;
	make_matrix_wei(graph, tops, edges,mas);
	cout << endl;
	getgraph(graph, tops, edges);
	bool minfound=false;
	cout << endl;
	outp(mas, tops);
	bool *str = new bool[tops];				//ÑÒÐÎÊÈ, ÊÎÒÎÐÛÅ ÂÊËÞ×ÅÍÛ Â ÏÎÈÑÊ ÌÈÍÈÌÓÌÀ
	for (int i = 0;i < tops;i++)
		str[i] = false;
	bool *strcycle = new bool[tops];			//ÈÇÌÅÍßÅÒÑß ÂÍÓÒÐÈ ÖÈÊËÀ
	for (int i = 0;i < tops;i++)
		strcycle[i] = false;
	//int **OOVOO = new int*[tops];
	//for (int i = 0;i < tops;i++)
	//	OOVOO = new int*[tops];
	//for (int i = 0;i < tops;i++)
	//	for (int j = 0;j < tops;j++)
	//		OOVOO[i][j] = 0;
	int isfullstr = 0;
	
	
	str[0] = true;			//ïåðâóþ ñòðîêó îòêðûëè äëÿ ïîèñêà
	strcycle[0] = true;
	int k = 0;
	int *massivekoef = new int[tops];
	for (int i = 0;i < tops;i++)
		massivekoef[i] = -1;
	while (k < tops - 1)			//èä¸ì ïî âåðøèíàì
	{
		minimum minimus;
		minimus.min = INT_MAX;
		for (int i = 0;i < tops ;i++)
		{
		
			if (str[i] == true)			//èä¸ì ïî îòêðûòûì âåðøèíàì
			{
				
				if (findmin(i, tops, mas[i], pos).min < 9999) minfound = true;		//åñëè ìèíèìóì îñòàëñÿ
				if ((minfound == true))
				{
					cout << "  str[" << i << "] == true  ";
					cout << "truemin  ";
					//int mem = masmin[i].min;
					masmin[i] = findmin(i, tops, mas[i], pos);
					
					cout << "masmin[" << i << "].min" << masmin[i].min << "  ";
					//memory = i;
					cout << masmin[i].pos << " <------ " << masmin[i].min << "   ";
					if (masmin[i].min < minimus.min)		//çàïîìèíàåì ìèíèìàëüíûé ïî îòêðûòûì ñòðîêàì
					{
						minimus.min = masmin[i].min;
						minimus.pos = masmin[i].pos;
						minimus.str = i;
					}
					//else masmin[i].min=mem;
				/*	else { masmin[i].min = mem; }*/
					
						if (graph[masmin[i].pos].IsBlue == false)
						{
							graph[masmin[i].pos].IsBlue = true;
							cout << "  top " << masmin[i].pos << "added to blue tops ";
							
						}
						//cout << strcycle[masmin[i].pos] << endl;
						

						minfound = false;

						
						cout << endl;
				}
			}
		}
		if (strcycle[minimus.pos] == false)
		{
			strcycle[minimus.pos] = true;
			isfullstr++;
		}
		if (isfullstr + 1 == tops)
			for (int u = 0;u < tops ;u++)
				if (strcycle[u] == false) strcycle[u] == true;
		cout << "MINIMUS---->" << minimus.min <<" POS---->"<< minimus.pos<< " STR---->" << minimus.str << endl;
		massivekoef[minimus.str]++;
		resPrim[minimus.str].neighbour[massivekoef[minimus.str]]=minimus.pos+1;
		resPrim[minimus.str].waight[massivekoef[minimus.str]] = minimus.min;
		resPrim[minimus.str].top = minimus.str+1;
		k++;
		mas[minimus.str][minimus.pos] = INT_MAX;
		outp(mas, tops);
		for (int i = 0;i < tops;i++)
			str[i] = strcycle[i];
	}

	for (int i = 0;i < tops-1;i++)
	{
		int f = 0;
		if (resPrim[i].top>0)
		cout << resPrim[i].top << endl;
		while (resPrim[i].neighbour[f] > 0)
		{
			cout << resPrim[i].neighbour[f] << "  ";
			
			f++;
		}
		cout << endl;
		int fu = 0;
		while (resPrim[i].waight[fu] > 0)
		{
			cout << resPrim[i].waight[fu]<<"  " ;
			fu++;
		}
		cout << endl;
		cout << endl;
	}
}