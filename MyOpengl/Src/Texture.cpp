#pragma once
#include "Texture.h"

#include "DebugErrors.h"
#include "vendor/std_image.h"

Texture::Texture(const std::string& path): m_RendererId(0), path(path), localBuffer(nullptr), width(0), height(0),
                                           bytesPerPixel(0)
{
    localBuffer = stbi_load(path.c_str(),&width,&height,&bytesPerPixel,4);


    glCreateTextures(GL_TEXTURE_2D,1,&m_RendererId);
    glTextureParameteri(m_RendererId,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTextureParameteri(m_RendererId,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTextureParameteri(m_RendererId,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTextureParameteri(m_RendererId,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTextureStorage2D(m_RendererId,1,GL_RGBA,width,height);
    glTextureSubImage2D(m_RendererId,1,0,0,width,height,GL_RGBA,GL_UNSIGNED_BYTE,localBuffer);
    stbi_image_free(localBuffer);
}

Texture::~Texture()
{
    glDeleteTextures(1,&m_RendererId);
}
