#include <iostream>

#include "BlockChain.h"
#include "Block.h"
#include "BlockData.h"


void main()
{
	BlockChain bc(3);
	std::cout << "Block " << bc.GetLatestBlock()->GetIndex() << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Transaction from: " <<  bc.GetLatestBlock()->GetBlockData().GetSender() << std::endl;
	std::cout << "Transaction to: " << bc.GetLatestBlock()->GetBlockData().GetRecipient() << std::endl;
	std::cout << "Transaction message: " << bc.GetLatestBlock()->GetBlockData().GetMessage() << std::endl;
	std::cout << "Transaction amount: " << bc.GetLatestBlock()->GetBlockData().GetAmount() << std::endl;
	std::cout << "Transaction timestamp: " << bc.GetLatestBlock()->GetTimestamp() << std::endl;
	std::cout << "Transaction hash: " << bc.GetLatestBlock()->GetHash() << std::endl;
	std::cout << "Previous hash: " << bc.GetLatestBlock()->GetPreviousHash() << std::endl;
	std::cout << std::endl;

	std::cout << "Account Funds: " << bc.GetFunds() << std::endl;
	std::cout << std::endl;

	//Mimic Receiving transaction
	BlockData nbd("Muad'Dib", "Duncan Idaho", "Fear is the mind killer", 15.0f);

	std::ostringstream archive_stream;
	boost::archive::text_oarchive archive(archive_stream);
	archive << nbd.GetDataString();

	nbd.SetSerialisedData(archive_stream.str());

	// Create a block and add to chain
	Block nb(bc.GetLatestBlock()->GetIndex() + 1, std::time(nullptr), nbd, bc.GetLatestBlock()->GetHash());
	bc.AddNewBlock(nb);

	std::cout << std::endl;

	std::cout << "Block " << bc.GetLatestBlock()->GetIndex() << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Transaction from: " << bc.GetLatestBlock()->GetBlockData().GetSender() << std::endl;
	std::cout << "Transaction to: " << bc.GetLatestBlock()->GetBlockData().GetRecipient() << std::endl;
	std::cout << "Transaction message: " << bc.GetLatestBlock()->GetBlockData().GetMessage() << std::endl;
	std::cout << "Transaction amount: " << bc.GetLatestBlock()->GetBlockData().GetAmount() << std::endl;
	std::cout << "Transaction timestamp: " << bc.GetLatestBlock()->GetTimestamp() << std::endl;
	std::cout << "Transaction hash: " << bc.GetLatestBlock()->GetHash() << std::endl;
	std::cout << "Previous hash: " << bc.GetLatestBlock()->GetPreviousHash() << std::endl;
	std::cout << "Nonce: " << bc.GetLatestBlock()->GetNonce() << std::endl;
	std::cout << std::endl;

	std::cout << "Account Funds: " << bc.GetFunds() << std::endl;
	std::cout << std::endl;


}