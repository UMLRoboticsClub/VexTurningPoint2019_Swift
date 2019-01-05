#pragma once

#include <vector>
#include <utility>
#include <string>

typedef std::pair<int, int> Point;

void setVisionCallback(void (*callback)(std::vector<Point>&));
void parseInput(std::string &input, std::vector<Point> &targets);
void readAndParseVisionData(void*);
void serialHeartbeat(void*);
void getTargets(std::vector<Point> &targets);
