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

// not related, or yes but not really
struct Line { Point p1, p2; };
int turn(Point p, Point q, Point r)
{
	int res = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
	if (res < 0) { return -1; } // P->Q-R is a right turn
	if (res > 0) { return 1; } //P->Q->R is left turn
	return 0; //this is a straight line, other words p q r are collinear

			  /*
			  Note: sometimes, we change the ’> 0’ to ’>= 0’ to accept collinear points bool ccw(point p, point q, point r) { return (turn(p, q, r) > 0); }
			  With the library code above, we can now check if a polygon is convex by verifying
			  if all three consecutive points in the polygon make left-turns if visited in counter clockwise order.
			  If we can ﬁnd at least one triple where this is false, the polygon is concave.
			  */
}
bool ccw(Point p, Point q, Point r) { return (turn(p, q, r) > 0); }
int intersect(Line line1, Line line2)
{
	return
		((ccw(line1.p1, line1.p2, line2.p1) * ccw(line1.p1, line1.p2, line2.p2)) <= 0)
		&&
		((ccw(line2.p1, line2.p2, line1.p1) * ccw(line2.p1, line2.p2, line1.p2)) <= 0);
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




