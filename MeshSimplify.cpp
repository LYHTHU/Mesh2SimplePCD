//
// Created by yunhaoli on 19-7-5.
//

#include "MeshSimplify.h"

MeshSimplify::MeshSimplify(string path, bool visible) {
    this->path = path;
    this->visible = visible;
}

MeshSimplify::MeshSimplify(Polyhedron *obj, bool visible) {
    this->mesh = obj;
    this->visible = visible;
}

void MeshSimplify::simplify(int num_points, int num_faces) {

}

void MeshSimplify::save(string out_path) {

}