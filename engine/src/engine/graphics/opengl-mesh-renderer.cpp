#include "opengl-mesh-renderer.h"

std::shared_ptr<IMesh> OpenGLMeshRenderer::CreateMesh()
{
    return m_meshes.emplace_back(std::make_shared<OpenGLMesh>());
}
