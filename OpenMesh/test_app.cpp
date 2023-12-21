#include <iostream>
#include <vector>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
//

using MeshType = OpenMesh::PolyMesh_ArrayKernelT<>;
using MeshPointType = MeshPointType;
using MeshVertexHandleType = MeshType::VertexHandle;
using MeshVertexHandlevectorType = std::vector<MeshType::VertexHandle>;

class MeshObject
{
private:
    MeshType mesh;
    std::vector<MeshVertexHandleType> face_vhandles;
    MeshVertexHandleType vhandle[8];

public:
    MeshObject() {}

    void initVertices()
    {
        vhandle[0] = mesh.add_vertex(MeshPointType(-1, -1, 1));
        vhandle[1] = mesh.add_vertex(MeshPointType(1, -1, 1));
        vhandle[2] = mesh.add_vertex(MeshPointType(1, 1, 1));
        vhandle[3] = mesh.add_vertex(MeshPointType(-1, 1, 1));
        vhandle[4] = mesh.add_vertex(MeshPointType(-1, -1, -1));
        vhandle[5] = mesh.add_vertex(MeshPointType(1, -1, -1));
        vhandle[6] = mesh.add_vertex(MeshPointType(1, 1, -1));
        vhandle[7] = mesh.add_vertex(MeshPointType(-1, 1, -1));
    }
    void clearVertexHandles()
    {
        my_mesh.clearVertexHandles();
    }

    void addVertexhandle(const auto vhandle)
    {
        my_mesh.addVertexhandle(vhandle);
    }

    void addFace(const auto face_vhandles)
    {
        my_mesh.addFace(face_vhandles);
    }

    MeshType::VertexHandle *getVertexHandles() const
    {
        return vhandle;
    }

    MeshType getMesh() const
    {
        return mesh;
    }

    MeshVertexHandlevectorType getFaceVertexHandles() const
    {
        return face_vhandles;
    }
};

int main()
{
    MeshObject my_mesh;

    // generate vertices
    my_mesh.initVertices();

    auto vhandle = my_mesh.getVertexHandles();
    auto face_vhandles = my_mesh.getFaceVertexHandles();

    // generate (quadrilateral) faces
    // std::vector<MeshType::VertexHandle> face_vhandles;
    my_mesh.clearVertexHandles();

    // my_mesh.clearVertexHandles();
    my_mesh.addVertexhandle(vhandle[0]);
    my_mesh.addVertexhandle(vhandle[1]);
    my_mesh.addVertexhandle(vhandle[2]);
    my_mesh.addVertexhandle(vhandle[3]);
    my_mesh.addFace(face_vhandles);

    my_mesh.clearVertexHandles();
    my_mesh.addVertexhandle(vhandle[7]);
    my_mesh.addVertexhandle(vhandle[6]);
    my_mesh.addVertexhandle(vhandle[5]);
    my_mesh.addVertexhandle(vhandle[4]);
    my_mesh.addFace(face_vhandles);

    my_mesh.clearVertexHandles();
    my_mesh.addVertexhandle(vhandle[1]);
    my_mesh.addVertexhandle(vhandle[0]);
    my_mesh.addVertexhandle(vhandle[4]);
    my_mesh.addVertexhandle(vhandle[5]);
    my_mesh.addFace(face_vhandles);

    my_mesh.clearVertexHandles();
    my_mesh.addVertexhandle(vhandle[2]);
    my_mesh.addVertexhandle(vhandle[1]);
    my_mesh.addVertexhandle(vhandle[5]);
    my_mesh.addVertexhandle(vhandle[6]);
    my_mesh.addFace(face_vhandles);

    my_mesh.clearVertexHandles();
    my_mesh.addVertexhandle(vhandle[3]);
    my_mesh.addVertexhandle(vhandle[2]);
    my_mesh.addVertexhandle(vhandle[6]);
    my_mesh.addVertexhandle(vhandle[7]);
    my_mesh.addFace(face_vhandles);

    my_mesh.clearVertexHandles();
    my_mesh.addVertexhandle(vhandle[0]);
    my_mesh.addVertexhandle(vhandle[3]);
    my_mesh.addVertexhandle(vhandle[7]);
    my_mesh.addVertexhandle(vhandle[4]);
    my_mesh.addFace(face_vhandles);

    auto mesh = my_mesh.getMesh();
    // write mesh to output.obj
    try
    {
        if (!OpenMesh::IO::write_mesh(mesh, "output.off"))
        {
            std::cerr << "Cannot write mesh to file 'output.off'" << std::endl;
            return 1;
        }
    }
    catch (std::exception &x)
    {
        std::cerr << x.what() << std::endl;
        return 1;
    }
    return 0;
}
