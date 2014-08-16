﻿//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

//
// Scenario3_Calibration.xaml.cpp
// Implementation of the Scenario3 class
//

#include "pch.h"
#include "Scenario3_Calibration.xaml.h"

using namespace SDKSample::CompassCPP;
using namespace SDKSample::Calibration;

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Devices::Sensors;
using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Platform;

Scenario3::Scenario3() : rootPage(MainPage::Current)
{
    InitializeComponent();
    calibrationBar = ref new CalibrationBar();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void Scenario3::OnNavigatedTo(NavigationEventArgs^ e)
{
}

/// <summary>
/// Invoked when this page is no longer displayed.
/// </summary>
/// <param name="e"></param>
void Scenario3::OnNavigatedFrom(NavigationEventArgs^ e)
{
    // If the navigation is external to the app do not clean up.
    // This can occur on Phone when suspending the app.
    if (e->NavigationMode == NavigationMode::Forward && e->Uri == nullptr)
    {
        return;
    }

    calibrationBar->Hide();
}

/// <summary>
/// This is the click handler for high accuracy. Acceptable accuracy met, so
/// hide the calibration bar.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
void Scenario3::OnHighAccuracy(Object^ sender, RoutedEventArgs^ e)
{
    calibrationBar->Hide();
}

/// <summary>
/// This is the click handler for approximate accuracy. Acceptable accuracy met, so
/// hide the calibration bar.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
void Scenario3::OnApproximateAccuracy(Object^ sender, RoutedEventArgs^ e)
{
    calibrationBar->Hide();
}

/// <summary>
/// This is the click handler for unreliable accuracy. Sensor does not meet accuracy
/// requirements. Request to show the calibration bar per the calibration guidance.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
void Scenario3::OnUnreliableAccuracy(Object^ sender, RoutedEventArgs^ e)
{
    calibrationBar->RequestCalibration(MagnetometerAccuracy::Unreliable);
}
