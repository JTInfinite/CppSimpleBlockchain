#pragma once
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

/*
BlockData makes up one part of the actual transaction block. It contains keys information
like the sender and recipient details as well as the transaction amount and the
data that will be serialised prior to sending (and deserialised on receipt).

What is not included are things like the hash, previous hash, timestampe etc.

TODO I need to use non intrusive serialisation to have two different types of serialisation - i.e. one to serialise the member and one to serialise the whole class 
*/
class BlockData
{
public:
	BlockData(std::string from, std::string to, std::string msg, float amount)
		: m_From(from), m_To(to), m_Message(msg), m_Amount(amount)
	{
		m_DataString.append(m_From + m_To + m_Message + std::to_string(m_Amount));
	}

	inline std::string GetSender() { return m_From; }
	inline std::string GetRecipient() { return m_To; }
	inline std::string GetMessage() { return m_Message; }
	inline std::string GetDataString() { return m_DataString; }
	inline float GetAmount() { return m_Amount; }
	inline void SetSerialisedData(std::string sd) { m_SerialisedData = sd; }

private:
	std::string m_From;
	std::string m_To;
	std::string m_Message;
	std::string m_DataString;
	std::string m_SerialisedData;
	float m_Amount = 0.0f;

private:
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& m_From;
		ar& m_To;
		ar& m_Message;
		ar& m_Amount;
	}

};