#pragma once
#include <ctime>
#include <ostream>
#include <sstream>
#include <string>
#include "sha256.h"
#include "BlockData.h"
#include <boost/serialization/string.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


class Block
{
public:
	Block(unsigned int idx, std::time_t timestamp, BlockData data, std::string previousHash)
		: m_Index(idx), m_TimeStamp(timestamp), m_Data(data), m_PreviousHash(previousHash) 
	{
		m_Hash = calculateHash();
	}


public:
	std::string calculateHash();
	void mineBlock(const int difficulty);

	inline unsigned int GetIndex() { return m_Index; }
	inline std::time_t GetTimestamp() { return m_TimeStamp; }
	inline std::string GetPreviousHash() { return m_PreviousHash; }
	inline std::string GetHash() { return m_Hash; }
	inline BlockData GetBlockData() { return m_Data; }
	inline int GetNonce() { return m_Nonce; }
	inline int GetConfirmations() { return m_Confirmations; }
	inline std::string GetVersion() { return m_Version; }


private:
	unsigned int m_Index;
	std::string m_Version = "0.0.1";
	std::time_t m_TimeStamp; // std::asctime(std::localtime(&result))  = e.g. Wed Sep 21 10:27:52 2011
	std::string m_PreviousHash;
	std::string m_Hash = "";
	int m_Nonce = 0;
	int m_Confirmations = 0;
	BlockData m_Data;



};


