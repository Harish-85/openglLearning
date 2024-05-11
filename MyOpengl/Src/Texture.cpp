#pragma once
#include "Texture.h"

#include "DebugErrors.h"
#include "stdImage/std_image.h"

Texture::Texture(const std::string& path): m_RendererId(0), path(path), localBuffer(nullptr), width(0), height(0),
                                           bytesPerPixel(0)
{
    stbi_set_flip_vertically_on_load(1);
    localBuffer = stbi_load(path.c_str(),&width,&height,&bytesPerPixel,4);

    std::cout<<"Image loaded \n Width :" << width <<" \n height :" << height << std::endl;

    glCreateTextures(GL_TEXTURE_2D,1,&m_RendererId);
    glTextureParameteri(m_RendererId,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTextureParameteri(m_RendererId,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTextureParameteri(m_RendererId,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTextureParameteri(m_RendererId,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTextureStorage2D(m_RendererId,1,GL_RGBA16,width,height);
    glTextureSubImage2D(m_RendererId,0,0,0,width,height,GL_RGBA,GL_UNSIGNED_BYTE,localBuffer);
    glGenerateTextureMipmap(m_RendererId);
	stbi_image_free(localBuffer);
}

Texture::~Texture()
{
    glDeleteTextures(1,&m_RendererId);
}

void Texture::Bind(unsigned int slot) const
{
    //GLCall(glActiveTexture(GL_TEXTURE0+slot));
    GLCall(glBindTextureUnit(slot,m_RendererId));
}
