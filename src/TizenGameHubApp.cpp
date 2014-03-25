#include <new>
#include "TizenGameHubApp.h"
#include "TizenGameHubFrame.h"
// heeyeon!!!

using namespace Tizen::App;
using namespace Tizen::System;

TizenGameHubApp::TizenGameHubApp(void)
{
}

TizenGameHubApp::~TizenGameHubApp(void)
{
}

UiApp*
TizenGameHubApp::CreateInstance(void)
{
	// Create the application instance through the constructor.
	return new (std::nothrow) TizenGameHubApp();
}

bool
TizenGameHubApp::OnAppInitializing(AppRegistry& appRegistry)
{
	// TODO: Initialize application-specific data.
	// The permanent data and context of the application can be obtained from the application registry (appRegistry).
	//
	// If this method is successful, return true; otherwise, return false and the application is terminated.

	// Uncomment the following statement to listen to the screen on and off events:
	// PowerManager::SetScreenEventListener(*this);

	// TODO: Add your application initialization code here.
	return true;
}

bool
TizenGameHubApp::OnAppInitialized(void)
{
	// Create the application frame.
	TizenGameHubFrame* pTizenGameHubFrame = new (std::nothrow) TizenGameHubFrame;
	TryReturn(pTizenGameHubFrame != null, false, "The memory is insufficient.");
	pTizenGameHubFrame->Construct();
	pTizenGameHubFrame->SetName(L"TizenGameHub");
	AddFrame(*pTizenGameHubFrame);

	return true;
}

bool
TizenGameHubApp::OnAppWillTerminate(void)
{
	// TODO: Deallocate or release resources in devices that have the END key.
	return true;
}

bool
TizenGameHubApp::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO: Deallocate all resources allocated by the application.
	// The permanent data and context of the application can be saved through the application registry (appRegistry).
	return true;
}

void
TizenGameHubApp::OnForeground(void)
{
	// TODO: Start or resume drawing when the application is moved to the foreground.
}

void
TizenGameHubApp::OnBackground(void)
{
	// TODO: Stop drawing when the application is moved to the background to save the CPU and battery consumption.
}

void
TizenGameHubApp::OnLowMemory(void)
{
	// TODO: Free unnecessary resources or close the application.
}

void
TizenGameHubApp::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO: Handle all battery level changes here.
	// Stop using multimedia features (such as camera and mp3 playback) if the battery level is CRITICAL.
}

void
TizenGameHubApp::OnScreenOn(void)
{
	// TODO: Retrieve the released resources or resume the operations that were paused or stopped in the OnScreenOff() event handler.
}

void
TizenGameHubApp::OnScreenOff(void)
{
	// TODO: Release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode 
	// to save the battery (unless you have a good reason to do otherwise).
	// Only perform quick operations in this event handler. Any lengthy operations can be risky; 
	// for example, invoking a long asynchronous method within this event handler can cause problems
	// because the device can enter the sleep mode before the callback is invoked.

}
