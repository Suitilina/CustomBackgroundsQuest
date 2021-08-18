#include "main.hpp"
#include "BackgroundsFlowCoordinator.hpp"
#include "BackgroundEnvViewController.hpp"
#include "BackgroundListViewController.hpp"
#include "BackgroundConfigViewController.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"

#include "HMUI/ViewController.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/FlowCoordinator.hpp"

using namespace CustomBackgrounds;
DEFINE_TYPE(CustomBackgrounds, BackgroundsFlowCoordinator);

void BackgroundsFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation) 
    {
        this->SetTitle(il2cpp_utils::createcsstr("Backgrounds"), (int)1);
        this->showBackButton = true;

        if (!this->bgListView) this->bgListView = QuestUI::BeatSaberUI::CreateViewController<BackgroundListViewController*>();
        if (!this->bgConfigView) this->bgConfigView = QuestUI::BeatSaberUI::CreateViewController<BackgroundConfigViewController*>();
        if (!this->bgEnvView) this->bgEnvView = QuestUI::BeatSaberUI::CreateViewController<BackgroundEnvViewController*>();
        BackgroundsFlowCoordinator::ProvideInitialViewControllers(bgListView, bgConfigView, bgEnvView, nullptr, nullptr);
    }
}

void BackgroundsFlowCoordinator::BackButtonWasPressed(HMUI::ViewController* topView)
{
    getConfig().Write();
    HMUI::FlowCoordinator* settingsFC = QuestUI::GetModSettingsFlowCoordinator();
    settingsFC->DismissFlowCoordinator(this, (int)0, nullptr, false);
}