/*
 * Crypt_policy.h
 * Header file to define policies for cryptography types
 * Name: Lethaha Thamae
 *Student No.: thmteb001
 * Date: 06 May 2013
 */

#ifndef CRYPT_POLICY_H_
#define CRYPT_POLICY_H_


#include <string>
#include <sstream>
#include <iostream>

#include "Types.h"

namespace thmteb001 {
/*
 * General Definition of CryptPolicy class
 * Parameterised by
 * 	*Cipher (Vignere, XOR)
 * 	*P (Pack, Empty)
 * 	*G (Group, Empty)
 */

template <typename Cipher, typename P, typename G>
class CryptPolicy
{
public:
	
	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key) { return false; }
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {  return false; }

};



/************************************************** Vignere Cipher **************************************************/

/*
 * Full specialization of CryptPolicy class for Vignere Cipher, no Pack, no Group
 */
template <> class CryptPolicy<Vignere, Empty, Empty>
{
public:
	
		/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
		
		/****************************** Encode the data **********************/
		std::string key = key_;
		std::vector<char> inArray;
		std::vector<char> outArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
	
		std::transform(inArray.begin(), inArray.end(), back_inserter(outArray), Vignere(1, key)); //encode using Vignere cipher
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
		
		return true; 
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		
		/****************************** Decode the data **********************/
		
		std::string key = key_;
		std::vector<char> inArray;
		std::vector<char> outArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
		
		
		std::transform(inArray.begin(), inArray.end(), back_inserter(outArray), Vignere(0, key)); //decode using Vignere cipher
		
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
		
		return true; 
	}
	
};

/*
 * Full specialization of CryptPolicy class for Vignere Cipher, Pack enabled, no Group
 */
template <> class CryptPolicy<Vignere, Pack, Empty>
{
public:
	
	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
		
		/****************************** Encode the data **********************/
		std::string key = key_;
		std::vector<char> inArray;
		std::vector<char> outArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
	
		std::transform(inArray.begin(), inArray.end(), back_inserter(outArray), Vignere(1, key)); //encode using Vignere cipher
		
		/****************************** Pack the data ***********************/
		outArray = Pack::pack(outArray);
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
		
		return true; 
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		
		std::string key = key_;
		std::vector<char> inArray;
		std::vector<char> outArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
	
		/****************************** Unpack the data ***********************/
		inArray = Pack::unpack(inArray);
		
		/****************************** Decode the data **********************/
		
		std::transform(inArray.begin(), inArray.end(), back_inserter(outArray), Vignere(0, key)); //decode using Vignere cipher
		
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
			
		return true;
	}
	
};

/*
 * Full specialization of CryptPolicy class for Vignere Cipher, no Pack, Group enabled
 */
template <> class CryptPolicy<Vignere, Empty, Group>
{
public:
	
	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
		
		/****************************** Encode the data **********************/
		std::string key = key_;
		std::vector<char> inArray;
		std::vector<char> outArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
	
		std::transform(inArray.begin(), inArray.end(), back_inserter(outArray), Vignere(1, key)); //encode using Vignere cipher
		
		/****************************** Group the data ***********************/
		Group g;
		outArray = g(outArray);
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
		
		return true;  
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		return true;
	}
	
};

/*
 * Full specialization of CryptPolicy class for Vignere Cipher, Pack enabled, Group enabled
 */
template <> class CryptPolicy<Vignere, Pack, Group>
{
public:

	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
		
		/****************************** Encode the data **********************/
		std::string key = key_;
		std::vector<char> inArray;
		std::vector<char> outArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
	
		std::transform(inArray.begin(), inArray.end(), back_inserter(outArray), Vignere(1, key)); //encode using Vignere cipher
		
		/****************************** Group the data ***********************/
		Group g;
		outArray = g(outArray);
		
		/****************************** Pack the data ***********************/
		outArray = Pack::pack(outArray);
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
		
		return true; 
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		return true;
	}
	
};


/************************************************** XOR  Cipher **************************************************/

/*
 * Full specialization of CryptPolicy class for XOR Cipher, no Pack, no Group
 */
template <> class CryptPolicy<XOR, Empty, Empty>
{
public:

	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
		
		/****************************** Encode the data **********************/
		int32_t key;
		std::stringstream(key_) >> key;
		std::vector<char> inArray;
		std::vector<char> outArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
		
		//convert to upper case
		std::transform(inArray.begin(), inArray.end(), inArray.begin(), [] (char c) { return toupper(c); } );
	
		transform(inArray.begin(), inArray.end(), back_inserter(outArray), [key] (char value) { return ((int32_t)value)^key;} );    //XOR each char using a lambda
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
		
		return true; 
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		
		/****************************** Decode the data **********************/
		int32_t key;
		std::stringstream(key_) >> key;
		std::vector<char> inArray;
		std::vector<char> outArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
	
		transform(inArray.begin(), inArray.end(), back_inserter(outArray), [key] (char value) { return ((int32_t)value)^key;} );    //XOR each char using a lambda
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
		
		return true;
	}
	
};

/*
 * Full specialization of CryptPolicy class for XOR Cipher, Pack enabled, no Group
 */
