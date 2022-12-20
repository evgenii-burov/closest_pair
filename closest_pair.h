#pragma once

#include "point.h"

#include <vector>

// Compute the distance between two points in a pair
double dist(std::pair<Point, Point> pair);

// Find the closest pair of points that are
// less than d distance away on x axis from the
// x coordinate boundary between Pleft and Pright
std::pair<Point, Point> closest_pair_between(const std::vector<Point>& Pleft, const std::vector<Point>& Pright, double d);

// Find the closest pair of points from given points
std::pair<Point, Point> closest_pair(const std::vector<Point> &points);
