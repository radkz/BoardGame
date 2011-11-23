#include "GameG.h"

void GameG::drawBoard()
{
	Ogre::SceneManager*  m_pSceneMgr=OgreFramework::getSingletonPtr()->m_pRoot->getSceneManager("GameSceneMgr");
	float widthKw = 30;
	float heightKw = 30;
	Ogre::ManualObject mo("Pole");
	 

	mo.begin("Examples/Rocky", Ogre::RenderOperation::OT_TRIANGLE_LIST);
		mo.position(0, 0, heightKw);
			mo.textureCoord(0, 0);
	 
			mo.position(widthKw, 0, heightKw);
			mo.textureCoord(1, 0);
	 
			mo.position(widthKw, 0, 0);
			mo.textureCoord(0, 1);
	 
			mo.position(0, 0, 0);
			mo.textureCoord(1, 1);
			
			mo.triangle(0, 1, 2);
			mo.triangle(0, 2, 3);
	
	mo.end();
	mo.convertToMesh("PoleKw");

	float width = 18;
	float height = 30;

	
	mo.clear();
	mo.begin("Examples/Rocky", Ogre::RenderOperation::OT_TRIANGLE_LIST);
		mo.position(0, 0, height);
			mo.textureCoord(0, 0);
	 
			mo.position(width, 0, height);
			mo.textureCoord(1, 0);
	 
			mo.position(width, 0, 0);
			mo.textureCoord(0, 1);
	 
			mo.position(0, 0, 0);
			mo.textureCoord(1, 1);
			
			mo.triangle(0, 1, 2);
			mo.triangle(0, 2, 3);
	
	mo.end();

	mo.convertToMesh("Pole");
	
	Ogre::Entity *pole = m_pSceneMgr->createEntity("pole0", "PoleKw");
	pole->setMaterialName("Examples/Chrome");
	Ogre::SceneNode *poleNode = m_pSceneMgr->getRootSceneNode()->createChildSceneNode("poleNode0");
	poleNode->attachObject(pole);
	poleNode->setPosition(Ogre::Vector3(4.5*width, 0,-4.5*width));
	poleNode->showBoundingBox(true);

	Ogre::Entity *pole2 = m_pSceneMgr->createEntity("pole10", "PoleKw");
	pole2->setMaterialName("Examples/OgreLogo");
	Ogre::SceneNode *poleNode2 = m_pSceneMgr->getRootSceneNode()->createChildSceneNode("poleNode10");
	poleNode2->attachObject(pole2);
	poleNode2->setPosition(Ogre::Vector3(-4.5*width-height, 0,-4.5*width));
	poleNode2->showBoundingBox(true);

	Ogre::Entity *pole3 = m_pSceneMgr->createEntity("pole20", "PoleKw");
	pole3->setMaterialName("Examples/OgreLogo");
	Ogre::SceneNode *poleNode3 = m_pSceneMgr->getRootSceneNode()->createChildSceneNode("poleNode20");
	poleNode3->attachObject(pole3);
	poleNode3->setPosition(Ogre::Vector3(-4.5*width-height, 0,4.5*width+height));
	poleNode3->showBoundingBox(true);

	Ogre::Entity *pole4 = m_pSceneMgr->createEntity("pole30", "PoleKw");
	pole4->setMaterialName("Examples/OgreLogo");
	Ogre::SceneNode *poleNode4 = m_pSceneMgr->getRootSceneNode()->createChildSceneNode("poleNode30");
	poleNode4->attachObject(pole4);
	poleNode4->setPosition(Ogre::Vector3(4.5*width , 0,4.5*width+height));
	poleNode4->showBoundingBox(true);

	for (int i=0; i<9; i++)
	{
		Ogre::Entity *pole = m_pSceneMgr->createEntity("pole"+Ogre::StringConverter::toString(i+1), "Pole");
		
		Ogre::SceneNode *poleNode = m_pSceneMgr->getRootSceneNode()->createChildSceneNode("poleNode"+Ogre::StringConverter::toString(i+1));
		poleNode->attachObject(pole);
		poleNode->setPosition(Ogre::Vector3(3.5*width-i*width, 0, -4.5*width));
		poleNode->showBoundingBox(true);
	}

		for (int i=0; i<9; i++)
	{
		Ogre::Entity *pole = m_pSceneMgr->createEntity("pole"+Ogre::StringConverter::toString(i+11), "Pole");
		
		Ogre::SceneNode *poleNode = m_pSceneMgr->getRootSceneNode()->createChildSceneNode("poleNode"+Ogre::StringConverter::toString(i+11));
		poleNode->attachObject(pole);
		poleNode->yaw(Ogre::Radian(Ogre::Math::PI/2.f));
		poleNode->setPosition(Ogre::Vector3(-4.5*width-height, 0, -1.8*width+i*width));
		poleNode->showBoundingBox(true);
	}

	for (int i=0; i<9; i++)
	{
		Ogre::Entity *pole = m_pSceneMgr->createEntity("pole"+Ogre::StringConverter::toString(i+21), "Pole");
		
		Ogre::SceneNode *poleNode = m_pSceneMgr->getRootSceneNode()->createChildSceneNode("poleNode"+Ogre::StringConverter::toString(i+21));
		poleNode->attachObject(pole);
		poleNode->yaw(Ogre::Radian(Ogre::Math::PI));
		poleNode->setPosition(Ogre::Vector3(-3.5*width+i*width, 0, 4.5*width+2*height));
		poleNode->showBoundingBox(true);
	}

	for (int i=0; i<9; i++)
	{
		Ogre::Entity *pole = m_pSceneMgr->createEntity("pole"+Ogre::StringConverter::toString(i+31), "Pole");
		
		Ogre::SceneNode *poleNode = m_pSceneMgr->getRootSceneNode()->createChildSceneNode("poleNode"+Ogre::StringConverter::toString(i+31));
		poleNode->attachObject(pole);
		poleNode->yaw(Ogre::Radian(-Ogre::Math::PI/2.f));
		poleNode->setPosition(Ogre::Vector3(4.5*width+height, 0, 5.2*width-i*width));
		poleNode->showBoundingBox(true);
	}

	
}