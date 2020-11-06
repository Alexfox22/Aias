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
	vector<int> neighbour;
	vector<int> waight;
	//int *neighbour = new int[100];
	//int *waight = new int[100];
	int top;
	int color;
};
struct rib {
	int beg;
	int end;
	int wai;
};
struct minimum
{
	int min;
	int pos;
	int str;
};
void outputio(int tops,node* masKr)
{
	for (int i = 0;i < tops;i++)		//вывод
	{
		int f = 0;
		if (masKr[i].top > 0)
			cout << masKr[i].top << endl;
		while (f<masKr[i].neighbour.size())
		{
			cout << masKr[i].neighbour[f] << "  ";

			f++;
		}
		cout << endl;
		int fu = 0;
		while (fu <masKr[i].waight.size())
		{
			cout << masKr[i].waight[fu] << "  ";
			fu++;
		}
		cout << endl;

		cout << endl;
	}
}
void sortnode(rib* in,int edges)
{
	int lenD = edges;
	
	int keyw = 0;
	int keyb = 0;
	int keye = 0;
	int i = 0;
	for (int j = 1;j < lenD;j++) {
		keyw = in[j].wai;
		keyb = in[j].beg;
		keye = in[j].end;
		i = j - 1;
		while (i >= 0 && in[i].wai > keyw)
			{
				in[i + 1].wai = in[i].wai;
				in[i + 1].beg = in[i].beg;
				in[i + 1].end = in[i].end;
				i = i - 1;
				in[i + 1].wai = keyw;
				in[i + 1].beg = keyb;
				in[i + 1].end = keye;
			}
		
	}
}

//void putgraph(node *gr,int tops,int edges)
//{
//	for (int i = 0;i < tops;i++)
//	{
//		int r = 0;
//		cout << "Input key ";
//		cin >> gr[i].top;
//		cout << "Input count of neighbours ";
//		cin >> r;
//		while (r>tops-1)
//		{
//			cout << "Wrong value. Please, try again" << endl;
//			cin >> r;
//		}
//		cout << endl;
//		int k = 0;
//			cout << "Input key of neighbour ";
//			cin >> k;
//			gr[i].neighbour.push_back(k);
//			cout << " Input value of edge ";
//			cin >> k;
//			gr[i].waight.push_back(k);
//			cout << endl;
//		
//	}
//}
void getgraph(node *gr, int tops)
{

	for (int i = 0;i < tops;i++)
		{  			
			
				cout << "top "<< gr[i].top<<"  ";
				for (int j = 0;j < gr[i].neighbour.size();j++)
					cout << gr[i].neighbour[j] << ' ';
				cout << endl;

		}

}
void getways(node *gr, int tops)
{
	for (int i = 0;i < tops;i++)
	{	
		cout << "top " << gr[i].top << "  ";
		for (int j = 0;j < gr[i].neighbour.size();j++)
		{
			if (gr[i].neighbour[j] > 0)
			{
				cout << gr[i].neighbour[j] << ' ';
			}
		}
		cout << endl;
	}
}
//void make_matrix_neigh(node *gr, int tops, int edges)
//{
//
//	for (int i = 0;i < tops;i++)
//	{
//		
//		for (int j=0;j < gr[i].neighbour.size()j++)
//		{
//			for (int k = 1;k < tops + 1;k++)
//			{
//				
//					if (gr[i].neighbour[j] == k)
//					{
//						cout << "1 ";
//						j++;
//							cout << "fasas"<<gr[i].neighbour[j]<<" "<< k<<"   ";
//
//					}
//					else /*(gr[i].neighbour[j] == k)*/
//					{
//						cout << "0 ";
//						
//					}
//				}
//			
//		}
//		cout << endl;
//	}
//
//}
void outp(int **mas,int tops)
{
	for (int j = 0;j < tops;j++)
	{
		for (int i = 0;i < tops;i++)
		{
			cout << mas[j][i];
			if ((mas[i][j]-10)>0)
				cout<< " ";
			else cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
void make_matrix_wei(node *gr, int tops,int **mas)
{

	for (int i = 0;i < tops;i++)
	{
		for (int j = 0;j < tops;j++)
		{
			mas[i][j] = INT_MAX - 1;
		}
	}
	for (int i=0;i<tops;i++)
	{
		for (int j = 0;j < gr[i].neighbour.size();j++)
		{
			mas[i][gr[i].neighbour[j]-1] = gr[i].waight[j];

		}
	
	}
		/*}
		cout << endl;
	}*/

}
minimum findmin(int start,int tops, int *mas,int pos)
{
	minimum min;
	min.min = INT_MAX;
	for(int k=0;k<tops;k++)
	{
		if ((mas[k]>start)&&(mas[k] < min.min) && (mas[k] > 0))
		{
			min.min = mas[k];
			min.pos = k;
			
		}
	}
	return min;
}
int readgraph(node *graph,string buf2,string num,string text,int tops,int edges)
{
	int res = 0;
	ifstream imfile;
	imfile.open("input1.txt");
	cout << tops << endl;
	getline(imfile, buf2);
	string ty;
	getline(imfile, ty);
	cout << ty<<"((((((((((";
	edges = stoi(ty);
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
				graph[i].neighbour.push_back(stoi(num));
				num =' ';
				k++;
				
			}
		
		}
		graph[i].neighbour.push_back(stoi(num));
		num = ' ';
		for (int o = 0;o < graph[i].neighbour.size();o++)
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
				graph[i].waight.push_back(stoi(num));
				num = ' ';
				k++;
			}
		}
		graph[i].waight.push_back(stoi(num));
		num = ' ';
		for (int o = 0;o < graph[i].waight.size();o++)
			if (graph[i].waight[o]>0)
			cout << graph[i].waight[o] << ' ';
		cout << endl;
	}
	res=edges;
	return res;
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
	string buf1, buf2;
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
		imfile.open("input1.txt");
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
	node *resPrim = new node[tops];			//результат для Прима
	node *resKrus = new node[tops];			//результат для Прима
	minimum *masmin = new minimum[tops];
	for (int i = 0;i < tops;i++)
	{
		mas[i] = new int[tops];
		masmin[i].min = 0;
	}

	if (menu == 1)
	{
		edges=readgraph(graph, buf2, num, text, tops, edges);
		cout << edges << "<------";
	}
	else
	{
		cout << "input count of edges ";
		cin >> edges;
		cout << endl;
		node *graph = new node[tops];
	//	putgraph(graph, tops, edges);
	}
	for (int i = 0;i < tops;i++)
		graph[i].color = 0;
