#include($${PWD}/Source/App.pri)

TEMPLATE = subdirs
 
SUBDIRS += \
        lib \
        app
 
# Add ZittelmenEngine as dependency
lib.file = "$${PWD}/External/ZittelmenEngine/ZittelmenEngine.pro"
app.file  = "$${PWD}/Source/App.pri"

app.depends = lib
