#pragma once

#include "raycaster.h"
#include "DrawableObject.h"
#include "HitObject.h"
#include "Finish.h"
#include "Scene.h"
#include "BoundBox.h"

class Box : public DrawableObject {
 public:
  Box();
  Box(Vector3f c1, Vector3f c2, Finish f, Color c, Matrix4f ctm);
  Box(Vector3f v1, Vector3f v2, Matrix4f ctm);
  
  void printValues();
  HitObject getIntersections(Ray *ray);
  Ray getTransformRay(Ray *ray, Matrix4f inverse);
  void getHitValues(HitObject *res, float near, Ray *tray,
		    Ray *oray, Vector3f *mins, Vector3f *maxs,
		    Matrix4f inverse, bool flipN);
  Vector3f getNormal(Vector3f p, Vector3f *mins, Vector3f *maxs);
  void computeMinMax(Vector3f *mins, Vector3f *maxs);
  bool checkDimension(float *tgmin, float *tgmax, float min,
		      float max, float point, float dir);
  BoundBox getBoundingBox();
  Vector3f getTransformedPoint(Vector3f op, Matrix4f m);

  
  Vector3f corner1;
  Vector3f corner2;
  Vector3f tcenter;
  Color color;
  Finish finish;
  Matrix4f CTM;
  bool isBounding;
};
