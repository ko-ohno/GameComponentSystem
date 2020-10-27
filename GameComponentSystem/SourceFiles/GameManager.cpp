/*=============================================================================
/*-----------------------------------------------------------------------------
/*	[GameManager.cpp] ゲームの状態やオブジェクトの管理モジュール
/*	Author：Kousuke,Ohno.
/*-----------------------------------------------------------------------------
/*	説明：ゲーム状態とオブジェクトの管理。追加と削除。入力、更新、描画など
=============================================================================*/

/*--- インクルードファイル ---*/
#include "StdAfx.h"
#include "GameManager.h"
#include "GameObjects/GameObject.h"


/*-----------------------------------------------------------------------------
/* コンストラクタ
-----------------------------------------------------------------------------*/
GameManager::GameManager(void)
	: updating_background_objects_(false)
	, updating_game_objects_(false)
	, updating_ui_objects_(false)
{
	std::cout << "ゲームマネージャの起動\n";
	this->InitAll();
}

/*-----------------------------------------------------------------------------
/* デストラクタ
-----------------------------------------------------------------------------*/
GameManager::~GameManager(void)
{
	this->UninitAll();
	std::cout << "ゲームマネージャの停止\n";
}

/*-----------------------------------------------------------------------------
/* 初期化処理
-----------------------------------------------------------------------------*/
void GameManager::InitAll(void)
{
	std::cout << "ゲームマネージャの初期化処理\n";

	//グラフィックスの立ち上げやセーブデータのロードなどを行う
	std::cout << "グラフィックスの立ち上げ\n";
	std::cout << "セーブデータのロード\n";
}

/*-----------------------------------------------------------------------------
/* 終了化処理
-----------------------------------------------------------------------------*/
void GameManager::UninitAll(void)
{
	std::cout << "ゲームマネージャの終了化処理\n";

	std::cout << "セーブデータのアンロード\n";
	std::cout << "グラフィックスの破棄\n";
}

/*-----------------------------------------------------------------------------
/* 入力処理
-----------------------------------------------------------------------------*/
void GameManager::InputAll(void)
{
	std::cout << "ゲームマネージャの入力処理\n";

	if (game_state_ == GameState::Gameplay)
	{
		//ゲームオブジェクトの入力処理
		for (auto game_object : game_objects_)
		{
			game_object->Input();
		}
	}
}

/*-----------------------------------------------------------------------------
/* 更新処理
-----------------------------------------------------------------------------*/
void GameManager::UpdateAll(float deltaTime)
{
	std::cout << "ゲームマネージャの更新処理\n";

	if (game_state_ == GameState::Gameplay)
	{
		//背景オブジェクトの更新
		this->UpdateBackgroundObjects(deltaTime);

		//ゲームオブジェクトの更新
		this->UpdateGameObjects(deltaTime);
		
		//UIオブジェクトの更新
		this->UpdateUIObjects(deltaTime);
	}
}

/*-----------------------------------------------------------------------------
/* 出力生成処理
-----------------------------------------------------------------------------*/
void GameManager::GenerateOutputAll(void)
{
	std::cout << "ゲームマネージャの出力化処理\n";
}

/*-----------------------------------------------------------------------------
/* 背景オブジェクトの追加処理
-----------------------------------------------------------------------------*/
void GameManager::AddBackgroundObjects(BackgroundObject* backgroundObject)
{
	//ゲームオブジェクトの更新中かで登録先を変更
	if (updating_background_objects_)
	{
		pending_background_objects_.emplace_back(backgroundObject);//待機コンテナ
	}
	else
	{
		background_objects_.emplace_back(backgroundObject);//稼働コンテナ
	}
}

/*-----------------------------------------------------------------------------
/* 背景オブジェクトの削除処理
-----------------------------------------------------------------------------*/
void GameManager::RemoveBackgroundObjects(BackgroundObject* backgroundObject)
{
	// 待機コンテナ
	// "backgroundObject"をコンテナの中から探し出して破棄する
	auto iter = std::find(pending_background_objects_.begin(), pending_background_objects_.end(), backgroundObject);
	if (iter != pending_background_objects_.end())
	{
		//一致する"backgroundObject"をコンテナの末尾へ移動させ、メモリ自体を破棄する
		std::iter_swap(iter, pending_background_objects_.end() - 1);
		pending_background_objects_.pop_back();
	}

	// 稼働コンテナ
	// "backgroundObject"をコンテナの中から探し出して破棄する
	iter = std::find(background_objects_.begin(), background_objects_.end(), backgroundObject);
	if (iter != background_objects_.end())
	{
		//一致する"backgroundObject"をコンテナの末尾へ移動させ、メモリ自体を破棄する
		std::iter_swap(iter, background_objects_.end() - 1);
		background_objects_.pop_back();
	}
}

/*-----------------------------------------------------------------------------
/* ゲームオブジェクトの追加処理
-----------------------------------------------------------------------------*/
void GameManager::AddGameObject(GameObject* gameObject)
{
	// ゲームオブジェクトの更新中かで登録先を変更
	if (updating_game_objects_)
	{
		pending_game_objects_.emplace_back(gameObject);//待機コンテナ
	}
	else
	{
		game_objects_.emplace_back(gameObject);//稼働コンテナ
	}
}

