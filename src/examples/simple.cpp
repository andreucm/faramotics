
//faramotics includes
#include "../sceneRender.h"

//std
#include <iostream>


int main(int argc, char** argv)
{
    CsceneRender *view;
    Window *win;
    Eigen::Affine3d eye; //camera wrt the model
    std::string modelFileName;
    
    //init model and initial view point
    modelFileName = "/home/andreu/Desktop/Robotiq_F2_85_LD.stl";
    //eye_pose.setPose(200,100,100,M_PI,-0.6,0);
    eye = Eigen::AngleAxisd( M_PI, Eigen::Vector3d(0,0,1) );
    eye.translation() = Eigen::Vector3d(300,100,100);     
        
    //glut initialization
    faramotics::initGLUT(argc, argv);
    
    //allocate faramotics object
    win = new Window(1200, 700, true, "faramotics_window");
    view = new CsceneRender(1200,700,90*M_PI/180.,90*(700./1200.)*(M_PI/180.),10.,600.,"view");
    view->loadAssimpModel(modelFileName);
    view->printRenderParameters();
    view->setViewPoint(eye);
    view->render(); 
    
    //stop 1s
    usleep(3000000);
    
    //return
    delete win; 
    //delete view; 
    std::cout << "main(): " << __LINE__ << std::endl; 
    return 0;
}
