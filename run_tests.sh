#!/bin/sh

[ -x seashell ] || make all

for file in tests/*.sh; do
    $file
done
