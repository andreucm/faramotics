
#ifndef rangeImage_H
#define rangeImage_H

//include
#include "sceneRender.h"
#include <vector>

/**
* \brief Known devices id's
* 
* Known devices id's
*
*/
enum knownDepthCameraDevices {SR4000 = 1, KINECT, TOF_X};

/**
* \brief CrangeImage class 
* 
* This class implements a range image devices such as a TOF camera or a 3D range scanner.
* The function depthImage() computes the range image according to the device parameters and the 3D model.
* The required input parameters that describe a 3D range device are (some of that are class members and others are inherited from CsceneRender):
*	- numPointsH: number of range points of the image rows [#]
*	- numPointsV: number of range points of the image columns [#]
*	- hAperture (inherited from CsceneRender): horizontal aperture [rad]
*	- vAperture (inherited from CsceneRender): vertical aperture [rad]
*	- angularAccuracyH: horizontal angular accuracy of the rays [rad]
*	- angularAccuracyV: horizontal angular accuracy of the rays [rad]
*	- zNear (inherited from CsceneRender): minimum range [m]
*	- zFar (inherited from CsceneRender): maximum range [m]
*
*/
class CrangeImage : public CsceneRender
{
	protected:
		//sector parameters
		
		/**
		* \brief Horizontal number of points
		* 
		* number of range points of the image rows [#]
		*
		*/
		unsigned int numPointsH;
		
		/**
		* \brief Vertical number of points
		* 
		* number of range points of the image columns [#]
		*
		*/
		unsigned int numPointsV;
		
		/**
		* \brief Horizontal angular accuracy
		* 
		* Horizontal angular accuracy
		*
		*/
		float angularAccuracyH;
		
		/**
		* \brief Vertical angular accuracy
		* 
		* Vertical angular accuracy
		*
		*/
		float angularAccuracyV; 
				
		/**
		* \brief Precomputed horizontal indexes
		* 
		* Precomputed horizontal indexes for the renderized pixels of interest.
		*
		*/
		vector<int> kH;
		
		/**
		* \brief Precomputed vertical indexes
		* 
		* Precomputed vertical indexes for the renderized pixels of interest.
		*
		*/
		vector<int> kV;

		//vector<float> cosHi, cosVi; /**<precomputed values for the cos(alpha_i)*/
		
		/**
		* \brief Initialization
		* 
		* Initialization. Called only by constructors.
		* From the provided device parameters computes the derives parameters to set window size and projection.
		*
		*/
		void rangeImageInit(unsigned int numPH, unsigned int numPV, float apertH, float apertV, float angularAccH, float angularAccV, float rmin, float rmax);
		
	public:
		/**
		* \brief Constructor with parameters
		* 
		* Constructor with device parameters set:
		*	- numPH: number of range points of the image rows [#]
		*	- numPV: number of range points of the image columns [#]
		*	- apertH : horizontal aperture [rad]
		*	- apertV: vertical aperture [rad]
		*	- angularAccH: horizontal angular accuracy of the rays [rad]
		*	- angularAccV: horizontal angular accuracy of the rays [rad]
		*	- rmin: minimum range [m]
		*	- rmax: maximum range [m]		
		*
		*/				
		CrangeImage(unsigned int numPH, unsigned int numPV, float apertH, float apertV, float angularAccH, float angularAccV, float rmin, float rmax);

		/**
		* \brief Constructor with device id
		* 
		* Constructor with device id
		*
		*/		
		CrangeImage(unsigned int deviceId);

		/**
		* \brief Destructor
		* 
		* Destructor
		*
		*/		
		~CrangeImage();

		/**
		* \brief Computes a full 3D depth image.
		* 
		* Computes a full 3D depth image from position ss. Range results are output to scan vector.
		*
		*/		
		void depthImage(Cpose3d & ss, vector<float> & depthImg);
};
#endif
