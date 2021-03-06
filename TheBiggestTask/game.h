#pragma once
#include <string>

enum class Key
{
	UP = 'w',
	DOWN = 's',
	LEFT = 'a',
	RIGHT = 'd'
};

class GameObject
{
protected:
	int coordinateX;
	int coordinateY;

public:
	GameObject(int coordinateX, int coordinateY)
		: coordinateX(coordinateX), coordinateY(coordinateY)
	{}

	virtual ~GameObject()
	{
		std::cout << "GameObject deleted!" << std::endl;
	}
};

class NonControllable : public GameObject
{
public:
	NonControllable(int X, int Y)
		: GameObject(X, Y)
	{}

	virtual void Destroy() = 0;
};

class Controllable : public GameObject
{
public:
	Controllable(int X, int Y)
		: GameObject(X, Y)
	{}

	virtual void ControlByKey(Key key) = 0;
	virtual void ControlByMouse(float offsetx, float offsety) = 0;
};

class Cube : public NonControllable
{
private:
	float sideLength;

	~Cube()
	{
		std::cout << "Cube deleted!" << std::endl;
	}

public:
	Cube(const int X, const int Y, float sideLength)
		: NonControllable(X, Y), sideLength(sideLength)
	{}

	void Destroy() override
	{
		delete this;
	}
};

class Sphere : public NonControllable
{
private:
	float radius;

	~Sphere()
	{
		std::cout << "Sphere deleted!" << std::endl;
	}

public:
	void Destroy() override
	{
		delete this;
	}
};

class Camera : public Controllable
{
private:
	float verticalAngle;
	float horizontalAngle;

public:
	Camera(int X, int Y, float verticalAngle, float horizontalAngle)
		: Controllable(X, Y), verticalAngle(verticalAngle), horizontalAngle(horizontalAngle)
	{}

	~Camera()
	{
		std::cout << "Camera deleted!" << std::endl;
	}

	void ControlByKey(Key key) override
	{
		switch (key)
		{
		case Key::UP:
			++verticalAngle;
			break;
		case Key::DOWN:
			--verticalAngle;
			break;
		case Key::LEFT:
			--horizontalAngle;
			break;
		case Key::RIGHT:
			++horizontalAngle;
			break;
		default:
			break;
		}
	}

	void ControlByMouse(float offsetx, float offsety) override
	{
		verticalAngle += offsety;
		horizontalAngle += offsetx;
	}
};

class Player : public Controllable
{
private:
	std::string name;

public:
	Player(int X, int Y, std::string name)
		: Controllable(X, Y), name(std::move(name))
	{}

	~Player()
	{
		std::cout << "Player deleted!" << std::endl;
	}

	void ControlByKey(Key key) override
	{
		switch (key)
		{
		case Key::UP:
			++coordinateY;
			break;
		case Key::DOWN:
			--coordinateY;
			break;
		case Key::LEFT:
			--coordinateX;
			break;
		case Key::RIGHT:
			++coordinateX;
			break;
		default:
			break;
		}
	}

	void ControlByMouse(float offsetx, float offsety) override
	{
		coordinateX += static_cast<int>(offsetx);
		coordinateY += static_cast<int>(offsety);
	}
};
