#include "closest_pair.h"
#include <random>

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

std::vector<Point> random_point_array(int size, int max) {
    std::vector<Point> result;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(-max, max);
    for (int i = 0; i < size; i++) {
        result.push_back(Point(distribution(generator), distribution(generator)));
    }
    return result;
}

int main(int argc, char** argv) {
    int result = Catch::Session().run(argc, argv);
    return result;
    //int size = (argc > 1 ? std::stoi(argv[1]) : 10);
    //std::vector<Point> points = random_point_array(size, size);
    //std::pair<Point, Point> result_pair;
    //auto t1 = std::chrono::high_resolution_clock::now();
    //result_pair = closest_pair(points);
    //auto t2 = std::chrono::high_resolution_clock::now();
    //auto time = std::chrono::duration<double>(t2 - t1).count();
    //std::cout << "SIZE: " << size << '\n';
    //std::cout << "TIME: " << time << '\n';
    //std::cout << "CLOSEST PAIR: " << result_pair.first << ' ' << result_pair.second;
}