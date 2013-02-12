#=============================================================================
#
# file :        Makefile
#
# description : Makefile to generate a TANGO device server.
#
# project :     TangoAccessControl
#
# $Author$
#
# $Revision$
# $Date$
#
#=============================================================================
#                This file is generated by POGO
#        (Program Obviously used to Generate tango Object)
#=============================================================================
#
#
#=============================================================================
# MAKE_ENV is the path to find common environment to buil project
#
MAKE_ENV = /segfs/tango/cppserver/env

#=============================================================================
# PACKAGE_NAME is the name of the library/device/exe you want to build
#
PACKAGE_NAME = TangoAccessControl
MAJOR_VERS   = 2
MINOR_VERS   = 6
RELEASE      = Release_$(MAJOR_VERS).$(MINOR_VERS)


MYSQL_INC_DIR = /usr/include/mysql
MYSQL_LIB_DIR = /usr/lib64/mysql

# #=============================================================================
# # RELEASE_TYPE
# # - DEBUG     : debug symbols - no optimization
# # - OPTIMIZED : no debug symbols - optimization level set to O2
# #-----------------------------------------------------------------------------
RELEASE_TYPE = DEBUG

#=============================================================================
# OUTPUT_TYPE can be one of the following :
#   - 'STATIC_LIB' for a static library (.a)
#   - 'SHARED_LIB' for a dynamic library (.so)
#   - 'DEVICE' for a device server (will automatically include and link
#            with Tango dependencies)
#   - 'SIMPLE_EXE' for an executable with no dependency (for exemple the test tool
#                of a library with no Tango dependencies)
#
OUTPUT_TYPE = DEVICE

#=============================================================================
# OUTPUT_DIR  is the directory which contains the build result.
# if not set, the standard location is :
#	- $HOME/DeviceServers if OUTPUT_TYPE is DEVICE
#	- ../bin for others
#
OUTPUT_DIR = ./bin/$(BIN_DIR)

#=============================================================================
# Following are names, pathes and files of the inherited classes used by project
#
#------------ Inheritance from TangoAccessControl class ------------
ACCESSCONTROL_CLASS = AccessControl
ACCESSCONTROL_HOME  = /segfs/tango/templates/AbstractClasses/AccessControl


#=============================================================================
# INC_DIR_USER is the list of all include path needed by your sources
#   - for a device server, tango dependencies are automatically appended
#   - '-I ../include' and '-I .' are automatically appended in all cases
#
INC_DIR_USER= -I . \
              -I $(ACCESSCONTROL_HOME) \
			  -I $(MYSQL_INC_DIR)

#=============================================================================
# LIB_DIR_USER is the list of user library directories
#   - for a device server, tango libraries directories are automatically appended
#   - '-L ../lib' is automatically appended in all cases
#
LIB_DIR_USER=

#=============================================================================
# LFLAGS_USR is the list of user link flags
#   - for a device server, tango libraries directories are automatically appended
#   - '-ldl -lpthread' is automatically appended in all cases
#
# !!! ATTENTION !!!
# Be aware that the order matters. 
# For example if you must link with libA, and if libA depends itself on libB
# you must use '-lA -lB' in this order as link flags, otherwise you will get
# 'undefined reference' errors
#
LFLAGS_USR+= -L $(MYSQL_LIB_DIR)  -lmysqlclient_r


#=============================================================================
# CXXFLAGS_USR lists the compilation flags specific for your library/device/exe
# This is the place where to put your compile-time macros using '-Dmy_macro'
#
# -DACE_HAS_EXCEPTIONS -D__ACE_INLINE__ for ACE
#
#CXXFLAGS_USR+= -Wall


#=============================================================================
# TANGO_REQUIRED 
# - TRUE  : your project depends on TANGO
# - FALSE : your project does not depend on TANGO
#-----------------------------------------------------------------------------
# - NOTE : if PROJECT_TYPE is set to DEVICE, TANGO will be auto. added
#-----------------------------------------------------------------------------  
TANGO_REQUIRED = TRUE



#=============================================================================
#	include Standard TANGO compilation options
#
include $(MAKE_ENV)/tango.opt

#=============================================================================
#	POST_PROCESSING: action to be done after normal make.
#	e.g.:  change executable file name, .....
#POST_PROCESSING = \
#	mv bin/$(BIN_DIR)/$(PACKAGE_NAME) bin/$(BIN_DIR)/$(PACKAGE_NAME)_DS

#=============================================================================
# SVC_OBJS is the list of all objects needed to make the output
#
SVC_INCL =  $(PACKAGE_NAME).h $(PACKAGE_NAME)Class.h $(SVC_INHERITANCE_INCL)


SVC_OBJS =      \
        $(OBJDIR)/$(PACKAGE_NAME).o \
        $(OBJDIR)/$(PACKAGE_NAME)Class.o \
        $(OBJDIR)/$(PACKAGE_NAME)StateMachine.o \
        $(SVC_INHERITANCE_OBJ) \
        $(OBJDIR)/ClassFactory.o  \
        $(OBJDIR)/main.o \
        $(ADDITIONAL_OBJS) 

SVC_INHERITANCE_OBJ =  \
        $(SVC_ACCESSCONTROL_OBJ) \

#------------  Object files for GenericPS class  ------------
SVC_ACCESSCONTROL_OBJ = \
        $(OBJDIR)/AccessControl.o \
        $(OBJDIR)/AccessControlClass.o \
        $(OBJDIR)/AccessControlStateMachine.o \

#------------ Object files for additional files ------------
ADDITIONAL_OBJS = \
		$(OBJDIR)/DbUtils.o

#=============================================================================
#	include common targets
#
include $(MAKE_ENV)/common_target.opt


#=============================================================================
# Following are dependancies of the inherited classes used by project
#

#------------  Object files dependancies for AccessControl class  ------------
ACCESSCONTROL_INCLUDES = \
		$(ACCESSCONTROL_HOME)/AccessControl.h \
		$(ACCESSCONTROL_HOME)/AccessControlClass.h
$(OBJDIR)/AccessControl.o:  $(ACCESSCONTROL_HOME)/AccessControl.cpp $(ACCESSCONTROL_INCLUDES)
	$(CC) $(CXXFLAGS) -c $< -o $(OBJDIR)/AccessControl.o
$(OBJDIR)/AccessControlClass.o:  $(ACCESSCONTROL_HOME)/AccessControlClass.cpp $(ACCESSCONTROL_INCLUDES)
	$(CC) $(CXXFLAGS) -c $< -o $(OBJDIR)/AccessControlClass.o
$(OBJDIR)/AccessControlStateMachine.o:  $(ACCESSCONTROL_HOME)/AccessControlStateMachine.cpp $(ACCESSCONTROL_INCLUDES)
	$(CC) $(CXXFLAGS) -c $< -o $(OBJDIR)/AccessControlStateMachine.o
$(OBJDIR)/DbUtils.o:  DbUtils.cpp $(ACCESSCONTROL_INCLUDES)
	$(CC) $(CXXFLAGS) -c $< -o $(OBJDIR)/DbUtils.o

SVC_INHERITANCE_INCL =  $(ACCESSCONTROL_INCLUDES)

#=============================================================================
#
SVN_TCS  =  https://tango-cs.svn.sourceforge.net/svnroot/tango-cs
SVN_PATH =	$(SVN_TCS)/classes/cpp/TangoAccessControl
tag:
	@echo "Tagging  $(PACKAGE_NAME)  for $(RELEASE)"
	svn copy  $(SVN_PATH)/trunk \
	          $(SVN_PATH)/tags/$(PACKAGE_NAME)-$(RELEASE)
