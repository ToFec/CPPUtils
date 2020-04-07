/*
 * Image.h
 *
 *  Created on: 18.05.2017
 *      Author: fechter
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "ImageWrapper.h"
#include <itkImageFileWriter.h>
#include <itkNrrdImageIO.h>

template<typename TImageType>
class Image : public ImageWrapper
{
public:

	Image(typename TImageType::Pointer itkImage)
	{
		this->itkImage = itkImage;
		dimension = 0;
		type = "";
	}

	virtual ~Image()
	{
		// TODO Auto-generated destructor stub
	}

	int getDimensions();
	void setDimension(int dim);
	std::string getType();
	void setType(std::string type);
	void saveImage(std::string filename);

	typename TImageType::Pointer getItkImage();

private:
	typename TImageType::Pointer itkImage;
	int dimension;
	std::string type;
};

template<typename TImageType>
inline int Image<TImageType>::getDimensions()
{
	return dimension;
}

template<typename TImageType>
inline void Image<TImageType>::setDimension(int dim)
{
	dimension = dim;
}

template<typename TImageType>
inline std::string Image<TImageType>::getType()
{
	return this->type;
}

template<typename TImageType>
inline void Image<TImageType>::setType(std::string type)
{
	this->type = type;
}

template<typename TImageType>
inline typename TImageType::Pointer Image<TImageType>::getItkImage()
{
		return itkImage;
}

template<typename TImageType>
inline void Image<TImageType>::saveImage(std::string filename)
{
	typedef itk::ImageFileWriter< TImageType >  ImgWriterType;
	typename ImgWriterType::Pointer imgwriter = ImgWriterType::New();
	imgwriter->SetFileName(filename.c_str() );
	imgwriter->SetInput(itkImage );

	itk::NrrdImageIO::Pointer io = itk::NrrdImageIO::New();
	io->SetFileType( itk::ImageIOBase::ASCII );
	imgwriter->SetImageIO(io);

	try
	{
		imgwriter->Update();
	}
	catch( itk::ExceptionObject & excp )
	{
		std::cerr << excp << std::endl;
	}
}

#endif /* IMAGE_H_ */
