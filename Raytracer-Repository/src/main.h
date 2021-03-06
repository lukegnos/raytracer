#pragma once 

#include "raycaster.h"
#include "Parser.h"
#include "HitObject.h"
#include "Camera.h"
#include "DrawableObject.h"
#include "Plane.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Image.h"
#include "LightSource.h"
#include "Finish.h"
#include "Ray.h"
#include "Scene.h"
#include "BoundBox.h"
#include "bvhNode.h"

#define RECURSE_DEPTH 5
#define AA_NUM 9
#define IOR_AIR 1
#define GI_NUMRAYS 128

typedef struct View {
  double right;
  double left;
  double top;
  double bottom;
} View;

//Function Declarations

//Support / Debug Functions
void checkArgs(int argc, char *argv[]);
View getView(Scene *scene);
Ray getDistRay(View v, int i, int j, int k, Scene *scene);
float getDistOffset(int k);
void printValues(Scene *scene);
void printTree(bvhNode *node);

//Ray functions
void manageRaycast(Scene *scene);
Color sendPrimaryRays(View view, int i, int j, Scene *scene);
Color raytrace(Ray inRay, Scene *scene, int depthCount);
Color refract(HitObject hit, Ray ray, Scene *scene, int depthCount);
Vector3f computeRefracVec(float n1, float n2, Vector3f d, Vector3f N);
Color reflect(HitObject hit, Ray ray, Scene *scene, int depthCount);
HitObject castRay(Ray *ray, Scene *scene);

//Color Functions
Color computeColor(HitObject hit, Scene *scene, int depthCount);
Color getAmbientColor(HitObject hit, Scene *scene, int depthCount);
Color computeRefrColor(float R, Color locColor, Color refrColor);
Color computeReflColor(float refl, Color locColor, Color reflColor);
float computeRValue(float ior, float cosTheta);
Color getGlobalIllum(HitObject hit, Scene *scene, int depthCount);
Vector3f getRandomRayDir();
Color getBRDFColor(HitObject hit, Scene *scene);
