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
void TutorialApplication::createCamera()
{
  mCamera = mSceneMgr->createCamera("PlayerCam");
 
  mCamera->setPosition(Ogre::Vector3(0, 300, 500));
  mCamera->lookAt(Ogre::Vector3(0, 0, 0));
  mCamera->setNearClipDistance(5);
 
  mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}
 
void TutorialApplication::createViewports()
{
  Ogre::Viewport* vp = mWindow->addViewport(mCamera);
 
  vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
 
  mCamera->setAspectRatio(
    Ogre::Real(vp->getActualWidth()) /
    Ogre::Real(vp->getActualHeight()));
 
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    // Create your scene here :)
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0,0,0));
	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

	Ogre::Entity* ninjaEntity=mSceneMgr->createEntity("NINJA","ninja.mesh");
	ninjaEntity->setCastShadows(true);

	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ninjaEntity);

	Ogre::Plane plane(Ogre::Vector3::UNIT_Y,0);

	Ogre::MeshManager::getSingleton().createPlane(
		"Ground",
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		plane,
		1500,1500,20,20,
		true,
		1,5,5,
		Ogre::Vector3::UNIT_Z);

	Ogre::Entity* groundEntity=mSceneMgr->createEntity("GroundEntity","Ground");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	groundEntity->setMaterialName("Examples/Rockwall");
	groundEntity->setCastShadows(false);

	Ogre::Light* spotlight=mSceneMgr->createLight("SoptLight");
	spotlight->setDiffuseColour(0,0,1.0);
	spotlight->setSpecularColour(0,0,1.0);
	spotlight->setType(Ogre::Light::LT_SPOTLIGHT);

	spotlight->setDirection(-1, -1, 0);
	spotlight->setPosition(Ogre::Vector3(200, 200, 0));
	spotlight->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));


	Ogre::Light* directionalLight=mSceneMgr->createLight("DirectionalLight");
	directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);

	directionalLight->setDiffuseColour(Ogre::ColourValue(0.4f,0,0));
	directionalLight->setSpecularColour(Ogre::ColourValue(0.4f,0,0));

	directionalLight->setDirection(Ogre::Vector3(0,-1,1));


	Ogre::Light* pointLight=mSceneMgr->createLight("PointLight");
	pointLight->setType(Ogre::Light::LT_POINT);
	pointLight->setDiffuseColour(0.3f,0.3f,0.3f);
	pointLight->setDiffuseColour(0.3f,0.3f,0.3f);
	pointLight->setPosition(Ogre::Vector3(0,150,250));


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
