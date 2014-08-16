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
// CalendarWithUnicodeExtensions.xaml.h
// Declaration of the CalendarWithUnicodeExtensions class
//

#pragma once

#include "pch.h"
#include "Scenario4_CalendarWithUnicodeExtensions.g.h"
#include "MainPage.xaml.h"

using namespace Platform;
using namespace Windows::Globalization;

namespace SDKSample
{
    namespace CalendarSample
    {
        /// <summary>
        /// An empty page that can be used on its own or navigated to within a Frame.
        /// </summary>
        [Windows::Foundation::Metadata::WebHostHidden]
        public ref class CalendarWithUnicodeExtensions sealed
        {
        public:
            CalendarWithUnicodeExtensions();
    
        protected:
            virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
        private:
            MainPage^ rootPage;
            void Display_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
            String^ GetCalendarProperties(Calendar^ calendar);
        };
    }
}
