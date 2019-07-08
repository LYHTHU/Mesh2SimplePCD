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
    if (!input) {
        cerr << "Cannot load file " << endl;
        exit(1);
    }
}

MeshSimplify::~MeshSimplify() {
    delete this->mesh;
    this->mesh = nullptr;
}

void MeshSimplify::simplify(int num_points) {
    if (this->visible) {
        num_points = min(num_points, int(this->mesh->num_vertices()));
        printf("Reducing 3D mesh %s: %d vertices and %d faces. ===> %d vertices.\n", this->path.c_str(),
                this->mesh->num_vertices(), this->mesh->num_faces(), num_points);
    }
    if (!CGAL::is_triangle_mesh(*(this->mesh))){
        std::cerr << "Input geometry is not triangulated." << std::endl;
        return;
    }

    SMS::Count_ratio_stop_predicate<Surface_mesh> stop(0.25);
//    SMS::Count_stop_predicate<Surface_mesh> stop();
    int r = SMS::edge_collapse(*(this->mesh), stop);
    std::cout << "\nFinished...\n" << r << " edges removed.\n"
              << this->mesh->number_of_edges() << " final edges.\n";
    std::cout << this->mesh->number_of_vertices() << " final vertices.\n";

}

void MeshSimplify::save(string& out_path) {
    ofstream os(out_path);
    os << *(this->mesh);
}