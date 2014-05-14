/*
 * Crypto.cpp
 * Driver class to perform encoding and decoding of strings
 * Name: Lethaha Thamae
 * Student No.: thmteb001
 * Date: 13 May 2013
 */

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <cstdint>

#include "CryptoMachine.h"
#include "cmdline_parser.h"
#include "Types.h"

using namespace std;
using namespace thmteb001;

int main(int argc, char * argv[])
{

	// Instantiate the parser
		cmdline_parser parser;

		// Try parse command line arguments
		if(!parser.process_cmdline(argc, argv))
		{
			// Complain to the standard error stream
			parser.print_errors(cerr);
			//Print help
			parser.print_help(cout);
			return 1;
		}

		// Print command line help to the standard output stream, if required
		if(parser.should_print_help())
			{ parser.print_help(std::cout);	
			return 0;
		}
		
		//get iput and output file name
		string fileIN = parser.getInFile();
		string fileOUT = parser.getOutFile();
		std::ifstream fin(fileIN.c_str());
		std::ofstream fout(fileOUT.c_str());
			
		//check for encoding
		if(parser.isEncode())
		{
			cout << "found encoding\n";
			//check for the cipher specified
			if(parser.isXOR())
			{
				//get the key
				int32_t key_ = parser.getXORK();
				string key;
				ostringstream convert;
				convert << key_;
				key = convert.str();
				cout << "found you xor\n";
				
				//check for packing and grouping
				if(parser.toGroup())
				{
					//check for packing with grouping
					if(parser.toPack())
					{
						CryptoMachine<XOR, Pack, Group> c;
						c.encode(fin, fout, key);
						return 0;
					}
						
					//perform grouping only
					else
					{
						CryptoMachine<XOR, Empty, Group> c;
						c.encode(fin, fout, key);
						return 0;
					}
						
				}
				//check for packing only
				else if(parser.toPack())
				{
					CryptoMachine<XOR, Pack, Empty> c;
					c.encode(fin, fout, key);
					return 0;
				}
				
				//perform XOR cipher only
				CryptoMachine<XOR, Empty, Empty> c;
				c.encode(fin, fout, key);
				return 0;
			}	
			else if(parser.isVignere())
			{
				//get the key
				string key = parser.getVignereK();
				//check that the key entered is valid and convert it to a string
				int pos;
				for(pos = 0; pos < key.length(); pos ++)
				{
					if(!isalpha(key.at(pos)))
					{
						cout << "\nInvalid key. Key has to have alphabets only for Vignere Cipher. Please try again.\n\n";
						return 0;
					}
				}
				transform(key.begin(), key.end(), key.begin(), [] (char c) { return toupper(c); } );	
					
				//check for packing and grouping
				if(parser.toGroup())
				{
					//check for packing with grouping
					if(parser.toPack())
					{
						CryptoMachine<Vignere, Pack, Group> c;
						c.encode(fin, fout, key);
						return 0;
					}
						
					//perform grouping only
					else
					{
						CryptoMachine<Vignere, Empty, Group> c;
						c.encode(fin, fout, key);
						return 0;
					}
						
				}
				//check for packing only
				else if(parser.toPack())
				{
					CryptoMachine<Vignere, Pack, Empty> c;
					c.encode(fin, fout, key);
					return 0;
				}
					
				//perform Vignere cipher only
				CryptoMachine<Vignere, Empty, Empty> c; 
				c.encode(fin, fout, key);
				return 0;
			}
			

			
			//check for packing and grouping without a Cipher
			if(parser.toGroup())
			{
				//check for packing with grouping
				if(parser.toPack())
				{
					CryptoMachine<Empty, Pack, Group> c;
					c.encode(fin, fout, " ");
					return 0;
				}
						
				//perform grouping only
				else
				{
					CryptoMachine<Empty, Empty, Group> c;
					c.encode(fin, fout, " ");
					return 0;
				}
						
			}
			//check for packing only without a Cipher
			else if(parser.toPack())
			{
				CryptoMachine<Empty, Pack, Empty> c;
				c.encode(fin, fout, " ");
				return 0;
			}
		
		}
		
		else if (parser.isDecode())
		{
			//check for the cipher specified
			if(parser.isXOR())
			{
				//get the key
				int32_t key_ = parser.getXORK();
				string key;
				ostringstream convert;
				convert << key_;
				key = convert.str();
				
				//check for decoding with grouping
				if(parser.toGroup())
				{
					if(parser.toPack())
					{
						CryptoMachine<XOR, Pack, Group> c;
						c.decode(fin, fout, key);
						return 0;
					}
					else
					{
						CryptoMachine<XOR, Empty, Group> c;
						c.decode(fin, fout, key);
						return 0;
					}
				}
					
				//check for decoding with packing only
				if(parser.toPack())
				{
					CryptoMachine<XOR, Pack, Empty> c;
					c.decode(fin, fout, key);
					return 0;
				}
					
				//perform XOR cipher only
				CryptoMachine<XOR, Empty, Empty> c;
				c.decode(fin, fout, key);
				return 0;
			}	
			else if(parser.isVignere())
			{
				//get the key
				string key = parser.getVignereK();
				//check that the key entered is valid and convert it to a string
				int pos;
				for(pos = 0; pos < key.length(); pos ++)
				{
					if(!isalpha(key.at(pos)))
					{
						cout << "\nInvalid key. Key has to have alphabets only for Vignere Cipher. Please try again.\n\n";
						return 0;
					}
				}
				transform(key.begin(), key.end(), key.begin(), [] (char c) { return toupper(c); } );	
					
				
				//check for decoding with grouping
				if(parser.toGroup())
				{
					if(parser.toPack())
					{	
						CryptoMachine<Vignere, Pack, Group> c;
						c.decode(fin, fout, key);
						return 0;
					}
					else
					{
						CryptoMachine<Vignere, Empty, Group> c;
						c.decode(fin, fout, key);
						return 0;
					}
				}
				
				//check for decoding packing only
				if(parser.toPack())
				{
					CryptoMachine<Vignere, Pack, Empty> c;
					c.decode(fin, fout, key);
					return 0;
				}
					
				//perform Vignere cipher only
				CryptoMachine<Vignere, Empty, Empty> c;
				c.decode(fin, fout, key);
				return 0;
			}
			

			
			//check for decoding with grouping with no Cipher
			if(parser.toGroup())
			{
				if(parser.toPack())
				{	CryptoMachine<Empty, Pack, Group> c;
					c.decode(fin, fout, " ");
					return 0;
				}
				else
				{
					CryptoMachine<Empty, Empty, Group> c;
					c.decode(fin, fout, " ");
					return 0;
				}
			}	

			//check for decoding packing only with no Cipher
			if(parser.toPack())
			{
				CryptoMachine<Empty, Pack, Empty> c;
				c.decode(fin, fout, " ");
				return 0;
			}
			
			
		}
		cout << "\nCommand line arguments could not be processed. Please try again.\n\n";
			
	
    return 0;
}



