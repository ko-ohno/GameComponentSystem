/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[PlayerParamComponent.cpp] 自機パラメータのコンポーネント
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：自機パラメータに関する処理のクラス定義
=============================================================================*/

/*--- インクルードファイル ---*/
#include "../../../StdAfx.h"
#include "PlayerParamComponent.h"

/*-----------------------------------------------------------------------------
/* コンストラクタ
-----------------------------------------------------------------------------*/
PlayerParamComponent::PlayerParamComponent(GameObject* owner, int updateOrder)
	: ActorParamComponent(owner, updateOrder)
{
}

/*-----------------------------------------------------------------------------
/* デストラクタ
-----------------------------------------------------------------------------*/
PlayerParamComponent::~PlayerParamComponent(void)
{
}

/*-----------------------------------------------------------------------------
/* 初期化処理
-----------------------------------------------------------------------------*/
void PlayerParamComponent::Init(void)
{
}

/*-----------------------------------------------------------------------------
/* 終了化処理
-----------------------------------------------------------------------------*/
void PlayerParamComponent::Uninit(void)
{
}

/*-----------------------------------------------------------------------------
/* 入力処理
-----------------------------------------------------------------------------*/
void PlayerParamComponent::Input(void)
{
}

/*-----------------------------------------------------------------------------
/* 更新処理
-----------------------------------------------------------------------------*/
void PlayerParamComponent::Update(float deltaTime)
{
}

/*=============================================================================
/*		End of File
=============================================================================*/