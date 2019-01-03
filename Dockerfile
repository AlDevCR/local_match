FROM ubuntu:18.04
LABEL maintainer = "pabgora94@gmail.com"

## Copy sqlodbc libraries to right places in container environment

# Install core dependencies

RUN apt-get update && \
    apt-get -y install -y \
        gcc g++ build-essential cmake bash make libxcb1-dev libicu-dev \
        libssl-dev linux-headers-generic curl git libxrender-dev \
        libpng-dev libjpeg-turbo8 libjpeg-turbo8-dev libicu-dev \
        libgles2-mesa libgles2-mesa-dev libfreetype6-dev libsqlite3-dev \
	      libogg-dev libvorbis-dev bzip2 gperf bison ruby flex vim python && \
    rm -rf /var/lib/apt/lists/*

# Install unixODBC

ENV unixODBC https://sourceforge.net/projects/unixodbc/files/unixODBC/2.3.7/unixODBC-2.3.7pre.tar.gz
ENV unixODBC_DIR /unixODBC-2.3.7pre

RUN curl -sSL $unixODBC| tar -xz \
    && cd $unixODBC_DIR \
    && bash ./configure --prefix=/usr/local/unixODBC \
    && make \
    && make install \
    && cd /

# Install ODBC driver and ODBC driver manager

RUN curl -sSL https://packages.microsoft.com/keys/microsoft.asc | apt-key add - \
    && curl -sSl https://packages.microsoft.com/config/ubuntu/18.04/prod.list > /etc/apt/sources.list.d/mssql-release.list \
    && apt-get update \
    && ACCEPT_EULA=Y apt-get -y install msodbcsql17 \
    && ACCEPT_EULA=Y apt-get -y install mssql-tools 
    # optional: for unixODBC development headers
    && apt-get install -y unixodbc-dev \
    && cd /

# Install clang-format

RUN apt-get -y install clang-format

# Installing dependencies
RUN apt-get -y install libqt5sql5-odbc \
    && apt-get install -y tdsodbc \
    && apt-get install -y unixodbc-dev unixodbc-bin unixodbc \
    && apt-get update \
    && cd /

# Choose Qt version

ENV QT_VERSION_MAJOR 5.12
ENV QT_VERSION 5.12.0

# Compile and install Qt Base

ENV QT_DIST /usr/local/Qt-"$QT_VERSION"
ENV QT_EVERYWHERE_SRC https://download.qt.io/official_releases/qt/"$QT_VERSION_MAJOR"/"$QT_VERSION"/single/qt-everywhere-src-"$QT_VERSION".tar.xz
ENV QT_EVERYWHERE_DIR /qt-everywhere-src-"$QT_VERSION"

RUN curl -sSL $QT_EVERYWHERE_SRC | tar xJ \
    && cd $QT_EVERYWHERE_DIR \
    && bash ./configure --help \
    && bash ./configure -opensource -confirm-license -static -no-accessibility -sql-odbc -sql-sqlite -sqlite \
       -no-harfbuzz -openssl-linked -qt-pcre -no-dbus -nomake tools \
       -no-xkbcommon-evdev -no-xcb-xlib -no-glib -qt-xcb -no-compile-examples -nomake examples \
       -no-gif -qt-doubleconversion -no-gtk \
    && make install

ENV PATH $QT_DIST/bin:$PATH


# Building ODBC plugin

RUN set -x && cd /qt-everywhere-src-5.12.0/qtbase/src/plugins/sqldrivers \
    && qmake -- ODBC_PREFIX=/usr/local/unixODBC \
    && make sub-odbc \
    && cd /

# Clean compilation files

CMD ["bash", "/build.sh"]
