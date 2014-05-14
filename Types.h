/*
 * Types.h
 * Class to create Types used by the crypt class
 * Name:Lethaha Thamae
 * Student No.: THMTEB001
 * Date: 06 May 2013
 */


#ifndef TYPES_H_
#define TYPES_H_

#include <string>
#include <cstdint>
#include <bitset>
#include <vector>

namespace thmteb001 {
	

// Vignere Cipher definition
class Vignere {
private:
	bool dir;                                 //direction -- encoding 1, decoding 0
public:
	std::string key;	
	
	/*
	 * Vignere constructor for encoding or decoding
	 * @param dir_ indicates encoding or decoding
	 * @param key_ the key to encode with
	*/ 
	Vignere(bool dir_, std::string key_) : dir(dir_), key(key_){}
	
	 /*
	   * operator() overload to encode or decode
	   * @value the value to encode or decode
	 */
	char operator()(const char &value)
	{
		static int currentPos = 0;                    //the currentPosition in the string
		char c = value;
		if(isalpha(c))
		{
			c = toupper(c);                           //convert to uppercase
			
			if(dir)    //encoding
			{
				//find the int values of the message and the key and return the cipherkey                                               
				int cVal = c - 65;
				int kVal = key.at(currentPos) - 65;
				int cipherVal = (cVal+kVal) % 26;
				c = (char)(cipherVal+65);
			}
			else       //decoding
			{
				//find the int values of the ciphertext and the key and return the messagekey                                               
				int cVal = c - 65;
				int kVal = key.at(currentPos) - 65;
				int messageVal = (cVal-kVal) % 26;
				if(messageVal < 0)
					messageVal+=26;
				messageVal = messageVal%26;
				c = (char)(messageVal+65);
				
			}
			currentPos++;
			if(currentPos == key.length())
				currentPos = 0;
		}

		return c;
	}

};
/*
 * XOR Cipher definition
 */
class XOR {};
/*
 * Class to define grouping
 */
class Group {
		
private:
	int size;
public:
	/*
	 * Grouping constructor
	 */
	Group(): size(5) {}
	
	std::vector<char> operator()(const std::vector<char> &old)
	{
		std::vector<char> newC;
		
		//group into newC
		int count = 0;
		int pos;
		for(pos = 0; pos < old.size(); pos++)
		{
			if(count == 5)
			{
				count = 0;
				newC.push_back(' ');
			}
			if(old[pos] != ' ')
			{	newC.push_back(old[pos]);
				count++;
			}
		}
		
		
		return std::move(newC);
		
	}
	
	
	
};

/*
 * Class to pack and unpack characters
 */
class Pack{

public:
	/*
	 * Pack no arg constructor
	 */
	Pack() {}
	 
	/*
	 * Method to pack characters into 5 bit characters
	 * @param old the old array with 8 bit characters
	 */
	static std::vector<char> pack(const std::vector<char> &old)
	{
		std::vector<char> newC;
		  
		//change and save chars as 5 bits	
		  
		typedef std::bitset<5> reducedC;
		typedef std::bitset<8> octet;
		std::vector<reducedC> newChars;                             //store 5 last bits of each char
		 
		reducedC aChar;
		octet temp; 
		int pos;
		int c;
		  
		for(c = 0; c < old.size(); c++)
		{
			aChar = (long)(0);
			temp = (long)(old[c] -65);
		
			for(pos = 0; pos < 5; pos++)
				aChar[pos] = temp[pos];
		
			newChars.push_back(aChar);
		}
		
		//write 8 bit characters to array 
	
		int val = 0;
		temp = (long)(0);
	
		std::vector<reducedC>::iterator i = newChars.begin();
		while(i != newChars.end())
		{	
			for(pos = 0; pos < 5; pos++, val++)
			{
				if(val== 8)
				{
					newC.push_back((char)temp.to_ulong());
					temp = (long)(0);
					val = 0;
				}
				temp[val] = (*i)[pos];
			}
			i++;
		}
		if(val != 0)
			newC.push_back((char)temp.to_ulong());
	
		  
		return std::move(newC);
		  
	}
	/*
	 * Method to unpack characters into 8 bit characters
	 * @param old the old array with 5 bit characters
	 */
	static std::vector<char> unpack(const std::vector<char> &old)
	{
		
		
		typedef std::bitset<8> octet;
		octet temp;
		
		std::vector<char> newC;
	
		char recovered;
		octet decoded = (long)(0);
		int numberOfChars = (old.size() * 8)/5 - 1;
		int oldChar = 0;
		temp = (long)(old[oldChar]);
		
		int charNo;
		int val = 0;
		int pos;
		
		for(charNo = 0; charNo < numberOfChars; charNo++)
		{
			for(pos = 0; pos < 5; pos++)
			{
				if(val == 8)
				{
					val = 0;
					oldChar++;
					temp = (long)(old[oldChar]);
				}
				decoded[pos] = temp[val];
				val++;
			} 
		
			recovered = (char)decoded.to_ulong();
			if((recovered+65) == 96) recovered = (char)223;
			newC.push_back(recovered+65);
			decoded = (long)(0);
		
		}
		
		return std::move(newC);

	}

	
};

class Empty{};

} /* namespace thmteb001 */
#endif /* TYPES_H_ */
