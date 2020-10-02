#include <ctime>
#include <iostream>
#include "BlockChain.h"
#include "Block.h"
#include "BlockData.h"



void BlockChain::CreateGenesisBlock()
{
	BlockData bd("Muad'Dib", "Leto Atreides", "Father!", 0.0f);

	std::ostringstream archive_stream;
	boost::archive::text_oarchive archive(archive_stream);
	archive << bd.GetDataString();

	bd.SetSerialisedData(archive_stream.str());

	Block b(0, std::time(nullptr), bd, "0");
	m_Chain.emplace_back(b);
	m_Funds = 0.0f;
}


Block* BlockChain::GetLatestBlock()
{
	return &m_Chain.back();
}

Block* BlockChain::GetBlockByIndex(int idx)
{
	return &m_Chain[idx];
}

void BlockChain::AddNewBlock(Block& nb)
{
	nb.mineBlock(m_Difficulty);
	m_Chain.emplace_back(nb);
	m_Funds += nb.GetBlockData().GetAmount();
}


/*
bool BlockChain::bIsChainValid()
{
	for (size_t i = 1; i < m_Chain.size(); i++)
	{
		if (m_Chain[i].calculateHash() != m_Chain[i].m_Hash)
		{
			return false;
		}

		if (m_Chain[i].m_PreviousHash != m_Chain[i - 1].m_Hash)
		{
			return false;
		}

		return true;
	}
}*/

