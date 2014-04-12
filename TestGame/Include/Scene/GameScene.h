#pragma once

#include <TestGame/Include/Scene/BaseScene.h>

class GameScene : public BaseScene
{
public:
	GameScene();
	virtual ~GameScene();

	int i;
	virtual void Initialize(SceneManagerInterface* p_sceneManagerInteface);
	void Update(double p_deltaTime, int p_mousePositionX, int p_mousePositionY, bool p_lMouseClicked);
	void Render();
};