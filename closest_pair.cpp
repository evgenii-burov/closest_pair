#include "closest_pair.h"

#include <stdexcept>
#include <algorithm>

using namespace std;

double dist(std::pair<Point, Point> pair) {
	return pair.first.distance(pair.second);
}

std::pair<Point, Point> closest_pair_between(const std::vector<Point> &Pleft, const std::vector<Point> &Pright, double d) {
	double Xm = (Pleft.back().x + Pright.front().x) / 2;
	std::vector<Point> Pstripe;
	for (const auto& elem : Pleft) {
		if (abs(Xm - elem.x) < d)
			Pstripe.push_back(elem);
	}
	for (const auto& elem : Pright) {
		if (abs(Xm - elem.x) < d)
			Pstripe.push_back(elem);
	}
	double min_distance = DBL_MAX;
	Point result_p1 = Point(DBL_MIN, DBL_MIN);
	Point result_p2 = Point(DBL_MAX, DBL_MAX);
	std::sort(Pstripe.begin(), Pstripe.end(), [](auto&& p1, auto&& p2) {return p1.y < p2.y; });
	for (int i = 0; i < int(Pstripe.size()) - 1; i++) {
		for (int j = i+1; j < Pstripe.size(); j++) {
			if (Pstripe[i].distance(Pstripe[j]) < min_distance) {
				min_distance = Pstripe[i].distance(Pstripe[j]);
				result_p1 = Pstripe[i];
				result_p2 = Pstripe[j];
			}
			if (Pstripe[i].distance(Pstripe[j]) >= d)
				break;
		}
	}
	auto result = std::make_pair(result_p1, result_p2);
	return result;
}

std::pair<Point, Point> closest_pair(const std::vector<Point> &points) {
	if (points.size() < 2) {
		throw invalid_argument("Not enough points");
	}	
	double min_distance = DBL_MAX;
	Point result_p1, result_p2;

	//Naive implementation

	//for (int i = 0; i < points.size() - 1; i++) {
	//	for (int j = i+1; j < points.size(); j++) {
	//		if (points[i].distance(points[j]) < min_distance) {
	//			min_distance = points[i].distance(points[j]);
	//			result_p1 = points[i];
	//			result_p2 = points[j];
	//		}
	//	}
	//}
	 
	//Implementation using divide and conquer strategy

	if (points.size() <= 3) {
		for (int i = 0; i < int(points.size()) - 1; i++) {
			for (int j = i + 1; j < points.size(); j++) {
				if (points[i].distance(points[j]) < min_distance) {
					min_distance = points[i].distance(points[j]);
					result_p1 = points[i];
					result_p2 = points[j];
				}
			}
		}
	}
	else {
		vector<Point> sorted_points = points;
		sort(sorted_points.begin(), sorted_points.end());
		std::vector<Point> Pleft, Pright;
		for (int i = 0; i < int(sorted_points.size()) / 2; i++)
			Pleft.push_back(sorted_points[i]);
		for (int i = (int(sorted_points.size()) / 2); i < sorted_points.size(); i++)
			Pright.push_back(sorted_points[i]);
		std::pair<Point, Point> pl = closest_pair(Pleft);
		std::pair<Point, Point> pr = closest_pair(Pright);
		double d = min(dist(pl), dist(pr));
		std::pair<Point, Point> pb = closest_pair_between(Pleft, Pright, d);
		if (dist(pl) <= dist(pr) && dist(pl) <= dist(pb)) {
			result_p1 = pl.first;
			result_p2 = pl.second;
		}
		else if ((dist(pr) <= dist(pl) && dist(pr) <= dist(pb))) {
			result_p1 = pr.first;
			result_p2 = pr.second;
		}
		else if ((dist(pb) <= dist(pl) && dist(pb) <= dist(pr))) {
			result_p1 = pb.first;
			result_p2 = pb.second;
		}
	}

	auto result = std::make_pair(result_p1, result_p2);
	return result;
}