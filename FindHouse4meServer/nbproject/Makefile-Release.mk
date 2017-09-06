#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/6bb45af9/ApartmentsController.o \
	${OBJECTDIR}/_ext/6bb45af9/ApartmentsListRequestHandler.o \
	${OBJECTDIR}/_ext/6bb45af9/Appartment.o \
	${OBJECTDIR}/_ext/6bb45af9/FindHouse4meServer.o \
	${OBJECTDIR}/_ext/6bb45af9/ReportHandlerFactory.o \
	${OBJECTDIR}/_ext/6bb45af9/SqlLiteDb.o \
	${OBJECTDIR}/_ext/6bb45af9/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/home/yuriy/test/real_estate_parser/poco-dev/lib -lPocoCrypto -lPocoData -lPocoDataSQLite -lPocoFoundation -lPocoJSON -lPocoNet -lPocoNetSSL -lPocoUtil -lPocoXML -lPocoZip

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/findhouse4meserver

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/findhouse4meserver: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/findhouse4meserver ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/6bb45af9/ApartmentsController.o: /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/ApartmentsController.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/6bb45af9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6bb45af9/ApartmentsController.o /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/ApartmentsController.cpp

${OBJECTDIR}/_ext/6bb45af9/ApartmentsListRequestHandler.o: /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/ApartmentsListRequestHandler.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/6bb45af9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6bb45af9/ApartmentsListRequestHandler.o /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/ApartmentsListRequestHandler.cpp

${OBJECTDIR}/_ext/6bb45af9/Appartment.o: /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/Appartment.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/6bb45af9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6bb45af9/Appartment.o /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/Appartment.cpp

${OBJECTDIR}/_ext/6bb45af9/FindHouse4meServer.o: /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/FindHouse4meServer.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/6bb45af9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6bb45af9/FindHouse4meServer.o /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/FindHouse4meServer.cpp

${OBJECTDIR}/_ext/6bb45af9/ReportHandlerFactory.o: /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/ReportHandlerFactory.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/6bb45af9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6bb45af9/ReportHandlerFactory.o /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/ReportHandlerFactory.cpp

${OBJECTDIR}/_ext/6bb45af9/SqlLiteDb.o: /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/SqlLiteDb.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/6bb45af9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6bb45af9/SqlLiteDb.o /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/SqlLiteDb.cpp

${OBJECTDIR}/_ext/6bb45af9/main.o: /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/main.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/6bb45af9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6bb45af9/main.o /home/yuriy/test/findhouse4.me/FindHouse4meServer/Source/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
