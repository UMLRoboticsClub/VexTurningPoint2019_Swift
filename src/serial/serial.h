#pragma once

#include <vector>
#include <utility>
#include <string>

typedef std::pair<int, int> Point;

void setCallback(void (*callback)(std::vector<Point>&));
void parseInput(std::string &input, std::vector<Point> &targets);
void readAndParseVisionData();
