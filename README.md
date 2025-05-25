# Qt QML and C++ File Explorer

![preview](./preview.png)

### About

Qt QML 6.5.3 and C++ 17 File Explorer, simple program.
Allows to navigate freely through filesystem (on Linux). 
Contains quick-access directories on the bar to the left.

### Note
Some features may lack in performance (looking at you, search bar).
Made as a learning project in preparation for Hachathon.

All icons are Ubuntu GNOME icons.

### Build and run

For building I am using **CMake**. 

In scripts folder in **config_cmake.sh** specify path to your 
Qt library in `cmake -B build -DCMAKE_PREFIX_PATH=<your/path/to/Qt/gcc_64>`, 
e.g. `cmake -B build -DCMAKE_PREFIX_PATH=/home/cashtan/Qt/6.5.3/gcc_64`.

After you've done that, to configure cmake just type in terminal: 

```
sh config_cmake.sh
```

To build and run: 
```
sh build.sh
```
### Alternative way to build/run
I used QtStudio
