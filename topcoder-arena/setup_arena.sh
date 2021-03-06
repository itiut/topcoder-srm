#!/bin/sh
cd $(dirname $0)

apps_dir=$HOME/.local/share/applications
icons_dir=$HOME/.icons
install_dir=$HOME/local/opt

if [ ! -d $apps_dir ]; then
    mkdir -pv $apps_dir
fi
cp -iv topcoder-arena.desktop $apps_dir

if [ ! -d $icons_dir ]; then
    mkdir -pv $icons_dir
fi
cp -iv topcoder-arena.xpm $icons_dir

if [ ! -d $install_dir ]; then
    mkdir -pv $install_dir
fi
ln -isv $PWD $install_dir

cp -iv contestapplet.conf $HOME
