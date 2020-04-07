/*
 * ImageFactory.cpp
 *
 *  Created on: 18.05.2017
 *      Author: fechter
 */

#include "ImageFactory.h"

ImageFactory* ImageFactory::_instance = 0;

ImageFactory::ImageFactory()
{
		// Supports non-standard type name "char" for loading but always writes "int8".
		nrrdtypes["int8_t"]=nrrdtypes["int8"]=nrrdtypes["signed char"]=nrrdtypes["char"]="char";
		nrrdtypes["uchar"]=nrrdtypes["uint8_t"]=nrrdtypes["uint8"]=nrrdtypes["unsigned char"]= "unsigned char";
		nrrdtypes["int16_t"]=nrrdtypes["int16"]=nrrdtypes["signed short int"]=nrrdtypes["signed signed"]=nrrdtypes["short int"]=nrrdtypes["short"]="short";
		nrrdtypes["ushort"]=nrrdtypes["uint16_t"]=nrrdtypes["uint16"]=nrrdtypes["unsigned short int"]=nrrdtypes["unsigned short"]="unsigned short";
		nrrdtypes["int32_t"]=nrrdtypes["int32"]=nrrdtypes["signed int"]=nrrdtypes["int"]="int";
		nrrdtypes["uint32_t"]=nrrdtypes["uint32"]=nrrdtypes["uint"]=nrrdtypes["unsigned int"]="unsigned int";
		nrrdtypes["float"]="float";
		nrrdtypes["double"]="double";

}

ImageFactory::~ImageFactory()
{
	std::set<ImageWrapper*>::iterator it;
	for (it = constructedObjects.begin(); it != constructedObjects.end(); it++)
	{
		delete *it;
	}
}

typename itk::ImageIOBase::Pointer ImageFactory::getImageIOClass(
		std::string filename, ImageFactory::FileType filetype)
{
	if (filetype == FileType::nrrd)
	{
		itk::NrrdImageIO::Pointer io =  itk::NrrdImageIO::New();
		io->SetFileName(filename.c_str());
		return io.GetPointer();
	}
	else
	{
		itk::ImageIOBase::Pointer io;
		return io;
	}
}

ImageWrapper* ImageFactory::createImage(std::string filename)
{

	FileType filetype = getFileTypeByFilename(filename);
	unsigned short imgDimensions = 0;
	std::string typInfo = "";
	if (filetype == FileType::nrrd)
	{
		imgDimensions = (unsigned short)Utils::getInstance().stringToInt(NRRD::getDimension(filename));
		typInfo = NRRD::getDataType(filename);
	}
	ImageWrapper* imgWrp;
	switch (imgDimensions) {
		case 2:
			if (nrrdtypes[typInfo] == "short")
			{
				typedef itk::Image<short, 2> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo]  == "unsigned short")
			{
				typedef itk::Image<unsigned short, 2> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo]  == "int")
			{
				typedef itk::Image< int, 2> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo]  == "unsigned int")
			{
				typedef itk::Image<unsigned int, 2> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo] == "float")
			{
				typedef itk::Image< float, 2> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo] == "double")
			{
				typedef itk::Image< double, 2> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo] == "char")
			{
				typedef itk::Image< char, 2> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo] == "unsigned char")
			{
				typedef itk::Image< unsigned char, 2> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			break;
		case 3:
			if (nrrdtypes[typInfo] == "short")
			{
				typedef itk::Image<short, 3> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo]  == "unsigned short")
			{
				typedef itk::Image<unsigned short, 3> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo]  == "int")
			{
				typedef itk::Image< int, 3> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo]  == "unsigned int")
			{
				typedef itk::Image<unsigned int, 3> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo] == "float")
			{
				typedef itk::Image< float, 3> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo] == "double")
			{
				typedef itk::Image< double, 3> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo] == "char")
			{
				typedef itk::Image< char, 3> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			else if (nrrdtypes[typInfo] == "unsigned char")
			{
				typedef itk::Image< unsigned char, 3> ImageType;
				typename ImageType::Pointer itkImage = ImageType::New();
				readFile<ImageType>(filename, itkImage, filetype);
				imgWrp = new Image<ImageType>(itkImage);
			}
			break;
	}
	if (imgWrp)
	{
		imgWrp->setDimension(imgDimensions);
		imgWrp->setType(nrrdtypes[typInfo]);
		constructedObjects.insert(imgWrp);
	}
	return imgWrp;

}


ImageFactory::FileType ImageFactory::getFileTypeByFilename(std::string filename)
{
	std::string::size_type pointPos = filename.find_last_of('.');
	if (pointPos != filename.npos)
	{
		std::string fileEnding = filename.substr(pointPos+1);
		std::transform(fileEnding.begin(), fileEnding.end(), fileEnding.begin(), ::tolower);
		if (fileEnding == "nrrd")
		{
			return FileType::nrrd;
		}
	}
	return FileType::unknown;
}
