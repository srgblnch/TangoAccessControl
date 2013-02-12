/*----- PROTECTED REGION ID(TangoAccessControl::ClassFactory.cpp) ENABLED START -----*/
static const char *RcsId = "$Header$";
//+=============================================================================
//
// file :        ClassFactory.cpp
//
// description : C++ source for the class_factory method of the DServer
//               device class. This method is responsible to create
//               all class singletin for a device server. It is called
//               at device server startup
//
// project :     TANGO Device Server
//
//
// Copyright (C) :      2004,2005,2006,2007,2008,2009,2010,2011,2012
//						European Synchrotron Radiation Facility
//                      BP 220, Grenoble 38043
//                      FRANCE
//
// This file is part of Tango.
//
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
//
//
// $Author$
//
// Copyright (C) :      2004,2005,2006,2007,2008,2009,2010
//						European Synchrotron Radiation Facility
//                      BP 220, Grenoble 38043
//                      FRANCE
//
// This file is part of Tango.
//
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
//
// $Revision$
//
// $Log$
// Revision 1.2  2010/09/21 11:33:29  taurel
// - Added GPL info
//
// Revision 1.1.1.1  2006/09/15 11:55:42  pascal_verdier
// Initial Revision
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


#include <tango.h>
#include <TangoAccessControlClass.h>

/**
 *	Create TangoAccessControlClass singleton and store it in DServer object.
 */

void Tango::DServer::class_factory()
{

	add_class(TangoAccessControl_ns::TangoAccessControlClass::init("TangoAccessControl"));

}
/*----- PROTECTED REGION END -----*/	//	TangoAccessControl::ClassFactory.cpp
