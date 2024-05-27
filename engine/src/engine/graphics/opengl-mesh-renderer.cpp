#include "opengl-mesh-renderer.h"
#include <cassert>

OpenGLMeshRenderer::OpenGLMeshRenderer()
{
    OpenGLShader vertexShader = OpenGLShader(OpenGLShaderType::VERTEX_SHADER);
    OpenGLShader fragmentShader = OpenGLShader(OpenGLShaderType::FRAGMENT_SHADER);

    const char* vertSource = R"(
#version 330 core

layout(location=0) in vec3 v_in_pos;
layout(location=1) in vec2 v_in_tex;
layout(location=2) in vec3 v_in_nor;

uniform mat4 u_projection;
uniform mat4 u_model;

void main()
{
    gl_Position = u_projection * u_model * vec4(v_in_pos, 1.0);
}
)";
    
    const char* fragSource = R"(
#version 330 core

out vec4 f_fragColor;

void main()
{
    f_fragColor = vec4(1.0);
}
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
