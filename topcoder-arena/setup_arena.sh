#!/bin/sh
cd $(dirname $0)

apps_dir=$HOME/.local/share/applications
icons_dir=$HOME/.icons

if [ ! -d $apps_dir ]; then
    mkdir -pv $apps_dir
fi
cp -iv topcoder-arena.desktop $apps_dir

if [ ! -d $icons_dir ]; then
    mkdir -pv $icons_dir
fi
cp -iv topcoder-arena.xpm $icons_dir

if [ ! -d $HOME/local/share ]; then
    mkdir -pv $HOME/local/share
fi
ln -isv $PWD $HOME/local/share

cp -iv contestapplet.conf $HOME
