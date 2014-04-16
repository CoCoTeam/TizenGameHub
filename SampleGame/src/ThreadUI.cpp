#include "ThreadUI.h"
#include "Form1.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

ThreadUI::ThreadUI()
{
}

ThreadUI::~ThreadUI()
{
}

Application*
ThreadUI::CreateInstance(void)
{
	// Create the instance through the constructor.
	return new ThreadUI();
}

bool
ThreadUI::OnAppInitializing(AppRegistry& appRegistry)
{
	////////////////////////////////////////////////////////////////////////////////////
	//this codes is automatically inserted by Tizen Application Wizard.
	Tizen::Ui::Controls::Frame* pAppMainFrame = new Tizen::Ui::Controls::Frame();
	pAppMainFrame->Construct();
	pAppMainFrame->SetName(L"MainFrame");
	AddFrame(*pAppMainFrame);
	////////////////////////////////////////////////////////////////////////////////////
	// TODO:
	// Initialize UI resources and application specific data.
	// The application's permanent data and context can be obtained from the appRegistry.
	//
	// If this method is successful, return true; otherwise, return false.
	// If this method returns false, the application will be terminated.

	// Uncomment the following statement to listen to the screen on/off events.
	//PowerManager::SetScreenEventListener(*this);

	// Prepare Scene management.

	SceneRegister::RegisterAllScenes();
	SceneManager* pSceneManager = SceneManager::GetInstance();
	pSceneManager->GoForward(ForwardSceneTransition(SCENE_GAME_SECLECT));

	/*// Create a form
	Form1 *pForm1 = new Form1();
	pForm1->Initialize();

	// Add the form to the frame
	Frame *pFrame = GetAppFrame()->GetFrame();
	pFrame->AddControl(*pForm1);

	// Set the current form
	pFrame->SetCurrentForm(*pForm1);

	// Draw and Show the form
	pForm1->Draw();
	pForm1->Show();*/

	return true;
}

bool
ThreadUI::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO:
	// Deallocate resources allocated by this application for termination.
	// The application's permanent data and context can be saved via appRegistry.
	return true;
}

void
ThreadUI::OnForeground(void)
{
	// TODO:
	// Start or resume drawing when the application is moved to the foreground.
}

void
ThreadUI::OnBackground(void)
{
	// TODO:
	// Stop drawing when the application is moved to the background.
}

void
ThreadUI::OnLowMemory(void)
{
	// TODO:
	// Free unused resources or close the application.
}

void
ThreadUI::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO:
	// Handle any changes in battery level here.
	// Stop using multimedia features(camera, mp3 etc.) if the battery level is CRITICAL.
}

void
ThreadUI::OnScreenOn (void)
{
	// TODO:
	// Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void
ThreadUI::OnScreenOff (void)
{
	// TODO:
	//  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