/*-----------------------------------------------------------------------------
/* ゲームオブジェクトの削除処理
-----------------------------------------------------------------------------*/
void GameManager::RemoveGameObject(GameObject* gameObject)
{
	// 待機コンテナ
	// "gameObject"をコンテナの中から探し出して破棄する
	auto iter = std::find(pending_game_objects_.begin(), pending_game_objects_.end(), gameObject);
	if (iter != pending_game_objects_.end())
	{
		//一致する"gameObject"をコンテナの末尾へ移動させ、メモリ自体を破棄する
		std::iter_swap(iter, pending_game_objects_.end() - 1);
		pending_game_objects_.pop_back();
	}

	// 稼働コンテナ
	// "gameObject"をコンテナの中から探し出して破棄する
	iter = std::find(game_objects_.begin(), game_objects_.end(), gameObject);
	if (iter != game_objects_.end())
	{
		//一致する"gameObject"をコンテナの末尾へ移動させ、メモリ自体を破棄する
		std::iter_swap(iter, game_objects_.end() - 1);
		game_objects_.pop_back();
	}
}

/*-----------------------------------------------------------------------------
/* UIオブジェクトの追加処理
-----------------------------------------------------------------------------*/
void GameManager::AddUIObjects(UIObject* uiObject)
{
	// UIオブジェクトの更新中かで登録先を変更
	if (updating_ui_objects_)
	{
		pending_ui_objects_.emplace_back(uiObject);//待機コンテナ
	}
	else
	{
		ui_objects_.emplace_back(uiObject);//稼働コンテナ
	}
}

/*-----------------------------------------------------------------------------
/* UIオブジェクトの削除処理
-----------------------------------------------------------------------------*/
void GameManager::RemoveUIObjects(UIObject* uiObject)
{
	// 待機コンテナ
	// "uiObject"をコンテナの中から探し出して破棄する
	auto iter = std::find(pending_ui_objects_.begin(), pending_ui_objects_.end(), uiObject);
	if (iter != pending_ui_objects_.end())
	{
		//一致する"uiObject"をコンテナの末尾へ移動させ、メモリ自体を破棄する
		std::iter_swap(iter, pending_ui_objects_.end() - 1);
		pending_ui_objects_.pop_back();
	}

	// 稼働コンテナ
	// "uiObject"をコンテナの中から探し出して破棄する
	iter = std::find(ui_objects_.begin(), ui_objects_.end(), uiObject);
	if (iter != ui_objects_.end())
	{
		//一致する"uiObject"をコンテナの末尾へ移動させ、メモリ自体を破棄する
		std::iter_swap(iter, ui_objects_.end() - 1);
		ui_objects_.pop_back();
	}
}

/*-----------------------------------------------------------------------------
/* 背景オブジェクトの総更新処理
-----------------------------------------------------------------------------*/
void GameManager::UpdateBackgroundObjects(float deltaTime)
{
	//すべてのゲームオブジェクトの更新
	updating_game_objects_ = true;
	for (auto game_object : game_objects_)
	{
		game_object->Update(deltaTime);
	}
	updating_game_objects_ = false;

	//待機リストのゲームオブジェクトの操作
	for (auto pending_game_object : pending_game_objects_)
	{
		pending_game_object->Update(deltaTime);
		game_objects_.emplace_back(pending_game_object);
	}
	pending_game_objects_.clear();

	//ゲームオブジェクトが破棄の状態かチェック
	std::vector<class GameObject*> dead_game_objects;
	for (auto game_object : game_objects_)
	{
		if (game_object->GetState() == GameObject::State::Dead)
		{
			dead_game_objects.emplace_back(game_object);
		}
	}

	//破棄予定のゲームオブジェクトのメモリを破棄
	for (auto dead_game_object : dead_game_objects)
	{
		delete dead_game_object;
	}
}

/*-----------------------------------------------------------------------------
/* ゲームオブジェクトの総更新処理
-----------------------------------------------------------------------------*/
void GameManager::UpdateGameObjects(float deltaTime)
{
	//すべてのゲームオブジェクトの更新
	updating_game_objects_ = true;
	for (auto game_object : game_objects_)
	{
		game_object->Update(deltaTime);
	}
	updating_game_objects_ = false;

	//待機リストのゲームオブジェクトの操作
	for (auto pending_game_object : pending_game_objects_)
	{
		pending_game_object->Update(deltaTime);
		game_objects_.emplace_back(pending_game_object);
	}
	pending_game_objects_.clear();

	//ゲームオブジェクトが破棄の状態かチェック
	std::vector<class GameObject*> dead_game_objects;
	for (auto game_object : game_objects_)
	{
		if (game_object->GetState() == GameObject::State::Dead)
		{
			dead_game_objects.emplace_back(game_object);
		}
	}

	//破棄予定のゲームオブジェクトのメモリを破棄
	for (auto dead_game_object : dead_game_objects)
	{
		delete dead_game_object;
	}
}

/*-----------------------------------------------------------------------------
/* UIオブジェクトの総更新処理
-----------------------------------------------------------------------------*/
void GameManager::UpdateUIObjects(float deltaTime)
{
	//すべてのゲームオブジェクトの更新
	updating_game_objects_ = true;
	for (auto game_object : game_objects_)
	{
		game_object->Update(deltaTime);
	}
	updating_game_objects_ = false;

	//待機リストのゲームオブジェクトの操作
	for (auto pending_game_object : pending_game_objects_)
	{
		pending_game_object->Update(deltaTime);
		game_objects_.emplace_back(pending_game_object);
	}
	pending_game_objects_.clear();

	//ゲームオブジェクトが破棄の状態かチェック
	std::vector<class GameObject*> dead_game_objects;
	for (auto game_object : game_objects_)
	{
		if (game_object->GetState() == GameObject::State::Dead)
		{
			dead_game_objects.emplace_back(game_object);
		}
	}

	//破棄予定のゲームオブジェクトのメモリを破棄
	for (auto dead_game_object : dead_game_objects)
	{
		delete dead_game_object;
	}
}

/*=============================================================================
/*		End of File
=============================================================================*/