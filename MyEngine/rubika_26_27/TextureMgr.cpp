#include "TextureMgr.h"

bool TextureMgr::LoadTexture(const std::filesystem::path& path)
{
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node;
    
    
    std::ifstream theFile (path);
    std::pmr::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    root_node = doc.first_node();
    
    
    
}

const TextureData& TextureMgr::GetTextureData(const std::string& name) const
{
}
