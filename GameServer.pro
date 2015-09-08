TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


QMAKE_CXXFLAGS += -std=c++0x -USTRICT_ANSI

#QMAKE_CXXFLAGS += -g

SOURCES += main.cpp \
    memManage/diskdbmanager.cpp \
    memManage/idbmanager.cpp \
    memManage/memdbmanager.cpp \
    NetWork/netclient.cpp \
    NetWork/tcpconnection.cpp \
    NetWork/tcpserver.cpp \
    md5.cpp \
    rpc.cpp \
    server.cpp \
    Monster/monster.cpp \
    Game/getdefinevalue.cpp \
    GameAttack/gameattack.cpp \
    GameTask/gametask.cpp \
    PlayerLogin/playerlogin.cpp \
    TeamFriend/teamfriend.cpp \
    GameInterchange/gameinterchange.cpp \
    OperationGoods/operationgoods.cpp \
    OperationPostgres/operationpostgres.cpp




include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Game/cmdparse.hpp \
    Game/cmdtypes.h \
    Game/log.hpp \
    Game/packheadflag.h \
    Game/postgresqlstruct.h \
    Game/session.hpp \
#    Game/transfer.hpp \
    Game/userposition.hpp \
    memManage/diskdbmanager.h \
    memManage/idbmanager.h \
    memManage/memdbmanager.h \
    NetWork/netclient.h \
    NetWork/tcpconnection.h \
    NetWork/tcpserver.h \
    utils/stringbuilder.hpp \
    hf_types.h \
    md5.h \
    rpc.h \
    server.h \
    Monster/monster.h \
    Game/getdefinevalue.h \
    Game/levelexperience.h \
    GameAttack/gameattack.h \
    GameTask/gametask.h \
    PlayerLogin/playerlogin.h \
    TeamFriend/teamfriend.h \
    GameInterchange/gameinterchange.h \
    OperationGoods/operationgoods.h \
    OperationPostgres/operationpostgres.h




#INCLUDEPATH += /home/hf02/soft/boost_1_58_0
#INCLUDEPATH += /home/hf02/soft/threadpool-0_2_5-src/threadpool


#LIBS+= /home/hf02/soft/hiredis-master/libhiredis.a
#LIBS += /usr/lib64/libpq.so
#LIBS += /home/hf02/soft/boost_1_58_0/stage/lib/libboost_system.a
#LIBS += /home/hf02/soft/boost_1_58_0/stage/lib/libboost_thread.a
#LIBS += /home/hf02/soft/boost_1_58_0/stage/lib/libboost_log.a

#QMAKE_LFLAGS += -pthread

INCLUDEPATH += /usr/local/include/hiredis
INCLUDEPATH += /opt/PostgreSQL/9.2/include

INCLUDEPATH += /home/junrui/yangWork/boost_1_58_0
INCLUDEPATH += /home/junrui/yangWork/threadpool

LIBS += /opt/PostgreSQL/9.2/lib/libpq.so
LIBS+= /usr/local/include/hiredis/libhiredis.so
#LIBS += /opt/PostgreSQL/9.2/lib/libpq.so.5

LIBS += /home/junrui/yangWork/boost_1_58_0/stage/lib/libboost_log.a
LIBS += /home/junrui/yangWork/boost_1_58_0/stage/lib/libboost_system.a
LIBS += /home/junrui/yangWork/boost_1_58_0/stage/lib/libboost_thread.a

QMAKE_LFLAGS += -pthread
