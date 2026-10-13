#include "TextureMgr.h"

#include <fstream>
#include <iterator>
#include <ranges>
#include <vector>

#include "Globals.h"
#include "Logger.h"
#include "ImGui/imgui.h"
#include <Imgui/imgui-SFML.h>



static int ReadInt(const rapidxml::xml_node<>* node, const char* name, int defaultValue = 0)
{
    const auto* child = node->first_node(name);
    return child ? std::atoi(child->value()) : defaultValue;
}

static float ReadFloat(const rapidxml::xml_node<>* node, const char* name, float defaultValue = 0.f)
{
    const auto* child = node->first_node(name);
    return child ? static_cast<float>(std::atof(child->value())) : defaultValue;
}


void TextureMgr::Init()
{
    m_DefaultTextureData = TextureData();
    LoadTexture("../Ressources/Antonio_Belpaese.png");
    LoadTexture("../Ressources/enemy_texture_1.png");
    LoadTexture("../Ressources/enemy_texture_2.png");
    LoadTexture("../Ressources/enemy_texture_3.png");
    LoadTexture("../Ressources/enemy_texture_4.png");
    LoadTexture("../Ressources/enemy_texture_5.png");   
    LoadTexture("../Ressources/IsaacSprite.png");
    LoadTexture("../Ressources/sample4k.png");
    
    gData.DebugMgr->RegisterDebugableWindow("textures manager", this);

}

void TextureMgr::Shut()
{
    gData.DebugMgr->UnregisterDebugableWindow("textures manager");

}

bool TextureMgr::LoadTexture(const std::filesystem::path& path)
{
    const std::string name = path.stem().string();

    TextureData& data = m_Textures[name];
    data.AnimationsData.clear();

    if (!data.Texture.loadFromFile(path.string()))
    {
        Logger::Error("the path points no available texture");
        m_Textures.erase(name);
        return false;
    }

    std::filesystem::path xmlPath = path;
    xmlPath.replace_extension(".xml");

    std::ifstream file(xmlPath);
    if (!file.is_open())
    {
        Logger::Error("the path points no available .xml file");

        m_Textures.erase(name);
        return false;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');

    try
    {
        rapidxml::xml_document<> doc;
        doc.parse<0>(buffer.data());

        const rapidxml::xml_node<>* animationsNode = doc.first_node("Animations");
        if (!animationsNode)
        {
            m_Textures.erase(name);
            return false;
        }

        for (const rapidxml::xml_node<>* node = animationsNode->first_node("Animation");
             node != nullptr;
             node = node->next_sibling("Animation"))
        {
            const rapidxml::xml_attribute<>* nameAttr = node->first_attribute("Name");
            if (!nameAttr)
                continue;

            AnimationData anim;
            anim.StartX                = ReadInt(node, "X");
            anim.StartY                = ReadInt(node, "Y");
            anim.SizeX                 = ReadInt(node, "SizeX");
            anim.SizeY                 = ReadInt(node, "SizeY");
            anim.OffsetX               = ReadInt(node, "OffsetX");
            anim.OffsetY               = ReadInt(node, "OffsetY");
            anim.AnimationSpriteCount  = ReadInt(node, "SpriteNum");
            anim.SpriteOnLine          = ReadInt(node, "SpritesOnLine");
            anim.IsReverted            = ReadInt(node, "Reverted") != 0;
            anim.TimeBetweenAnimationInS = ReadFloat(node, "TimeBetweenAnimation");

            data.AnimationsData[nameAttr->value()] = anim;
        }
    }
    catch (const rapidxml::parse_error&)
    {
        Logger::Error("probleme happend while parsing xml");

        m_Textures.erase(name);
        return false;
    }

    return true;
}

const TextureData& TextureMgr::GetTextureData(const std::string& name) const
{
    const std::unordered_map<std::string, TextureData>::const_iterator data = m_Textures.find(name);
    return data != m_Textures.end() ? data->second : m_DefaultTextureData;
}

void TextureMgr::DrawDebug()
{
    if (ImGui::BeginTable("jsp", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_NoSavedSettings | ImGuiTableFlags_Borders))
    {
        ImGui::TableSetupColumn("img name");
        ImGui::TableSetupColumn("img");
        ImGui::TableHeadersRow();
        ImGui::TableNextRow();

        for (const auto& data : m_Textures)
        {
            ImGui::TableSetColumnIndex(0);
            ImGui::Text(data.first.c_str());
            ImGui::TableSetColumnIndex(1);
            ImGui::Image(data.second.Texture);
            ImGui::TableNextRow();
        }
    }
    ImGui::EndTable();

}
