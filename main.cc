#include <iostream>
#include <vector>

#include "lodepng.h"

unsigned width, height;
std::vector< unsigned char > imageDataOriginal;

// single channel
std::vector< unsigned char > imageDataRRR;
std::vector< unsigned char > imageDataGGG;
std::vector< unsigned char > imageDataBBB;

// two channels
std::vector< unsigned char > imageDataRGG;
std::vector< unsigned char > imageDataRBB;

// all three channels
std::vector< unsigned char > imageDataRBG;
std::vector< unsigned char > imageDataBRG;
std::vector< unsigned char > imageDataBGR;
std::vector< unsigned char > imageDataGRB;
std::vector< unsigned char > imageDataGBR;


void ChannelSwapAndWrite ( std::string filePrefix ) {
	int imageDataSize = width * height * 4;

	// allocate space
	imageDataRRR.resize( imageDataSize );
	imageDataGGG.resize( imageDataSize );
	imageDataBBB.resize( imageDataSize );

	imageDataRGG.resize( imageDataSize );
	imageDataRBB.resize( imageDataSize );

	imageDataRBG.resize( imageDataSize );
	imageDataBRG.resize( imageDataSize );
	imageDataBGR.resize( imageDataSize );
	imageDataGRB.resize( imageDataSize );
	imageDataGBR.resize( imageDataSize );

	#define RED   i+0
	#define GREEN i+1
	#define BLUE  i+2
	#define ALPHA i+3

	for ( int i = 0; i < width * height * 4; i+=4 ) {
		// shuffle data around
		imageDataRRR[ RED ]		= imageDataOriginal[ RED ];
		imageDataRRR[ GREEN ]	= imageDataOriginal[ RED ];
		imageDataRRR[ BLUE ]	= imageDataOriginal[ RED ];
		imageDataRRR[ ALPHA ]	= 255;

		imageDataGGG[ RED ]		= imageDataOriginal[ GREEN ];
		imageDataGGG[ GREEN ]	= imageDataOriginal[ GREEN ];
		imageDataGGG[ BLUE ]	= imageDataOriginal[ GREEN ];
		imageDataGGG[ ALPHA ]	= 255;

		imageDataBBB[ RED ]		= imageDataOriginal[ BLUE ];
		imageDataBBB[ GREEN ]	= imageDataOriginal[ BLUE ];
		imageDataBBB[ BLUE ]	= imageDataOriginal[ BLUE ];
		imageDataBBB[ ALPHA ]	= 255;

		imageDataRGG[ RED ]		= imageDataOriginal[ RED ];
		imageDataRGG[ GREEN ]	= imageDataOriginal[ GREEN ];
		imageDataRGG[ BLUE ]	= imageDataOriginal[ GREEN ];
		imageDataRGG[ ALPHA ]	= 255;

		imageDataRBB[ RED ]		= imageDataOriginal[ RED ];
		imageDataRBB[ GREEN ]	= imageDataOriginal[ BLUE ];
		imageDataRBB[ BLUE ]	= imageDataOriginal[ BLUE ];
		imageDataRBB[ ALPHA ]	= 255;

		imageDataRBG[ RED ]		= imageDataOriginal[ RED ];
		imageDataRBG[ GREEN ]	= imageDataOriginal[ BLUE ];
		imageDataRBG[ BLUE ]	= imageDataOriginal[ GREEN ];
		imageDataRBG[ ALPHA ]	= 255;

		imageDataBRG[ RED ]		= imageDataOriginal[ BLUE ];
		imageDataBRG[ GREEN ]	= imageDataOriginal[ RED ];
		imageDataBRG[ BLUE ]	= imageDataOriginal[ GREEN ];
		imageDataBRG[ ALPHA ]	= 255;

		imageDataBGR[ RED ]		= imageDataOriginal[ BLUE ];
		imageDataBGR[ GREEN ]	= imageDataOriginal[ GREEN ];
		imageDataBGR[ BLUE ]	= imageDataOriginal[ RED ];
		imageDataBGR[ ALPHA ]	= 255;

		imageDataGRB[ RED ]		= imageDataOriginal[ GREEN ];
		imageDataGRB[ GREEN ]	= imageDataOriginal[ RED ];
		imageDataGRB[ BLUE ]	= imageDataOriginal[ BLUE ];
		imageDataGRB[ ALPHA ]	= 255;

		imageDataGBR[ RED ]		= imageDataOriginal[ GREEN ];
		imageDataGBR[ GREEN ]	= imageDataOriginal[ BLUE ];
		imageDataGBR[ BLUE ]	= imageDataOriginal[ RED ];
		imageDataGBR[ ALPHA ]	= 255;
	}

	// write all the images
	unsigned error;
	std::string filename;

	filename = std::string( filePrefix + std::string( "RRR.png" ) );
	error = lodepng::encode( filename.c_str(), imageDataRRR, width, height );
	if ( error ) {
		std::cout << "encode error during save(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}

	filename = std::string( filePrefix + std::string( "GGG.png" ) );
	error = lodepng::encode( filename.c_str(), imageDataGGG, width, height );
	if ( error ) {
		std::cout << "encode error during save(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}

	filename = std::string( filePrefix + std::string( "BBB.png" ) );
	error = lodepng::encode( filename.c_str(), imageDataBBB, width, height );
	if ( error ) {
		std::cout << "encode error during save(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}

	filename = std::string( filePrefix + std::string( "RGG.png" ) );
	error = lodepng::encode( filename.c_str(), imageDataRGG, width, height );
	if ( error ) {
		std::cout << "encode error during save(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}

	filename = std::string( filePrefix + std::string( "RBB.png" ) );
	error = lodepng::encode( filename.c_str(), imageDataRBB, width, height );
	if ( error ) {
		std::cout << "encode error during save(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}

	filename = std::string( filePrefix + std::string( "RBG.png" ) );
	error = lodepng::encode( filename.c_str(), imageDataRBG, width, height );
	if ( error ) {
		std::cout << "encode error during save(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}

	filename = std::string( filePrefix + std::string( "BRG.png" ) );
	error = lodepng::encode( filename.c_str(), imageDataBRG, width, height );
	if ( error ) {
		std::cout << "encode error during save(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}

	filename = std::string( filePrefix + std::string( "BGR.png" ) );
	error = lodepng::encode( filename.c_str(), imageDataBGR, width, height );
	if ( error ) {
		std::cout << "encode error during save(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}

	filename = std::string( filePrefix + std::string( "GRB.png" ) );
	error = lodepng::encode( filename.c_str(), imageDataGRB, width, height );
	if ( error ) {
		std::cout << "encode error during save(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}

	filename = std::string( filePrefix + std::string( "GBR.png" ) );
	error = lodepng::encode( filename.c_str(), imageDataGBR, width, height );
	if ( error ) {
		std::cout << "encode error during save(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}
}

int main ( int argc, char const *argv[] ) {
	// filename from command line
	std::string filename = std::string( "in" ) + std::string( argv[ 1 ] ) + std::string( ".png" );

	// load the image
	unsigned error = lodepng::decode( imageDataOriginal, width, height, filename.c_str() );
	if ( error ) {
		std::cout << "decode error during load(\" " + filename + " \") " << error << ": " << lodepng_error_text( error ) << std::endl;
	}

	// produce each output
	ChannelSwapAndWrite( std::string( "out" ) + std::string( argv[ 1 ] ) );

	return 0;
}
