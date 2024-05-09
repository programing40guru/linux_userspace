#!/bin/bash
echo Today is `date`

echo -e "\nenter the path to directory"
read the_path

echo -e "\nyou path has following files anf folders: "
ls $the_path
