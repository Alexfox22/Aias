//#pragma once
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <cstdlib>
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <functional>   // std::greater
//#include <cassert>
//using namespace std;
//
//const int INF = 1e9 + 7;
//
//vector<pair<int, int>> graph[100000];
//bool used[100000];      //�������� �� �� ��������������� ������� � �����
//
//int main() {
//	//���� �����...
//
//	int mst_weight = 0;     //������� ��� ������.
//
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//
//	q.push({ 0, 0 });     //����� � ������� 0.
//
//	while (!q.empty()) {
//		pair<int, int> c = q.top();
//		q.pop();
//
//		int dst = c.first, v = c.second;
//
//		if (used[v]) {      //������� ��� ��������� � �����
//			continue;
//		}
//
//		used[v] = true;
//		mst_weight += dst;
//
//		for (pair<int, int> e : graph[v]) {
//			int u = e.first, len_vu = e.second;
//
//			if (!used[u]) {
//				q.push({ len_vu, u });    //��������: �� ��������� ������ ����� �����.
//			}
//		}
//	}
//
//	cout << "Minimum spanning tree weight: " << mst_weight << endl;
//}