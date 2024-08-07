#include "opengl-mesh-renderer.h"
#include <cassert>
#include <numbers>

OpenGLMeshRenderer::OpenGLMeshRenderer()
{
    CreateProgram();
}

std::shared_ptr<MeshBase> OpenGLMeshRenderer::CreateMesh()
{
    return m_meshes.emplace_back(std::make_shared<OpenGLMesh>());
}

void OpenGLMeshRenderer::DrawAllMeshes() const
{
    m_program.Use();

    const Matrix4x4 perspectiveMatrix = Matrix4x4::Perspective(static_cast<float>(std::numbers::pi) / 2.0f, 3.0f / 4.0f, 0.1f, 50.0f);
    m_program.UniformMatrix4x4("u_projection", perspectiveMatrix);

    for (const std::shared_ptr<OpenGLMesh>& mesh : m_meshes)
    {
        const Matrix4x4 modelMatrix = GenerateModelMatrix(mesh->transform);
        m_program.UniformMatrix4x4("u_model", modelMatrix);
        mesh->Draw();
    }
}

void OpenGLMeshRenderer::CreateProgram()
{
    OpenGLShader vertexShader = OpenGLShader(OpenGLShaderType::VERTEX_SHADER);
    OpenGLShader fragmentShader = OpenGLShader(OpenGLShaderType::FRAGMENT_SHADER);

    const char* vertSource = R"(
#version 330 core

layout(location=0) in vec3 v_in_pos;
layout(location=1) in vec2 v_in_tex;
layout(location=2) in vec3 v_in_nor;

out vec3 v_out_color;

uniform mat4 u_projection;
uniform mat4 u_model;

void main()
{
    vec4 vertexPos = u_projection * u_model * vec4(v_in_pos, 1.0);
    gl_Position = vertexPos;
    v_out_color = vec3(v_in_nor.r, v_in_nor.g, v_in_nor.b);
}
)";

    const char* fragSource = R"(
#version 330 core

out vec4 f_fragColor;

in vec3 v_out_color;

void main()
{
    f_fragColor = vec4(v_out_color, 1.0);
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

Matrix4x4 OpenGLMeshRenderer::GenerateModelMatrix(const Transform3D& transform) const
{
    const Matrix4x4 scaleMatrix = Matrix4x4::Scale(transform.scale);
    const Matrix4x4 rotationMatrix = Matrix4x4::Rotation(transform.rotation);
    const Matrix4x4 translationMatrix = Matrix4x4::Translation(transform.position);
    return translationMatrix * scaleMatrix * rotationMatrix;
}
