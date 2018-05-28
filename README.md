# Acrolinx Windows C++ Sidebar Demo

Demo code for an integration of the Acrolinx Sidebar in a C++ application

## Prerequisites

Please contact Acrolinx SDK support (sdk-support@acrolinx.com) for initial consulting.
We like to schedule a kickoff meeting to answer any questions about your integration project.
After the meeting, we provide you with test server credentials and configuration settings you need to get started.

## Configuration of the Sample

The Acrolinx checks if a connecting integration is allowed to connect. To connect to a server, you must provide a valid integration signature by editing the code:

In the file:

* `Acrolinx.Demo.Sidebar.Cpp\Acrolinx.Demo.Sidebar.CppDlg.cpp`

Find following line and add the signature provided by Acrolinx.
```cpp
m_sidebar.SetClientSignature
```


## How to Start

Make sure that you have installed Microsoft Visual Studio with C++ support version 2010.

Register Acrolinx.Sidebar.SDK.dll found under Acrolinx.Demo.Sidebar.Cpp\modules by running [RegisterAcrolinx.bat](https://github.com/acrolinx/sidebar-demo-cpp/blob/master/modules/RegisterAcrolinx.bat "register dll").


![Screen Shot of C++ Sidebar Example](/doc/sample.png)

## How to Use the Sidebar in Your Integration

Open the solution file `Acrolinx.Demo.Sidebar.Cpp.sln` with Visual Studio.

After you register Acrolinx.Sidebar.SDK.dll, you can start using it in your project. In the Designer View of your dialog, insert Acrolinx Sidebar Control from ActiveX Control list.

![Choose Items](/doc/chooseitems.png)

You should be able to see Acrolinx Sidebar on your dialog.

Usually you dock the Acrolinx Sidebar to the right side of your dialog:

![Dialog](/doc/dialog1.png)

Set the integration signature, which you received from Acrolinx. (Add file link)


Somewhere in your initialization code, tell the Sidebar to start:

	m_sidebar.Start();

![Start Sidebar](/doc/startcode.png)

Run the application. If you see the Acrolinx Sidebar, then everything went well.

The next step is to implement the extraction and the events of the Sidebar:

![Events](/doc/events.png)

Have a look at the sample source code provided in the sample project.

## CORS
* You must have CORS enabled for Acrolinx (https://support.acrolinx.com/hc/en-us/articles/203851132-Enable-Cross-Origin-Resource-Sharing-CORS-on-your-Core-Server).

## License

Copyright 2018 Acrolinx GmbH

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

For more information visit: http://www.acrolinx.com
