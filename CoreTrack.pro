include($${PWD}/Source/App.pri)

TEMPLATE = subdirs
 
SUBDIRS = \
        lib
 
# Add ZittelmenEngine as dependency
lib.subdir  = External/ZittelmenEngine

