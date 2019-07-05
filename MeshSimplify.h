//
// Created by yunhaoli on 19-7-5.
//

#ifndef MESH2SIMPLEPCD_MESHSIMPLIFY_H
#define MESH2SIMPLEPCD_MESHSIMPLIFY_H


#include <iostream>
#include <string>
#include <CGAL/Polyhedron_3.h>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef CGAL::Polyhedron_3<Kernel>     Polyhedron;

using namespace std;
using namespace CGAL;


class MeshSimplify {
public:
    string path;
    bool visible;
    Polyhedron *mesh = nullptr;

    MeshSimplify(string path="", bool visible = false);
    MeshSimplify(Polyhedron *obj, bool visible);

    void simplify(int num_points, int num_faces);
    void save(string out_path);

};


#endif //MESH2SIMPLEPCD_MESHSIMPLIFY_H
