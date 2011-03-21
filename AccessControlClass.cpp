/*----- PROTECTED REGION ID(AccessControlClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id$";
static const char *TagName    = "$Name$";
static const char *CvsPath    = "$Source$";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        AccessControlClass.cpp
//
// description : C++ source for the AccessControlClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the �name� once per process.
//
// project :     Access Control abstract class.
//
// Copyright (C) :      2004,2005,2006,2007,2008,2009,2010,2011
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
// $Revision$
// $Date$
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source$
// $Log$
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <AccessControlClass.h>

/*----- PROTECTED REGION END -----*/

//-------------------------------------------------------------------
/**
 *	Create AccessControlClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_AccessControl_class(const char *name) {
		return AccessControl_ns::AccessControlClass::init(name);
	}
}


namespace AccessControl_ns
{


//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
AccessControlClass *AccessControlClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		AccessControlClass::AccessControlClass(string &s)
 * description : 	constructor for the AccessControlClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
AccessControlClass::AccessControlClass(string &s):DeviceClass(s)
{
	cout2 << "Entering AccessControlClass constructor" << endl;
	set_default_property();
	get_class_property();
	write_class_property();

	/*----- PROTECTED REGION ID(AccessControl::Class::constructor) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AccessControl::Class::constructor

	cout2 << "Leaving AccessControlClass constructor" << endl;
}


//--------------------------------------------------------
/**
 * method : 		AccessControlClass::~AccessControlClass()
 * description : 	destructor for the AccessControlClass
 */
//--------------------------------------------------------
AccessControlClass::~AccessControlClass()
{
	/*----- PROTECTED REGION ID(AccessControl::Class::destructor) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AccessControl::Class::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		AccessControlClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
AccessControlClass *AccessControlClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new AccessControlClass(s);
		}
		catch (bad_alloc)
		{
			throw;
		}		
	}		
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		AccessControlClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
AccessControlClass *AccessControlClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}




//===================================================================
//	Command execution method calls
//===================================================================




//===================================================================
//	Properties management
//===================================================================

//--------------------------------------------------------
/**
 * method : 		AccessControlClass::get_class_property
 * description : 	Get the class property for specified name.
 *
 * @param	name  The property name
 */
//--------------------------------------------------------
Tango::DbDatum AccessControlClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : AccessControl::AccessControlClass::get_default_device_property()()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum AccessControlClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : AccessControl::AccessControlClass::get_default_class_property()()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum AccessControlClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : AccessControl::AccessControlClass::get_class_property()
 *	Description : //	Add your own code to initialize
 */
//--------------------------------------------------------
void AccessControlClass::get_class_property()
{
}


//--------------------------------------------------------
/**
 *	Method      : AccessControl::AccessControlClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *	              For each property, add to wizard property name and description.
 *	              If default value has been set, add it to wizard property and.
 *	              store it in a DbDatum.
 */
//--------------------------------------------------------
void AccessControlClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;
	
	//	Set Default Class Properties

	//	Set Default Device Properties
}


//--------------------------------------------------------
/**
 *	Method      : AccessControl::AccessControlClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void AccessControlClass::write_class_property()
{
}




//===================================================================
//	Factory methods
//===================================================================


//--------------------------------------------------------
/**
 * method : 		AccessControlClass::device_factory
 * description : 	Create the device object(s)
 *                  and store them in the device list
 *
 * @param	*devlist_ptr	The device name list
 */
//--------------------------------------------------------
void AccessControlClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{



	//	This class is not concrete and cannot implement devices

	
}


//--------------------------------------------------------
/**
 *	Method      : AccessControl::AccessControlClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *	              and store them in the attribute list
 */
//--------------------------------------------------------
void AccessControlClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(AccessControl::Class::attribute_factory_before) ENABLED START -----*/

	//	Add your own code

	/*----- PROTECTED REGION END -----*/	//	AccessControl::Class::attribute_factory_before



}


//--------------------------------------------------------
/**
 *	Method      : AccessControl::AccessControlClass::command_factory()
 *	Description : Create the command object(s)
 *	              and store them in the command list
 */
//--------------------------------------------------------
void AccessControlClass::command_factory()
{
	/*----- PROTECTED REGION ID(AccessControl::Class::command_factory_before) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AccessControl::Class::command_factory_before


	/*----- PROTECTED REGION ID(AccessControl::Class::command_factory_after) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AccessControl::Class::command_factory_after

}






	/*----- PROTECTED REGION ID(AccessControl::Class::Additional Methods) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AccessControl::Class::Additional Methods

} //	namespace
