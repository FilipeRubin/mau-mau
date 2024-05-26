#include "opengl-mesh-renderer.h"
#include <cassert>

OpenGLMeshRenderer::OpenGLMeshRenderer()
{
    OpenGLShader vertexShader = OpenGLShader(OpenGLShaderType::VERTEX_SHADER);
    OpenGLShader fragmentShader = OpenGLShader(OpenGLShaderType::FRAGMENT_SHADER);

    const char* vertSource = R"(
)";
    
    const char* fragSource = R"(
)";

    vertexShader.SetSource(vertSource);
    fragmentShader.SetSource(fragSource);

    if (not vertexShader.TryCompile() or not fragmentShader.TryCompile())
    {
        assert(false);
    }

    m_program.AttachShader(vertexShader);
    m_program.AttachShader(fragmentShader);

    m_program.Link();
}

std::shared_ptr<IMesh> OpenGLMeshRenderer::CreateMesh()
{
    return m_meshes.emplace_back(std::make_shared<OpenGLMesh>());
}

void OpenGLMeshRenderer::DrawAllMeshes() const
{
    m_program.Use();

    for (const std::shared_ptr<OpenGLMesh>& mesh : m_meshes)
    {
        mesh->Draw();
    }
}
