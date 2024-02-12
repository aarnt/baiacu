## This is Baiacu, a powerful OpenBSD pkg front end using Qt libs.

![Main window](https://raw.githubusercontent.com/aarnt/baiacu/main/baiacu-mainwindow.png)

**Baiacu** is a Qt based GUI front end to the OpenBSD package manager, derived from [Octopkg](http://tintaescura.com/projects/octopkg).
It consists of a lxqt-sudo clone called [baiacu-doas](https://github.com/aarnt/baiacu/tree/main/doas) used to gain root privileges and a package browser application used
to search, install, remove and update packages.
The project is compatible with [OpenBSD](https://www.openbsd.org/).
Baiacu is a [Tupi-Guarani](https://en.wikipedia.org/wiki/Tupi%E2%80%93Guarani_languages) word that means "the hot and poisonous thing, because of its gall".

### Follow the steps bellow to compile the latest source code (you'll need curl, git and qt5 packages):

```
$ git clone https://github.com/aarnt/baiacu
$ cd baiacu/doas
$ qmake-qt5
$ make
# make install
$ cd ..
$ qmake-qt5
$ make
# make install
```

### In order to run Baiacu:

```
$ baiacu
```

Remember: Baiacu needs doas or sudo tool to work.


Enjoy!
