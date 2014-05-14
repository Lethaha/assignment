/*
 * Crypt_traits.h
 *
 * Header file to define traits for cryptography types
 * Name:Lethaha Thamae
 * Student No.: thmteb001
 * Date: 13 May 2014
 */

#ifndef CRYPT_TRAITS_H_
#define CRYPT_TRAITS_H_

#include <string>

#include "Types.h"

namespace thmteb001 {

/*
 * General Definition of CryptTraits class
 * Parameterised by
 * 	*Cipher (Vignere, XOR)
 * 	*P (Pack, Empty)
 * 	*G (Group, Empty)
 */

template <typename Cipher, typename P, typename G>
class CryptTrait
{
public:
	
	//Method to return a description of the encoder chosen
	static std::string start(void) { return "<<Not defined.>>\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n<<Not defined.>>\n"; }

	//End of decoding method
	static std::string endD(void) { return "\n<<Not defined.>>\n"; }

};


/************************************************** Vignere Cipher **************************************************/

/*
 * Full specialisation of CryptTrait class for Vignere Cipher, no Pack, no Group
 */
template <> class CryptTrait<Vignere, Empty, Empty>
{
public:
	
	//Method to return a description of the encoder chosen
	static std::string start(void) { return "Vignere Cipher\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****Vignere Cipher Encoding completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) { return "\n*****Vignere Cipher Decoding completed. Check the output.*****\n\n"; }	
	
};

/*
 * Full specialisation of CryptTrait class for Vignere Cipher, Pack enabled, no Group
 */
template <> class CryptTrait<Vignere, Pack, Empty>
{
public:
	
	//Method to return a description of the encoder chosen
	static std::string start(void) { return "Vignere Cipher with Pack option.\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****Vignere Cipher with Pack option Encoding completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) { return "\n*****Vignere Cipher with Pack option Decoding completed. Check the output.*****\n\n"; }	
	
};

/*
 * Full specialisation of CryptTrait class for Vignere Cipher, no Pack, Group enabled
 */
template <> class CryptTrait<Vignere, Empty, Group>
{
public:
	//Method to return a description of the encoder chosen
	static std::string start(void) { return "Vignere Cipher with Group option.\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****Vignere Cipher with Group option Encoding completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) { return "\n<<Not defined.>>\n\n"; }	
	
};

/*
 * Full specialisation of CryptTrait class for Vignere Cipher, Pack enabled, Group enabled
 */
template <> class CryptTrait<Vignere, Pack, Group>
{
public:
	
	//Method to return a description of the encoder chosen
	static std::string start(void) { return "Vignere Cipher with Pack and Group options.\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****Vignere Cipher with Pack and Group options Encoding completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) { return "\n<<Not defined.>>\n\n"; }
	
	
};



/************************************************** XOR  Cipher **************************************************/

/*
 * Full specialisation of CryptTrait class for XOR Cipher, no Pack, no Group
 */
template <> class CryptTrait<XOR, Empty, Empty>
{
public:
	
	//Method to return a description of the encoder chosen
	static std::string start(void) { return "XOR Cipher\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****XOR Cipher Encoding completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) {  return "\n*****XOR Cipher Decoding completed. Check the output.*****\n\n"; }
	
	
};

/*
 * Full specialisation of CryptTrait class for XOR Cipher, Pack enabled, no Group
 */
template <> class CryptTrait<XOR, Pack, Empty>
{
public:
	
	//Method to return a description of the encoder chosen
	static std::string start(void) { return "XOR Cipher with Pack option.\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****XOR Cipher with Pack option Encoding completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) { return  "\n*****XOR Cipher with Pack option Decoding completed. Check the output.*****\n\n"; }
	
};

/*
 * Full specialisation of CryptTrait class for XOR Cipher, no Pack, Group enabled
 */
template <> class CryptTrait<XOR, Empty, Group>
{
public:
	
	//Method to return a description of the encoder chosen
	static std::string start(void) { return "XOR Cipher with Group option.\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****XOR Cipher with Group option Encoding completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) { return "\n<<Not defined.>>\n\n"; }
	
	
};

/*
 * Full specialisation of CryptTrait class for XOR Cipher, Pack enabled, Group enabled
 */
template <> class CryptTrait<XOR, Pack, Group>
{
public:

	//Method to return a description of the encoder chosen
	static std::string start(void) { return "XOR Cipher with Pack and Group options.\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****XOR Cipher with Pack and Group options Encoding completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) { return "\n<<Not defined.>>\n\n"; }
	
	
};

/*
 * Full specialisation of CryptTrait class for No Cipher, Pack enabled, No Group 
 */
template <> class CryptTrait<Empty, Pack, Empty>
{
public:

	//Method to return a description of the encoder chosen
	static std::string start(void) { return "Packing.\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****Packing completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) { return "\n*****Unpacking completed. Check the output.*****\n\n"; }
	
	
};

/*
 * Full specialisation of CryptTrait class for No Cipher, No Pack , Group enabled
 */
template <> class CryptTrait<Empty, Empty, Group>
{
public:

	//Method to return a description of the encoder chosen
	static std::string start(void) { return "Grouping.\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****Grouping completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) { return "\n<<Not defined.>>\n\n"; }
	
	
};

/*
 * Full specialisation of CryptTrait class for No Cipher, Pack Enabled, Group enabled
 */
template <> class CryptTrait<Empty, Pack, Group>
{
public:

	//Method to return a description of the encoder chosen
	static std::string start(void) { return "Packing and Grouping.\n\n"; }

	//End of encoding method
	static std::string endE(void) { return "\n*****Packing and Grouping completed. Check the output.*****\n\n"; }

	//End of decoding method
	static std::string endD(void) { return "\n<<Not defined.>>\n\n"; }
	
	
};

} /* namespace thmteb001 */

#endif /* CRYPT_TRAITS_H_ */
