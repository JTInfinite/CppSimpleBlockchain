#include "Block.h"
#include "SHA256.h"
#include <algorithm>
#include <iterator>
#include <boost/archive/text_oarchive.hpp>
#include <string>
#include <iostream>

std::string Block::calculateHash()
{
	std::string input;
	input.append(std::to_string(m_Index) + m_PreviousHash + std::to_string(m_TimeStamp) + m_Data.GetMessage() + std::to_string(m_Nonce));
	SHA256 sha;
	sha.update(input);
	uint8_t* digest = sha.digest();

	return SHA256::toString(digest);

}

void Block::mineBlock(const int difficulty)
{
	std::string requirement = "000";
	std::cout << "Mining Block | Requirements " << requirement << std::endl;
	while (m_Hash.substr(0, 3) != requirement)
	{
		m_Hash = calculateHash();
		m_Nonce++;
	}
	
	std::cout << "Block mined | Hash " << m_Hash << std::endl;
}
