#!/bin/bash
from_folder=$1
to_folder=$2

cd $from_folder
for file in $(find -iname "*.xml")
do
  file_aux="$file";
  if [[ !($file_aux =~ .*DOUBLE.*) ]]
    then
      cp $file_aux $to_folder
  fi
done
