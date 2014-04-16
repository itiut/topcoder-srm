#!/bin/sh
cd $(dirname $0)

apps_dir=$HOME/.local/share/applications
icons_dir=$HOME/.icons

if [ ! -d $apps_dir ]; then
    mkdir $apps_dir
fi
cp topcoder-arena.desktop $apps_dir

if [ ! -d $icons_dir ]; then
    mkdir $icons_dir
fi
cp topcoder-arena.xpm $icons_dir

if [ ! -d $HOME/local/share ]; then
    mkdir $HOME/local/share -p
fi
ln --interactive --symbolic $PWD $HOME/local/share

cp contestapplet.conf $HOME
