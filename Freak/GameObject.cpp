#include"GameObject.h"
#include"utils.h"
inline void GameObject::Draw() {

	if (live.sprite != NULL) live.sprite->Draw(*this);
}

bool GameObject::Update(float deltaTime) {
	if (!IsInUse()) return false;
	if (live.moveHandle != NULL) live.moveHandle->update(this);
	if (live.velocitySetter != NULL) live.velocitySetter->update(this);
	if (abs(live.xpos) > 1.3 || abs(live.ypos) > 1.3) {
		in_use = false;
		return true;
	};
	return false;
}

void GameObject::Init(std::string name, float xpos, float ypos, MoveHandle * moveHandle, VelocitySetter * velocitySetter, Sprite * sprite, BoxCollider* collider)
{
	next = NULL;
	live.name = name;
	live.collider = collider;
	live.moveHandle = moveHandle;
	live.velocitySetter = velocitySetter;
	live.sprite = sprite;
	live.xpos = xpos;
	live.ypos = ypos;
	in_use = true;
}

void GameObject::OnCollisionWith(GameObject & other)
{
	std::cout << "BOOM!" << std::endl;
}

bool GameObject::IsCollisionWith(GameObject & other)
{
	BoxCollider* this_collider = GetWorldCollider();
	BoxCollider* other_collider = other.GetWorldCollider();
	if (this_collider&&other_collider) {
		
		return this_collider->isCollisionWith(other_collider);
	}
	return false;
}

bool GameObject::IsInUse()
{
	return in_use;
}

BoxCollider* GameObject::GetWorldCollider()
{
	if (live.collider) {
		live.collider->update(this);
		return live.collider;
	}
	return NULL;
}

GameObject::GameObject() {
	in_use = false;
}

GameObjectPool::GameObjectPool()
{
	first_avaliable = &objs[0];
	for (int i = 0; i < POOL_SIZE-1; ++i) {
		objs[i].SetNext(&objs[i + 1]);
	}
}

void GameObjectPool::create(std::string name, MoveHandle * moveHandle, VelocitySetter * velocitySetter, Sprite * sprite, BoxCollider* collider)
{
	GameObject* next_first_avaliable = first_avaliable->GetNext();
	first_avaliable->Init(name, 0, 0, moveHandle, velocitySetter, sprite, collider);
	first_avaliable = next_first_avaliable;
}

void GameObjectPool::update(float deltaTime)
{
	for (auto& obj : objs) {
		if (obj.Update(deltaTime)) {
			obj.SetNext(first_avaliable);
			first_avaliable = &obj;
		}
	}
}

void GameObjectPool::Draw()
{
	for (auto& obj : objs) {
		if (obj.IsInUse()) {
			obj.Draw();
		}
	}
}

void GameObjectPool::DoCollisionTest()
{
	//对每个网格及周围九个网格做碰撞检测
	FreshObjMesh();
	for (int i = 0; i < MESH_HEIGHT; ++i) {
		for (int j = 0; j < MESH_WIDTH; ++j) {
			std::vector<GameObject*> test_objs;
			int dx[] = { 0, 1, 0, -1, 0 , 1, -1, -1, 1};
			int dy[] = { 0, 0, 1, 0, -1, 1, -1, 1, -1 };
			for (int dir = 0; dir < 9; ++dir) {
				int height = i + dy[dir];
				int width = j + dx[dir];
				if (height >= MESH_HEIGHT || height < 0 || width >= MESH_WIDTH || width < 0) {
					continue;
				}
				for (auto obj : obj_mesh[height][width]) {
					test_objs.push_back(obj);
				}
			}

			for (int ii = 0; ii < test_objs.size(); ++ii) {
				for (int jj = ii+1; jj < test_objs.size(); ++jj) {
					if (test_objs[ii]->IsCollisionWith(*(test_objs[jj]))) {
						test_objs[ii]->OnCollisionWith(*(test_objs[jj]));
						test_objs[jj]->OnCollisionWith(*(test_objs[ii]));
					}
				}
			}
		}
	}
}

void GameObjectPool::FreshObjMesh()
{
	for (int i = 0; i < MESH_HEIGHT; ++i) {
		for (int j = 0; j < MESH_WIDTH; ++j) {
			obj_mesh[i][j].clear();
		}
	}
	for (auto& obj : objs) {
		if (obj.IsInUse()) {
			int height = (obj.live.ypos + 1.f) / 2.f * MESH_HEIGHT;
			int width = (obj.live.xpos + 1.f) / 2.f * MESH_WIDTH;
			if (height >= MESH_HEIGHT)
				height = MESH_HEIGHT - 1;
			else if (height < 0)
				height = 0;
			if (width >= MESH_WIDTH)
				width = MESH_WIDTH - 1;
			else if (width < 0)
				width = 0;
			obj_mesh[height][width].push_back(&obj);
		}
	}
}
