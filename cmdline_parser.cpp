/*
 * cmdline_parser.cpp
 *
 *  Created on: 22 Feb 2012
 *      Author: simon
 */

#include "cmdline_parser.h"
#include <cstdint>

//-------------------------------------------------------------------------//
// Constructor, initialise the variables_map object with default
// constructor, options_descriptor with the name "Options"
//-------------------------------------------------------------------------//
cmdline_parser::cmdline_parser(void) : vm(), od("Options")
{
	// Shorter alias for the boost::program_options namespace
	namespace po = boost::program_options;

	// Add two cmdline options
	// --help or -?
	// --input-file or -i
	od.add_options()
		("help,?", "produce help message")
		((ENCODING+",e").c_str(), "Encoding should be performed.")
		((DECODING+",d").c_str(), "Decoding should be performed.")
		((INPUTFILE+",i").c_str(), po::value<std::string>(),
		"input filename.")
		((OUTPUTFILE+",o").c_str(), po::value<std::string>(),
		"output filename.")
		((XOR+",x").c_str(), po::value<int32_t>(),
		"Encode/Decode with XOR cipher using specified key.")
		((VIGNERE+",v").c_str(), po::value<std::string>(),
		"Encode/Decode with Vingere cipher using specified key.")
		((GROUP+",g").c_str(), "Specify support for grouping into code blocks.")
		((PACKING+",p").c_str(), "Specify support for bit packing.")
		((MODE+",m").c_str(), "Specify mode.") 
		((INITIALISE+",I").c_str(), "Provide initialisation vector") ;
		

};

//-------------------------------------------------------------------------//
// Process the cmdline
//-------------------------------------------------------------------------//
bool cmdline_parser::process_cmdline(int argc, char * argv[])
{
	// Shorter alias for the boost::program_options namespace
	namespace po = boost::program_options;

	// Clear the variable map
	vm.clear();

	// Parse the cmdline arguments defined by argc and argv,
	// looking for the options defined in the od variable,
	// and store them in the vm variable.
	po::store(po::parse_command_line(argc, argv, od), vm);
	po::notify(vm);
	bool success = true;

	if(vm.count(INPUTFILE) == 0)
	{
		success = false;
		errors.push_back(
			INPUTFILE + " not specified.");
	}

	if(vm.count(OUTPUTFILE) == 0)
	{
			success = false;
			errors.push_back(
				OUTPUTFILE + " not specified.");
	}



	return success;
}

//-----------------------------------------------------------------------//
// Return the input PGM filename
//-------------------------------------------------------------------------//
std::string cmdline_parser::getInFile(void) const
{
	// Return whatever value is stored as a string
	return vm[INPUTFILE].as<std::string>();
}

// Get outputfile name
std::string cmdline_parser::getOutFile(void) const
{
	// Return whatever value is stored as a string
	return vm[OUTPUTFILE].as<std::string>();
}

//Check for encoding or decoding

bool cmdline_parser::isEncode(void)
{
	return vm.count(ENCODING) > 0;
}


bool cmdline_parser::isDecode(void)
{
	return vm.count(DECODING) > 0;
}


//Check the type of Cipher 
bool cmdline_parser::isXOR(void)
{
	return vm.count(XOR) > 0;
}

bool cmdline_parser::isVignere(void)
{
	return vm.count(VIGNERE) > 0;
}


//Get the key corresponding to the Cipher selected
int32_t cmdline_parser::getXORK(void) const
{
	return vm[XOR].as<int32_t>();
}

std::string cmdline_parser::getVignereK(void) const
{
	return vm[VIGNERE].as<std::string>();
}

//Check if user specified grouping
bool cmdline_parser::toGroup(void)
{
	return vm.count(GROUP) > 0;
}

//Check if the user specified packing
bool cmdline_parser::toPack(void)
{
	return vm.count(PACKING) > 0;
}


//-----------------------------------------------------------------------//
// Should we print cmdline help?
//-------------------------------------------------------------------------//
bool cmdline_parser::should_print_help(void) const
{
	// Are there instances of the help option stored in the variable map
	return vm.count("help") > 0;
}

//-------------------------------------------------------------------------//
// Print out the options_descriptor to the supplied output stream
//-------------------------------------------------------------------------//
void cmdline_parser::print_help(std::ostream & out) const
{
	out << od;
}

//-------------------------------------------------------------------------//
// Print out the options_descriptor to the supplied output stream
//-------------------------------------------------------------------------//
void cmdline_parser::print_errors(std::ostream & out) const
{
	std::cerr << "Error processing command line arguments:" << std::endl;
	std::copy(errors.begin(), errors.end(),
		std::ostream_iterator<std::string>(out, "\n"));
}

// Definition of static strings in the class
const std::string cmdline_parser::MODE = "mode";
const std::string cmdline_parser::INITIALISE = "initialize-vector";
const std::string cmdline_parser::INPUTFILE = "input-file";
const std::string cmdline_parser::OUTPUTFILE = "output-file";
const std::string cmdline_parser::ENCODING = "encoding";
const std::string cmdline_parser::DECODING = "decoding";
const std::string cmdline_parser::XOR = "xor-cipher";
const std::string cmdline_parser::VIGNERE = "vignere-cipher";
const std::string cmdline_parser::GROUP = "group";
const std::string cmdline_parser::PACKING = "pack";

