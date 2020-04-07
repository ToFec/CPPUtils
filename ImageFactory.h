/*
 * ImageFactory.h
 *
 *  Created on: 18.05.2017
 *      Author: fechter
 */

#ifndef IMAGEFACTORY_H_
#define IMAGEFACTORY_H_

#include "Utils.h"
#include "ImageWrapper.h"
#include "Image.h"
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkNrrdImageIO.h>
#include <NRRD/nrrd_image.hxx>

#include <algorithm>

class ImageFactory
{
public:
	virtual ~ImageFactory();

    static ImageFactory* instance ()
    {
       static CGuard g;   // Speicherbereinigung
       if (!_instance)
          _instance = new ImageFactory ();
       return _instance;
    }

	ImageWrapper* createImage(std::string filename);

private:
	enum FileType
	{
		unknown, nrrd
	};

	std::map<std::string, std::string> nrrdtypes;
	std::set<ImageWrapper* > constructedObjects;

	template<typename TImageType>
	void readFile(std::string filename, typename TImageType::Pointer image,
			ImageFactory::FileType filetype);
	typename itk::ImageIOBase::Pointer getImageIOClass(std::string filename,
			ImageFactory::FileType filetype);
	FileType getFileTypeByFilename(std::string filename);

	ImageFactory(void);
	ImageFactory(const ImageFactory& imageFactoryToCopy){};
	ImageFactory & operator = (const ImageFactory &);

	static ImageFactory* _instance;

    class CGuard
    {
    public:
       ~CGuard()
       {
          if( NULL != ImageFactory::_instance )
          {
             delete ImageFactory::_instance;
             ImageFactory::_instance = NULL;
          }
       }
    };
};


template<typename TImageType>
inline void ImageFactory::readFile(std::string filename,
		typename TImageType::Pointer image, ImageFactory::FileType filetype)
{
	typedef itk::ImageFileReader<TImageType> ReaderType;
	typename ReaderType::Pointer reader = ReaderType::New();

	itk::ImageIOBase::Pointer imageIO = getImageIOClass(filename, filetype);
	imageIO->ReadImageInformation();
	reader->SetImageIO(imageIO);
	reader->SetFileName(filename);
	reader->Update();

	image->Graft(reader->GetOutput());
}

#endif /* IMAGEFACTORY_H_ */
