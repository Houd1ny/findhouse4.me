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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Source/ApartmentsController.o \
	${OBJECTDIR}/Source/ApartmentsListRequestHandler.o \
	${OBJECTDIR}/Source/Appartment.o \
	${OBJECTDIR}/Source/FileRequestHandler.o \
	${OBJECTDIR}/Source/FileSystem.o \
	${OBJECTDIR}/Source/FindHouse4meServer.o \
	${OBJECTDIR}/Source/ReportHandlerFactory.o \
	${OBJECTDIR}/Source/SearchPageController.o \
	${OBJECTDIR}/Source/SearchPageRequestHandler.o \
	${OBJECTDIR}/Source/SqlLiteDb.o \
	${OBJECTDIR}/Source/main.o


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
LDLIBSOPTIONS=-L/home/yuriy/test/real_estate_parser/poco-dev/lib -Wl,-rpath,'/home/yuriy/test/real_estate_parser/poco-dev/lib' -lPocoCryptod -lPocoDataSQLited -lPocoDatad -lPocoFoundationd -lPocoJSONd -lPocoNetSSLd -lPocoNetd -lPocoUtild -lPocoXMLd -lPocoZipd

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/findhouse4meserver

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/findhouse4meserver: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/findhouse4meserver ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Source/ApartmentsController.o: Source/ApartmentsController.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/ApartmentsController.o Source/ApartmentsController.cpp

${OBJECTDIR}/Source/ApartmentsListRequestHandler.o: Source/ApartmentsListRequestHandler.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/ApartmentsListRequestHandler.o Source/ApartmentsListRequestHandler.cpp

${OBJECTDIR}/Source/Appartment.o: Source/Appartment.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/Appartment.o Source/Appartment.cpp

${OBJECTDIR}/Source/FileRequestHandler.o: Source/FileRequestHandler.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/FileRequestHandler.o Source/FileRequestHandler.cpp

${OBJECTDIR}/Source/FileSystem.o: Source/FileSystem.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/FileSystem.o Source/FileSystem.cpp

${OBJECTDIR}/Source/FindHouse4meServer.o: Source/FindHouse4meServer.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/FindHouse4meServer.o Source/FindHouse4meServer.cpp

${OBJECTDIR}/Source/ReportHandlerFactory.o: Source/ReportHandlerFactory.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/ReportHandlerFactory.o Source/ReportHandlerFactory.cpp

${OBJECTDIR}/Source/SearchPageController.o: Source/SearchPageController.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/SearchPageController.o Source/SearchPageController.cpp

${OBJECTDIR}/Source/SearchPageRequestHandler.o: Source/SearchPageRequestHandler.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/SearchPageRequestHandler.o Source/SearchPageRequestHandler.cpp

${OBJECTDIR}/Source/SqlLiteDb.o: Source/SqlLiteDb.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/SqlLiteDb.o Source/SqlLiteDb.cpp

${OBJECTDIR}/Source/main.o: Source/main.cpp
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/yuriy/test/real_estate_parser/poco-dev/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/main.o Source/main.cpp

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
