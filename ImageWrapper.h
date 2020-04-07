/*
 * ImageWrapper.h
 *
 *  Created on: 18.05.2017
 *      Author: fechter
 */

#ifndef IMAGEWRAPPER_H_
#define IMAGEWRAPPER_H_




class ImageWrapper
{
public:

	ImageWrapper()
	{
	};

	virtual ~ImageWrapper()
	{
	};

	virtual int getDimensions() = 0;
	virtual void setDimension(int dim) = 0;

	virtual std::string getType() = 0;
	virtual void setType(std::string type) = 0;

	virtual void saveImage(std::string filename) = 0;

};


#endif /* IMAGEWRAPPER_H_ */
