#pragma once
class colliders
{
public:
	enum shape : char // enum to make sure only one shape is used at a time
	{
		none = 0,
		circle,
		aabb,
		line
	};
	colliders() = delete;

	const shape getShape() const;

protected:
	shape m_shape = shape::none;//holds the shape of the specific collider

	colliders(shape a_shape); // constructor

private:


};

