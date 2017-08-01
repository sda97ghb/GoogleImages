# GoogleImages image selector

## Overview
This library gives you ability to use GoogleImages search in your Qt/Qml/C++ project. It allows to create a dialog with first 20 images that google returns for request and select one of them.<br/>
Example of dialog for request "shark":<br/>
![Example of dialog](https://raw.githubusercontent.com/sda97ghb/GoogleImages/master/doc/Dialog%20example%20screenshot.png "Logo Title Text 1")
## Requirement
This library requiers:
- Qt/Qml/C++
- [htmlcxx](http://htmlcxx.sourceforge.net/) for GoogleImages response page parsing
## Tutorial
1. Install Qt/Qml/Cpp.
2. Also install htmlcxx library. If you use Ubuntu you can just type:
	  ```bash
    sudo apt-get install libhtmlcxx-dev
    ```
3. Create new application with Qt Quick Controls 2.
4. Copy GoogleImages directory and GoogleImagesSearchDialog.qml to your project directory. Also add following code to .pro file:
    ```
    LIBS += -lhtmlcxx
    ```
5. Register new QML type in main.cpp
    ```c++
    #include "GoogleImages/Search.h"
    int main(int argc, char *argv[])
    {
        ...
        qmlRegisterType<google_images::Search>("GoogleImages", 1, 0, "GoogleImagesSearch");
        ...
    }

    ```
6. Add code as following to your qml file (main.qml or other).<br/>
   <b>Clipart</b> mode is enabled by default. In this mode " clipart" postfix will be added to the end of each search request. In many cases enabling this mode gives better results.<br/>
   <b>selected(selectedUrl)</b> signal is emmited when user selected image in a dialog. selectedUrl is url of selected image.
	```javascript
    GoogleImagesSearchDialog {
        id: googleImagesSearchDialog
        clipartMode: true
        onSelected: {
        	// handle selected image here
            // for example display it in an Image
            image.source = selectedUrl
        }
    }
    ```
7. Add some button and when it is clicked call 
    ```javascript
    googleImagesSearchDialog.search("some text to search")
    ```
