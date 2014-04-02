#ifndef _THREADUI_H_
#define _THREADUI_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>

/**
 * [ThreadUI] application must inherit from Application class
 * which provides basic features necessary to define an application.
 */
class ThreadUI :
	public Tizen::App::Application,
	public Tizen::System::IScreenEventListener
{
public:

	/**
	 * [ThreadUI] application must have a factory method that creates an instance of itself.
	 */
	static Tizen::App::Application* CreateInstance(void);


public:
	ThreadUI();
	~ThreadUI();


public:


	// Called when the application is initializing.
	bool OnAppInitializing(Tizen::App::AppRegistry& appRegistry);

	// Called when the application is terminating.
	bool OnAppTerminating(Tizen::App::AppRegistry& appRegistry, bool forcedTermination = false);


	// Called when the application's frame moves to the top of the screen.
	void OnForeground(void);


	// Called when this application's frame is moved from top of the screen to the background.
	void OnBackground(void);

	// Called when the system memory is not sufficient to run the application any further.
	void OnLowMemory(void);

	// Called when the battery level changes.
	void OnBatteryLevelChanged(Tizen::System::BatteryLevel batteryLevel);

	// Called when the screen turns on.
	void OnScreenOn (void);

	// Called when the screen turns off.
	void OnScreenOff (void);
};

#endif
