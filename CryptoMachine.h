/*
 * crypt.h
 * Name: Lethaha Thamae	
 * Student No.: thmteb001
 * Date: 13 May 2014
 */


#ifndef CRYPT_H_
#define CRYPT_H_

#include <string>
#include <iostream>

#include "Crypt_policy.h"
#include "Crypt_traits.h"

namespace thmteb001 {

/*
 * General Definition of Crypt class
 * Parameterised by
 * 	*Cipher ( Vignere, XOR)
 * 	*P (Pack, Empty)
 * 	*G (Group, Empty)
 */
template <typename Cipher, typename P, typename G, typename Trait = CryptTrait<Cipher, P, G>, typename Policy = CryptPolicy<Cipher, P, G> >
class CryptoMachine
{
public:

	typedef Trait Tr;
	typedef Policy Pol;

	/*
	 * Method to show the current operation
	 */
	std::string show(void) const
	{ return Tr::start(); }

	/*
	 * Method for encoding
	 * @param in the source of data to be encoded
	 * @param out the output to send the encoded data to
	 * @param key_ the key to encode with
	 */
	void encode(std::istream &in, std::ostream &out, std::string key_)
	{
		std::cout << std::endl;
		std::cout << "Encoding: " + show();
		Pol::encode(in,out,key_);
		
		std::cout << Tr::endE();
	}
	
	/*
	 * Method for decoding
	 * @param in the source of data to be decoded
	 * @param out the output to send the decoded data to
	 * @param key_ the key to decode with
	 */
	void decode(std::istream &in, std::ostream &out, std::string key_)
	{
		std::cout << std::endl;
		std::cout << "Decoding: " + show();
		Pol::decode(in,out,key_);
		
		std::cout << Tr::endD();
	}


};

} /* namespace thmteb001 */


#endif /* CRYPT_H_ */
