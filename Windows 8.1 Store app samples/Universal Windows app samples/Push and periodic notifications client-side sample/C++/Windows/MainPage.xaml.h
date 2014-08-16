// Copyright (c) Microsoft. All rights reserved.

#pragma once

#include "MainPage.g.h"
#include "SampleConfiguration.h"

namespace SDKSample
{
	public enum class NotifyType
	{
		StatusMessage,
		ErrorMessage
	};

    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public ref class MainPage sealed
    {
	public:
		MainPage();

		property PushNotificationsHelper::Notifier^ Notifier {
			PushNotificationsHelper::Notifier^ get()
			{
				return notifier;
			}

			void set(PushNotificationsHelper::Notifier^ newNotifier)
			{
				notifier = newNotifier;
			}
		}

		property Windows::Networking::PushNotifications::PushNotificationChannel^ Channel {
			Windows::Networking::PushNotifications::PushNotificationChannel^ get()
			{
				return channel;
			}

			void set(Windows::Networking::PushNotifications::PushNotificationChannel^ newChannel)
			{
				channel = newChannel;
			}
		}

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
		
	private:
		void ScenarioControl_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
		void Footer_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);		
		PushNotificationsHelper::Notifier^ notifier;
		Windows::Networking::PushNotifications::PushNotificationChannel^ channel;

	internal:
		static MainPage^ Current;
		void NotifyUser(Platform::String^ strMessage, NotifyType type);

    };
}
