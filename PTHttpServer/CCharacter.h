#pragma once


class CCharacter
{
public:
	CCharacter() {};
	~CCharacter() {};

	std::string GetCharacterInfoAsJsonString(const std::string&);
	std::vector<sRECORD_ITEM> GetRecordItems(const std::shared_ptr<TRANS_RECORD_DATA>&);

};
