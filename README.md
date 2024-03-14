## This is Baiacu, a powerful OpenBSD pkg front end using Qt libs.

![Main window](https://raw.githubusercontent.com/aarnt/baiacu/main/baiacu-mainwindow.png)

**Baiacu** is a Qt based GUI front end to the OpenBSD package manager, derived from [OctoPkg](http://tintaescura.com/projects/octopkg).
It consists of a lxqt-sudo clone called [qt-sudo](https://github.com/aarnt/qt-sudo) used to gain root privileges and a package browser application used to search, install, remove and update packages.

Baiacu is also a [Tupi-Guarani](https://en.wikipedia.org/wiki/Tupi%E2%80%93Guarani_languages) word that means "the hot and poisonous thing, because of its gall".

### Follow the steps bellow to compile the latest source code (you'll need git and qt5 or qt6 packages):

```
$ git clone https://github.com/aarnt/baiacu
$ cd baiacu
$ qmake-qt5
$ make
# make install
```

### Add these lines in your /etc/doas.conf for qt-sudo work with OpenBSD:
```
# with password
#permit keepenv setenv { USER=root HOME=/root \
#XAUTHORITY=/home/<your_username_here/.Xauthority } <your_username_here

# without password
permit nopass keepenv setenv { USER=root HOME=/root \
XAUTHORITY=/home/<your_username_here>/.Xauthority } <your_username_here>
```

### In order to run Baiacu:

```
$ baiacu
```

Remember: Baiacu needs doas/sudo and curl to work.


Enjoy!
