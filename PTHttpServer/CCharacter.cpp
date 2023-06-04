#include <StdAfx.h>
#include "CCharacter.h"
#include <Boost/property_tree/json_parser.hpp>

std::vector<sRECORD_ITEM> CCharacter::GetRecordItems(const std::shared_ptr<TRANS_RECORD_DATA>& data)
{
    std::vector<sRECORD_ITEM> vItems;
    BYTE* lpRecItem = reinterpret_cast<BYTE*>(&data->Data);

    for (auto cnt = 0; cnt < data->ItemCount; cnt++)
    {
        sRECORD_ITEM sRecordItem;
        DecodeCompress(lpRecItem, reinterpret_cast<BYTE*>(&sRecordItem));

        if (sRecordItem.sItemInfo.CODE)
            vItems.emplace_back(sRecordItem);

        lpRecItem += *reinterpret_cast<int*>(lpRecItem);
    }

    return vItems;
}

std::string CCharacter::GetCharacterInfoAsJsonString(const std::string& character)
{
    std::string filePath = character + ".dat";
    std::ifstream inputFile(filePath, std::ios::binary);

    if (!inputFile)
        return "Character not found!";

    std::shared_ptr<TRANS_RECORD_DATA> data = std::make_shared<TRANS_RECORD_DATA>();
    inputFile.read(reinterpret_cast<char*>(data.get()), sizeof(TRANS_RECORD_DATA));
    inputFile.close();

    boost::property_tree::ptree pt;
    const auto& charInfo = data->smCharInfo;
    pt.put("szName", charInfo.szName);
    pt.put("JOB_CODE", charInfo.JOB_CODE);
    pt.put("Level", charInfo.Level);
    pt.put("Strength", charInfo.Strength);
    pt.put("Spirit", charInfo.Spirit);
    pt.put("Talent", charInfo.Talent);
    pt.put("Dexterity", charInfo.Dexterity);
    pt.put("Health", charInfo.Health);
    pt.put("Accuracy", charInfo.Accuracy);
    pt.put("Attack_Rating", charInfo.Attack_Rating);
    pt.put("Attack_Damage[0]", charInfo.Attack_Damage[0]);
    pt.put("Attack_Damage[1]", charInfo.Attack_Damage[1]);
    pt.put("Attack_Speed", charInfo.Attack_Speed);
    pt.put("Shooting_Range", charInfo.Shooting_Range);
    pt.put("Critical_Hit", charInfo.Critical_Hit);
    pt.put("Defence", charInfo.Defence);
    pt.put("Chance_Block", charInfo.Chance_Block);
    pt.put("Absorption", charInfo.Absorption);
    pt.put("Move_Speed", charInfo.Move_Speed);

    boost::property_tree::ptree items;
    std::vector<sRECORD_ITEM> vItems = GetRecordItems(data);

    for (const auto& item : vItems)
    {
        boost::property_tree::ptree itemNode;
        itemNode.put("ItemName", item.sItemInfo.ItemName);
        items.push_back(std::make_pair("", itemNode));
    }

    pt.add_child("Items", items);

    std::stringstream ssOut;
    boost::property_tree::write_json(ssOut, pt);

    return ssOut.str();
}