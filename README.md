# empty project of the Shade 3D ver.15.1 Plugin SDK

Shade 3D ver.15.1 Plugin SDK : https://shade3d.jp/en/community/sdn/sdk.html

## Overview
This plugin is an empty plug-in project.
Shade 3D plugin menu ([Tools] - [Plugins]) When you select the "HelloShade" from, it displays HelloShade in the message window.


## Confirmation environment

It was confirmed at Shade 3D ver.15.2.

Development environment is the following.  
* Windows Visual Studio 2013 or 2015
* Xcode 6.4 on OS X 10.11.4

## Placement

    [ShadePluginSDK1510]  
         [boost_1_55_0]  
         [include]  
         [vsprops]  
         [xcconfig]  
         [plugin_projects]  
             [HelloShade]  <== This project  
                 [mac]     <== plugins/HelloShade.xcodeproj is Xcode project.  
                 [source]  <== plugin sources  
                 [win_vs2013] <== Visual Studio 2013 project  
                 [win_vs2015] <== Visual Studio 2015 project  
             
