#pragma once

#define NUM_MESHES 4
#define SHOULD_MOVE true

namespace Tmpl8
{

// application class
class PrettyApp : public TheApp
{
public:
	// game flow methods
	void Init();
	void AnimateScene();
	float3 Trace( Ray& ray, RayCounter* counter );
	void Tick( float deltaTime );
	void Shutdown() { /* implement if you want to do something on exit */ }
	// input handling
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { mousePos.x = x, mousePos.y = y; }
	void MouseWheel( float y ) { /* implement if you want to handle the mouse wheel */ }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }
	// data members
	int2 mousePos;
	BVHInstance bvhInstance[256];
	TLAS tlas;
	float3 p0, p1, p2; // virtual screen plane corners
	float3 camPos;
	float3* accumulator;
	RayCounter* counters[524288] = { nullptr };
	uint counterIdx = 0;
	Timer timer;
};

} // namespace Tmpl8