template <> class CryptPolicy<XOR, Pack, Empty>
{
public:

	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
		
		int32_t key;
		std::stringstream(key_) >> key;
		
		std::vector<char> inArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
		
		//convert to upper case
		std::transform(inArray.begin(), inArray.end(), inArray.begin(), [] (char c) { return toupper(c); } );
		
		/****************************** Pack the data ***********************/
		inArray = Pack::pack(inArray);
		
		/****************************** Encode the data **********************/
		std::vector<char> outArray;
		
	
		transform(inArray.begin(), inArray.end(), back_inserter(outArray), [key] (char value) { return ((int32_t)value)^key;} );    //XOR each char using a lambda
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
		
		return true; 
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		
		/****************************** Decode the data **********************/
		int32_t key;
		std::stringstream(key_) >> key;
		std::vector<char> inArray;
		std::vector<char> outArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
	
		transform(inArray.begin(), inArray.end(), back_inserter(outArray), [key] (char value) { return ((int32_t)value)^key;} );    //XOR each char using a lambda
		
		/****************************** Unpack the data ***********************/
		outArray = Pack::unpack(outArray);
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
			
		return true;
	}
	
};

/*
 * Full specialization of CryptPolicy class for XOR Cipher, no Pack, Group enabled
 */
template <> class CryptPolicy<XOR, Empty, Group>
{
public:

	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
		
		
		int32_t key;
		std::stringstream(key_) >> key;
		
		/****************************** Group the data ***********************/
		std::vector<char> inArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
		
		//convert to upper case
		std::transform(inArray.begin(), inArray.end(), inArray.begin(), [] (char c) { return toupper(c); } );
		
		Group g;
		inArray = g(inArray);
		
		/****************************** Encode the data **********************/
		std::vector<char> outArray;
		
	
		transform(inArray.begin(), inArray.end(), back_inserter(outArray), [key] (char value) { return ((int32_t)value)^key;} );    //XOR each char using a lambda
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
		
		return true; 
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		return true;
	}
	
};

/*
 * Full specialization of CryptPolicy class for XOR Cipher, Pack enabled, Group enabled
 */
template <> class CryptPolicy<XOR, Pack, Group>
{
public:
	
	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
		
		int32_t key;
		std::stringstream(key_) >> key;
		
		
		/****************************** Group the data ***********************/
		std::vector<char> inArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
		
		//convert to upper case
		std::transform(inArray.begin(), inArray.end(), inArray.begin(), [] (char c) { return toupper(c); } );
		
		Group g;
		inArray = g(inArray);
		
		/****************************** Pack the data ***********************/
		inArray = Pack::pack(inArray);
		
		/****************************** Encode the data **********************/
		std::vector<char> outArray;
		
	
		transform(inArray.begin(), inArray.end(), back_inserter(outArray), [key] (char value) { return ((int32_t)value)^key;} );    //XOR each char using a lambda
		
		//Save the result
		int i;
		for(i = 0; i < outArray.size(); i++)
			out<< outArray[i];
		return true; 
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		return true;
	}
	
};

/*
 * Full specialization of CryptPolicy class for No Cipher, Pack enabled, No Group
 */
template <> class CryptPolicy<Empty, Pack, Empty>
{
public:
	
	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
		
		std::vector<char> inArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
		
		//convert to upper case
		std::transform(inArray.begin(), inArray.end(), inArray.begin(), [] (char c) { return toupper(c); } );
		
		/****************************** Pack the data ***********************/
		inArray = Pack::pack(inArray);
		
		
		//Save the result
		int i;
		for(i = 0; i < inArray.size(); i++)
			out<< inArray[i];
		return true; 
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		
		std::vector<char> inArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
	
		/****************************** Unpack the data ***********************/
		inArray = Pack::unpack(inArray);
		
		
		//Save the result
		int i;
		for(i = 0; i < inArray.size(); i++)
			out<< inArray[i];
		
		return true;
	}
	
};

/*
 * Full specialization of CryptPolicy class for No Cipher, No Pack , Group enabled
 */
template <> class CryptPolicy<Empty, Empty, Group>
{
public:
	
	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
	
		/****************************** Group the data ***********************/
		std::vector<char> inArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
		
		//convert to upper case
		std::transform(inArray.begin(), inArray.end(), inArray.begin(), [] (char c) { return toupper(c); } );
		
		Group g;
		inArray = g(inArray);
		
		//Save the result
		int i;
		for(i = 0; i < inArray.size(); i++)
			out<< inArray[i];
		return true; 
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		return true;
	}
	
};


/*
 * Full specialization of CryptPolicy class for No Cipher, Pack enabled, Group enabled
 */
template <> class CryptPolicy<Empty, Pack, Group>
{
public:
	
	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	static bool encode(std::istream &in, std::ostream &out, std::string key_) {
		
		
		/****************************** Group the data ***********************/
		std::vector<char> inArray;
		std::copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), back_inserter(inArray)); //get the input
		
		//convert to upper case
		std::transform(inArray.begin(), inArray.end(), inArray.begin(), [] (char c) { return toupper(c); } );	
		
		Group g;
		inArray = g(inArray);
		
		/****************************** Pack the data ***********************/
		inArray = Pack::pack(inArray);
		
		//Save the result
		int i;
		for(i = 0; i < inArray.size(); i++)
			out<< inArray[i];
		return true; 
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	static bool decode(std::istream &in, std::ostream &out, std::string key_) {
		return true;
	}
	
};

}


#endif /* TYPE_TRAITS_H_ */
