#pragma once
#include <vector>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>

class Block;

class BlockChain
{

public:
	BlockChain(int dif) {
		m_Difficulty = dif;
		CreateGenesisBlock(); 
	}

	Block* GetLatestBlock();
	Block* GetBlockByIndex(int index);
	
	inline float GetFunds() { return m_Funds; };
	inline int GetDifficulty() { return m_Difficulty; }
	inline size_t GetChainLength() { return m_Chain.size(); }
	//bool bIsChainValid();

	void AddNewBlock(Block& nb);


private:
	void CreateGenesisBlock();


private:
	std::vector<Block> m_Chain;
	float m_Funds;
	int m_Difficulty = 2;


};

