TEMPLATE = subdirs



SUBDIRS += \
        lib \
        app

CONFIG += ordered

# Add ZittelmenEngine as dependency
lib.file = "$${PWD}/External/ZittelmenEngine/ZittelmenEngine.pro"
app.file = "$${PWD}/Source/App.pri"

app.depends = lib
