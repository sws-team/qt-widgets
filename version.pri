GIT_ENABLED = $$system(cd $$_PRO_FILE_PWD_ && git version)
isEmpty( GIT_ENABLED ) {
error( "set up git" )
}

GIT_VERSION = $$system(cd $$_PRO_FILE_PWD_ && git describe)
QMAKE_SUBSTITUTES += $$PWD/version.h.in
DISTFILES += $$PWD/version.h.in

NORMAL_VERSION = $$replace(GIT_VERSION, "-[a-z|0-9]+", "" )
VERSION = $${NORMAL_VERSION}
DEFINES += APP_VERSION=\\\"$${NORMAL_VERSION}\\\"

FOLDER = $$basename(PWD)
INCLUDEPATH += $$OUT_PWD/$$FOLDER
message($$FOLDER)
