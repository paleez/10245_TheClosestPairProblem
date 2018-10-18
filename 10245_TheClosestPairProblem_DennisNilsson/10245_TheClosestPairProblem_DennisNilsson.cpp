// 10245_TheClosestPairProblem_DennisNilsson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
struct Point { double x, y; };
double distance(Point &p1, Point &p2)
{
	return std::sqrt((p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y));
}
double closestPair(std::vector<Point> arr)
{
	float minDist = 100000;
	int arrSize = arr.size();
	int arSize = arr.size() - 1;
	for (int i = 0; i < arSize; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (distance(arr[i], arr[j]) < minDist)
			{
				minDist = distance(arr[i], arr[j]);
			}
		}
	}
	return minDist;
}


int main()
{
	int nops;
	while (std::cin >> nops)
	{
		std::vector<Point> arr(nops);
		if (nops == 0)
		{
			break;
		}
		for (size_t i = 0; i < nops; i++)
		{
			double x, y;
			std::cin >> x >> y;
			arr[i].x = x;
			arr[i].y = y;
		}
		double dist;
		dist = closestPair(arr);
		if (dist < 10000)
		{
			std::cout << std::fixed << std::setprecision(4) << dist;
			
		}
		else
		{
			std::cout << "INFINITY";
		}
	}
	return 0;
}




