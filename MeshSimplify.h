//
// Created by yunhaoli on 19-7-5.
//

#ifndef MESH2SIMPLEPCD_MESHSIMPLIFY_H
#define MESH2SIMPLEPCD_MESHSIMPLIFY_H

#include <iostream>
#include <string>

using namespace std;

class MeshSimplify {
public:
    string path;
    bool visible;
    MeshSimplify(string path, bool visible = false);

};


#endif //MESH2SIMPLEPCD_MESHSIMPLIFY_H
