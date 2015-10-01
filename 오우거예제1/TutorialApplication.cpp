/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/
-----------------------------------------------------------------------------
*/

#include "TutorialApplication.h"

//---------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
	mSceneMgr->setAmbientLight(Ogre::ColourValue(1, 1, 1));//deng guang

	Ogre::Entity* ent1 = mSceneMgr->createEntity("Robot","Robot.mesh");//kong xiang mu
	Ogre::Entity* ent2=mSceneMgr->createEntity("Robot2","robot.mesh");//di2ge kongxiangmu

	Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("RobotNode");//shi ti
	Ogre::SceneNode* node2=mSceneMgr->getRootSceneNode()->createChildSceneNode("RobotNode2",Ogre::Vector3(50,0,0));// biao ji zuo biao de shi ti 

	node2->attachObject(ent2); // bang ding di 2ge 
	ogreNode->attachObject(ent1);// bang ding

	Ogre::Light* light=mSceneMgr->createLight("MainLight"); //chuang jian deng guang
	light->setPosition(20,80,50);   // gai bian deng guang weizhi 
    // Create your scene here :)
}
//---------------------------------------------------------------------------

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
