#include "opengl-mesh-renderer.h"

std::shared_ptr<IMesh> OpenGLMeshRenderer::CreateMesh()
{
    return m_meshes.emplace_back(std::make_shared<OpenGLMesh>());
}

void OpenGLMeshRenderer::DrawAllMeshes() const
{
    for (const std::shared_ptr<OpenGLMesh>& mesh : m_meshes)
    {
        mesh->Draw();
    }
}
