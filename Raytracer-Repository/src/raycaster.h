#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
//#include </home/lgnos/advRend/lib/Eigen/Eigen/Dense>
#include <Eigen/Dense>

#define DISPLACE_VALUE .001

using namespace std;
using namespace Eigen;

typedef struct Color {
  float r;
  float g;
  float b;
  float f;
} Color;

#define MAX_DISTANCE 10000000