//	make_matrix_neigh(graph, tops, edges);
	cout << endl;
	cout << endl;
	make_matrix_wei(graph, tops, mas);
	cout << endl;
	getgraph(graph, tops);
	bool minfound = false;
	cout << endl;
	outp(mas, tops);
	bool *str = new bool[tops];				//СТРОКИ, КОТОРЫЕ ВКЛЮЧЕНЫ В ПОИСК МИНИМУМА
	for (int i = 0;i < tops;i++)
		str[i] = false;
	bool *strcycle = new bool[tops];			//ИЗМЕНЯЕТСЯ ВНУТРИ ЦИКЛА
	for (int i = 0;i < tops;i++)
		strcycle[i] = false;
	int isfullstr = 0;

	node *masKr = new node[tops];
	for (int i = 0;i < tops;i++)
	{
		masKr[i] = graph[i];
	}

	str[0] = true;			//первую строку открыли для поиска
	strcycle[0] = true;
	graph[0].color = 1;
	int k = 0;



	while (k < tops - 1)			//идём по вершинам
	{
		minimum minimus;
		minimus.min = INT_MAX;
		for (int i = 0;i < tops;i++)
		{

			if (str[i] == true)			//идём по открытым вершинам
			{
				int popo = 0;
				int kr;
				while ((graph[findmin(popo, tops, mas[i], pos).pos].color == 1) && (graph[i].color == 1))
				{
					//cout << findmin(popo, tops, mas[i], pos).min<< "  BAD REBRO " << i + 1 << "," << findmin(popo, tops, mas[i], pos).pos + 1 << "  " << graph[findmin(popo, tops, mas[i], pos).pos].IsBlue << " " << graph[i].IsBlue << endl;
					kr = findmin(popo, tops, mas[i], pos).min;
					//cout << "kr " << kr << endl;
					popo = kr;
					if (popo == INT_MAX - 1) break;
				}
				if (findmin(popo, tops, mas[i], pos).min < INT_MAX)
					minfound = true;		//если минимум остался
				if ((minfound == true))
				{
					//cout << "  str[" << i << "] == true  ";
					//cout << "truemin  ";

					masmin[i] = findmin(popo, tops, mas[i], pos);
					//cout << "masmin[" << i << "].min" << masmin[i].min << "  ";

					cout << masmin[i].pos << " <------ " << masmin[i].min << "   ";
					//cout << "REBRO " <<i+1<<","<< masmin[i].pos+1 <<"  "<< graph[masmin[i].pos].IsBlue<<" " << graph[i].IsBlue << endl;
					if ((masmin[i].min < minimus.min) && (((graph[masmin[i].pos].color == 0) && (graph[i].color == 1)) || ((graph[masmin[i].pos].color == 1) && (graph[i].color == 0))))//запоминаем минимальный по открытым строкам
					{
						//cout << " ___entered___" << graph[masmin[i].pos].IsBlue << endl;
						minimus.min = masmin[i].min;
						minimus.pos = masmin[i].pos;
						minimus.str = i;
					}

					minfound = false;


					cout << endl;
				}
			}
		}
		if (graph[minimus.pos].color == 0)
		{
			graph[minimus.pos].color = 1;
			cout << "  top " << minimus.pos + 1 << " added to blue tops " << endl;
		}
		if (strcycle[minimus.pos] == false)
		{
			strcycle[minimus.pos] = true;
			isfullstr++;
		}
		if (isfullstr + 1 == tops)
			for (int u = 0;u < tops;u++)
				if (strcycle[u] == false) strcycle[u] == true;
		cout << "MINIMUS---->" << minimus.min << " POS---->" << minimus.pos << " STR---->" << minimus.str << endl;

		resPrim[minimus.str].neighbour.push_back(minimus.pos + 1);
		resPrim[minimus.str].waight.push_back(minimus.min);
		resPrim[minimus.str].top = minimus.str + 1;

		k++;
		mas[minimus.str][minimus.pos] = INT_MAX;
		mas[minimus.pos][minimus.str] = INT_MAX;
		//outp(mas, tops);
		for (int i = 0;i < tops;i++)
			str[i] = strcycle[i];
	}
	for (int i = 0;i < tops;i++)		//вывод
	{
		int f = 0;
		if (resPrim[i].top > 0)
			cout << resPrim[i].top << endl;
		while (f<resPrim[i].neighbour.size())
		{
			cout << resPrim[i].neighbour[f] << "  ";

			f++;
		}
		cout << endl;
		int fu = 0;
		while (fu <resPrim[i].waight.size())
		{
			cout << resPrim[i].waight[fu] << "  ";
			fu++;
		}
		cout << endl;

		cout << endl;
	}

	make_matrix_wei(resPrim, tops, mas);
	outp(mas, tops);


	int RIB = edges*2;
	rib *Kr = new rib[RIB];
	int u = 0;
	while (u < RIB)
	{
		cout << edges << "<----";
		for (int j = 0;j < tops;j++)
		{
			for (int k = 0;k < masKr[j].neighbour.size();k++)
			{
				Kr[u].beg = j+1;
				cout << "Kr[u].beg = " << Kr[u].beg;
				Kr[u].end = masKr[j].neighbour[k];
				cout << " Kr[u].end = " << Kr[u].end;
				Kr[u].wai = masKr[j].waight[k];
				cout << " Kr[u].wai = " << Kr[u].wai;
				cout << endl;
				u++;
			}
		}
	}
	cout << endl;
	sortnode(Kr, RIB);
	for(int u=0;u<RIB;u++)
	{
		
		cout << "Kr[u].beg = " << Kr[u].beg;
		
		cout << " Kr[u].end = " << Kr[u].end;
		
		cout << " Kr[u].wai = " << Kr[u].wai;
		cout << endl;
	}
	cout << endl;
	int i = 0;
	int countmn = 2;
	masKr[Kr[0].beg-1].color = 1;
	for (int j = 0;j < RIB;j++)
	{
		cout << "color"<< masKr[Kr[j].beg-1].top <<"---" << masKr[Kr[j].beg - 1].color << "---color"<< masKr[Kr[j].end-1].top<<"---" << masKr[Kr[j].end - 1].color << endl;
		if (((masKr[Kr[j].beg-1].color ==0) && (masKr[Kr[j].end-1].color !=0))|| ((masKr[Kr[j].beg - 1].color != 0) && (masKr[Kr[j].end - 1].color == 0)))//||((masKr[Kr[j].beg - 1].color != masKr[Kr[j].end - 1].color)))
		{
			
			cout << "Kr[u].beg = " << Kr[j].beg;

			cout << " Kr[u].end = " << Kr[j].end;

			cout << " Kr[u].wai = " << Kr[j].wai;
			cout << endl;
			if (masKr[Kr[j].beg - 1].color == 0)
			{
				masKr[Kr[j].beg - 1].color = masKr[Kr[j].end - 1].color;
				cout << "top " << Kr[j].beg << " get new color "<< masKr[Kr[j].beg - 1].color;
				cout << endl;
			}
			if (masKr[Kr[j].end - 1].color == 0)
			{
				masKr[Kr[j].end - 1].color = masKr[Kr[j].beg - 1].color;
				cout << "top " << Kr[j].end << " get new color " << masKr[Kr[j].end - 1].color;
				cout << endl;
			}
		}
		if ((masKr[Kr[j].beg - 1].color == 0) && (masKr[Kr[j].end - 1].color == 0))
		{
			cout << "Kr[u].beg = " << Kr[j].beg;

			cout << " Kr[u].end = " << Kr[j].end;

			cout << " Kr[u].wai = " << Kr[j].wai;
			cout << endl;
			masKr[Kr[j].beg - 1].color = countmn;
			cout << "top " << Kr[j].beg << " was opened "<< masKr[Kr[j].beg - 1].color;
			cout << endl;
			masKr[Kr[j].end - 1].color = countmn;
			cout << "top " << Kr[j].end << " was opened "<< masKr[Kr[j].end - 1].color;
			cout << endl;
			countmn++;
		}
		if (((masKr[Kr[j].beg - 1].color != masKr[Kr[j].end - 1].color)) && ((masKr[Kr[j].beg - 1].color > 0) && (masKr[Kr[j].end - 1].color > 0)))
		{

			cout << "Kr[u].beg = " << Kr[j].beg;

			cout << " Kr[u].end = " << Kr[j].end;

			cout << " Kr[u].wai = " << Kr[j].wai;
			cout << endl;
			if (masKr[Kr[j].end - 1].color > masKr[Kr[j].beg - 1].color)
			{
				cout << "hey, " << masKr[Kr[j].end - 1].color << " > " << masKr[Kr[j].beg - 1].color << endl;
				masKr[Kr[j].end - 1].color= masKr[Kr[j].beg - 1].color;
				cout << "top " << Kr[j].end << " was changed, color: "<< masKr[Kr[j].end - 1].color;
				cout << endl;
				for (int y = 0;y < masKr[Kr[j].end - 1].neighbour.size();y++)
				{
					if (masKr[masKr[Kr[j].end - 1].neighbour[y] - 1].color > 1)
					{
						cout << "--color--" << masKr[masKr[Kr[j].end - 1].neighbour[y] - 1].color;
						masKr[masKr[Kr[j].end - 1].neighbour[y] - 1].color= masKr[Kr[j].beg - 1].color;
						cout << " from " << masKr[masKr[Kr[j].end - 1].neighbour[y] - 1].top << " <--- was changed " << endl;
					}
				}
			}
			else //if (masKr[Kr[j].end - 1].color < masKr[Kr[j].beg - 1].color)
			{
				cout << "hey, " << masKr[Kr[j].beg - 1].color << " > " << masKr[Kr[j].end - 1].color << endl;
				masKr[Kr[j].beg - 1].color= masKr[Kr[j].end - 1].color;
				cout << "top " << Kr[j].beg << " was changed, color: " << masKr[Kr[j].beg - 1].color;
				cout << endl;
				for (int y = 0;y < masKr[Kr[j].beg - 1].neighbour.size();y++)
				{
					if (masKr[masKr[Kr[j].beg - 1].neighbour[y] - 1].color)
					{
						cout << "--color--" << masKr[masKr[Kr[j].beg - 1].neighbour[y] - 1].color;
						masKr[masKr[Kr[j].beg - 1].neighbour[y] - 1].color= masKr[Kr[j].end - 1].color;
						cout << " from " << masKr[masKr[Kr[j].beg - 1].neighbour[y] - 1].top << " <--- was changed " << endl;;
					}
				}
			}
		}


		



		i++;
	}

}