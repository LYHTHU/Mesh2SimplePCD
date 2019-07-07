#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <cstring>
#include "Mesh2PCD.h"
#include "MeshSimplify.h"

using namespace std;


int main(int argc, char** argv) {
    int result;

    opterr = 0;
    string path = "Data/tube.off";
    bool visible = false;

    while( (result = getopt(argc, argv, "f:v")) != -1 ) {
        switch (result) {
            case 'f':
                path = optarg;
                break;
            case 'v':
                visible = true;
                break;
            case '?':
                break;
            default:
                path = "Data/tube.off";
                break;
        }
    }

    MeshSimplify *simplify = new MeshSimplify(path, visible);
    simplify->simplify(15, 40);
    string out_path = "./Data/tube_sim.off";
    simplify->save(out_path);
    return 0;
}