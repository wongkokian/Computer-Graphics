//============================================================
// STUDENT NAME: Wong Kok Ian
// NUS User ID.: e0418183
// COMMENTS TO GRADER:
//
// ============================================================

#include <cmath>
#include "Sphere.h"

using namespace std;



bool Sphere::hit( const Ray &r, double tmin, double tmax, SurfaceHitRecord &rec ) const 
{
    //***********************************************
    //*********** WRITE YOUR CODE HERE **************
    //***********************************************

    Vector3d oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = 2 * dot(r.direction(), oc);
    double c = dot(oc, oc) - pow(radius, 2);
    double disc = pow(b, 2) - (4 * a * c);
    double t0;

    if (disc < 0) {
        return false;
    }
    else if (disc == 0) {
        t0 = -b / (2 * a);
    }
    else {
        double t1 = (-b + sqrt(disc)) / (2 * a);
        double t2 = (-b - sqrt(disc)) / (2 * a);
        t0 = min(t1, t2);
    }

    if (t0 < tmin || t0 > tmax) {
        return false;
    }

    // We have a hit -- populate hit record. 
    rec.t = t0;
    rec.p = r.pointAtParam(t0);
    rec.normal = r.pointAtParam(t0) - center;
    rec.material = material;
    return true;
}



bool Sphere::shadowHit( const Ray &r, double tmin, double tmax ) const 
{
    //***********************************************
    //*********** WRITE YOUR CODE HERE **************
    //***********************************************

    Vector3d oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = 2 * dot(r.direction(), oc);
    double c = dot(oc, oc) - pow(radius, 2);
    double disc = pow(b, 2) - (4 * a * c);
    double t0;

    if (disc < 0) {
        return false;
    }
    else if (disc == 0) {
        t0 = -b / (2 * a);
    }
    else {
        double t1 = (-b + sqrt(disc)) / (2 * a);
        double t2 = (-b - sqrt(disc)) / (2 * a);
        t0 = min(t1, t2);
    }
    return (t0 >= tmin && t0 <= tmax);
}
