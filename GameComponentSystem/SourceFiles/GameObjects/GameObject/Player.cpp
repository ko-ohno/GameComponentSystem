/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[Hoge.cpp] モジュール
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：
=============================================================================*/

/*--- インクルードファイル ---*/
#include "../../StdAfx.h"
#include "Player.h"
#include "../Component/RenderComponent/SpriteComponent.h"

/*-----------------------------------------------------------------------------
/* コンストラクタ
-----------------------------------------------------------------------------*/
Player::Player(GameManager* gameManager)
	:GameObject(gameManager)
{
	std::cout << "プレイヤーのゲームオブジェクトの作成\n";

	sprite_ = new SpriteComponent(this);
	sprite_->SetObjectName("プレイヤーオブジェクト");

}

/*-----------------------------------------------------------------------------
/* デストラクタ
-----------------------------------------------------------------------------*/
Player::~Player(void)
{
	std::cout << "プレイヤーのゲームオブジェクトの破棄\n";
}

void Player::UpdateGameObject(float deltaTime)
{
	std::cout << "プレイヤーのゲームオブジェクトが更新された\n";
}


/*=============================================================================
/*		End of File
=============================================================================*/