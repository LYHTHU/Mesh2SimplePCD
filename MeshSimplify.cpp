//
// Created by yunhaoli on 19-7-5.
//

#include "MeshSimplify.h"

MeshSimplify::MeshSimplify(string path, bool visible) {
    this->path = path;
    this->visible = visible;
    ifstream input(path);
    if (!input)
    {
        cerr << "Cannot open file " << endl;
        exit(1);
    }
    this->mesh = new Surface_mesh();
    input >> *(this->mesh);
}

MeshSimplify::~MeshSimplify() {
    delete this->mesh;
    this->mesh = nullptr;
}

void MeshSimplify::simplify(int num_points, int num_faces) {

}

void MeshSimplify::save(string& out_path) {
    ofstream os(out_path);
    os << *(this->mesh);
}