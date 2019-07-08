#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <cstring>
#include "MeshSimplify.h"

using namespace std;


int main(int argc, char** argv) {
    int result;

    opterr = 0;
    string path = "Data/tube.off";
    string out_path = "./Data/tube_sim.off";
    bool visible = true;

    while( (result = getopt(argc, argv, "f:o:v")) != -1 ) {
        switch (result) {
            case 'f':
                path = optarg;
                break;
            case 'o':
                out_path = optarg;
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

    MeshSimplify *simplify = new MeshSimplify(path, out_path, visible = visible);
    simplify->simplify(15);

    simplify->save_mesh(out_path);
    return 0;
}