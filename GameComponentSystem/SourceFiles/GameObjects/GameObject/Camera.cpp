/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Camera.cpp] カメラのゲームオブジェクト
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：レンダリングコンポーネントに共通する処理の定義
=============================================================================*/

/*--- インクルードファイル ---*/
#include "../../StdAfx.h"
#include "../../GameManager.h"
#include "Camera.h"
#include "../Component/CameraComponent.h"


/*-----------------------------------------------------------------------------
/* コンストラクタ
-----------------------------------------------------------------------------*/
Camera::Camera(class GameManager* gameManager)
	: GameObject(gameManager)
{
	std::cout << "カメラのゲームオブジェクトの作成\n";

	camera_component_ = new CameraComponent(this, 100);

}

/*-----------------------------------------------------------------------------
/* デストラクタ
-----------------------------------------------------------------------------*/
Camera::~Camera(void)
{
}

void Camera::UpdateGameObject(float deltaTime)
{
	std::cout << "カメラのゲームオブジェクトが更新された\n";
}

/*=============================================================================
/*		End of File
=============================================================================*/