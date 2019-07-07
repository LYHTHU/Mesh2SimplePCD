//
// Created by yunhaoli on 19-7-5.
//

#ifndef MESH2SIMPLEPCD_MESHSIMPLIFY_H
#define MESH2SIMPLEPCD_MESHSIMPLIFY_H


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Surface_mesh_simplification/edge_collapse.h>
#include <CGAL/Surface_mesh_simplification/Policies/Edge_collapse/Count_ratio_stop_predicate.h>
#include <CGAL/Surface_mesh_simplification/Policies/Edge_collapse/Count_stop_predicate.h>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_3 Point_3;
typedef CGAL::Surface_mesh<Point_3> Surface_mesh;

namespace SMS = CGAL::Surface_mesh_simplification;
using namespace std;


class MeshSimplify {
public:
    string path;
    bool visible;
    Surface_mesh *mesh = nullptr;
    MeshSimplify(string path="", bool visible = false);
    ~MeshSimplify();
    void simplify(int num_points);
    void save(string& out_path);
};


#endif //MESH2SIMPLEPCD_MESHSIMPLIFY_H
