# Acrolinx Windows C++ Sidebar Demo

This is a showcase for integrating the [Acrolinx](https://www.acrolinx.com/) Sidebar into a Windows C++ application.

See: [Getting Started with Custom Integrations](https://docs.acrolinx.com/customintegrations)

## Live Demo

[Acrolinx Sidebar Web Live Demo](https://acrolinx.github.io/acrolinx-sidebar-demo/samples/index.html)

## The Acrolinx Sidebar

The Acrolinx Sidebar is designed to show up beside the window where you edit your content.
You use it for checking, reviewing, and correcting your content.
To get an impression what the Sidebar looks like in existing integrations, have a look at
[Get Started With the Sidebar](https://docs.acrolinx.com/coreplatform/latest/en/the-sidebar/get-started-with-the-sidebar).

## Prerequisites

Please contact [Acrolinx SDK support](https://github.com/acrolinx/acrolinx-coding-guidance/blob/master/topics/sdk-support.md)
for consulting and getting your integration certified.
This sample works with a test license on an internal Acrolinx URL.
This license is only meant for demonstration and developing purposes.
Once you finished your integration, you'll have to get a license for your integration from Acrolinx.
  
Acrolinx offers different other SDKs, and examples for developing integrations.

Before you start developing your own integration, you might benefit from looking into:

* [Getting Started with Custom Integrations](https://docs.acrolinx.com/customintegrations),
* the [Guidance for the Development of Acrolinx Integrations](https://github.com/acrolinx/acrolinx-coding-guidance),
* the [Acrolinx SDKs](https://github.com/acrolinx?q=sdk), and
* the [Acrolinx Demo Projects](https://github.com/acrolinx?q=demo).

## Getting Started

### Run Locally

1. Make sure that you have installed Microsoft Visual Studio 2017 with C++ support (MSVC anf MFC)
2. Open [`Acrolinx.Demo.Sidebar.Cpp.sln`](Acrolinx.Demo.Sidebar.Cpp.sln) in Visual Studio.
3. Build and run the solution (F5).

![Screenshot of C++ Sidebar Example](/doc/sample.png)

### Using the SDK

1. Open the solution file `Acrolinx.Demo.Sidebar.Cpp.sln` with Visual Studio.
2. Add C++ SDK as dependency from [Nuget](https://www.nuget.org/packages/Acrolinx.Sidebar.SDK.CPP/)
3. Register the Acrolinx.Sidebar.SDK.dll from `packages\Acrolinx.Sidebar.SDK.CPP.<version>\lib\<architecture>`
4. Use `/scripts/RegisterAcrolinx.bat` or `regsvr32 Acrolinx.Sidebar.SDK.dll` ro register the Dll.
5. After you register Acrolinx.Sidebar.SDK.dll, you can start using it in your project.
   In the Designer View of your dialog, insert Acrolinx Sidebar Control from ActiveX Control list.
   ![Choose Items](/doc/chooseitems.png)
6. You should be able to see Acrolinx Sidebar on your dialog.
7. Usually you dock the Acrolinx Sidebar to the right side of your dialog:
   ![Dialog](/doc/dialog1.png)
8. Set the test signature: `SW50ZWdyYXRpb25EZXZlbG9wbWVudERlbW9Pbmx5`.
9. Somewhere in your initialization code, tell the Sidebar to start:

    ```cpp
    m_sidebar.Start();
    ```

    ![Start Sidebar](/doc/startcode.png)
10. Run the application. If you see the Acrolinx Sidebar, then everything went well.
11. The next step is to implement the extraction and the events of the Sidebar.
   ![Events](/doc/events.png)
12. Have a look at the sample source code provided in the sample project.

## SDK Features

1. Provides lookup functionality.
2. **Start page**: Provides interactive way to sign in to Acrolinx with built-in error handling.
3. Provides logging using [Plog v1.1.4](https://github.com/SergiusTheBest/plog).
4. **Acrolinx Storage**: Applications using the Internet Explorer web browser control may be denied to access LocalStorage.
   The SDK uses its own storage mechanism using the Windows registry.
   + **Registry path**: `HKCU\Software\Acrolinx\Plugins\Storage\AcrolinxStorage\[KEY]`
   + **Fallback path**: `HKLM\Software\Acrolinx\Plugins\Storage\AcrolinxStorage\[KEY]`
5. **Acrolinx Adapter**: Provides reusable functionality for all integrations.

## References

* This DEMO is built on the [Sidebar SDK C++](https://github.com/acrolinx/sidebar-sdk-cpp).
* The Sidebar SDKs are based on the [Acrolinx Sidebar Interface](https://acrolinx.github.io/sidebar-interface/).

## License

Copyright 2018-present Acrolinx GmbH

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at:

[http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0)

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

For more information visit: [https://www.acrolinx.com](https://www.acrolinx.com)
