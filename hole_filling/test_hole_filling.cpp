#include <iostream>
#include <pmp/SurfaceMesh.h>
#include <pmp/algorithms/SurfaceHoleFilling.h>

using namespace std;

int main()
{
    std::string obj_input_file{"map.obj"};
    std::string obj_output_file{"map_out.obj"};

    pmp::SurfaceMesh mesh;
    mesh.read(obj_input_file);

    pmp::SurfaceHoleFilling surfaceHoleFiller(mesh);

    // loop over all vertices
    for (auto h : mesh.halfedges())
    {
        if (h.is_valid())
            surfaceHoleFiller.fill_hole(h);
    }

    mesh.write(obj_output_file);

    return 0;
}
